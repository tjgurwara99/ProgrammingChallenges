import Control.Monad
import Data.Array.Unboxed
import Data.Array.ST

sieve :: Int -> UArray Int Bool
sieve bound = runSTUArray $ do
  isPrime <- newArray (2, bound) True
  forM_ (2:[3,5..bound]) $ \i -> do
    prime <- readArray isPrime i
    when prime $ forM_ [i*i,i*(i+1)..bound] $ \j -> writeArray isPrime j False
  return isPrime

primes :: Int -> [Int]
primes bound = [ p | (p,True) <- assocs $ sieve bound]

solve :: Int -> Int
solve n = go 0 ps (reverse ps) (length ps)
  where ps = primes (n `div` 2)
        go acc a@(x:xs) b@(y:ys) l
          | x > y     = acc
          | x*y >= n  = go acc a ys (l-1)
          | otherwise = go (acc+l) xs b (l-1)

main :: IO ()
main = print $ solve 100000000
