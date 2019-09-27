import Control.Monad
import Control.Monad.ST
import Data.Array
import Data.Array.ST
import Data.STRef

h :: Int -> Int
h n = runST $ do
  isPrime <- newArray (0,n) True :: ST s (STUArray s Int Bool)
  totient <- newArray (0,n) 0 :: ST s (STUArray s Int Int)

  forM_ [1..n] $ \i -> writeArray totient i i
  forM_ [2..n] $ \i -> do
    prime <- readArray isPrime i
    when prime $ do
      forM_ [i,i+i..n] $ \j -> do
        v <- readArray totient j
        writeArray totient j ((v`div`i)*(i-1))
        writeArray isPrime j False

  total <- newSTRef 0
  forM_ [1..n] $ \i -> do
    v <- readArray totient i
    modifySTRef' total (+(i-v))
  t <- readSTRef total
  return (t*6)

main :: IO ()
main = print $ h 100000000
