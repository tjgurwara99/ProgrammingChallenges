import Control.Monad
import Control.Monad.ST
import Data.Array.ST
import Data.Array.Unboxed
import Data.List
import Data.Int
import Data.Bits

bound :: Int64
bound = 10^12

mergeUnique :: Ord a => [a] -> [a] -> [a]
mergeUnique xs [] = xs
mergeUnique [] ys = ys
mergeUnique x@(a:as) y@(b:bs) = case compare a b of
  LT -> a : mergeUnique as y
  EQ -> a : mergeUnique as bs
  GT -> b : mergeUnique x bs

hammingNumbers :: [Int64]
hammingNumbers = 1 : merge (times 2) (times 3) (times 5)
  where times k = map (k*) hammingNumbers
        merge x y z = x `mergeUnique` y `mergeUnique` z

sieve :: Int -> UArray Int Bool
sieve bound = runSTUArray $ do
  let m = ceiling $ sqrt (fromIntegral bound)
  prime <- newArray (2,bound) True
  forM_ [2..m] $ \i -> do
    p <- readArray prime i
    when p $ do
      forM_ [i*i,i*i+i..bound] (\j -> writeArray prime j False)
  return prime

primes :: [Int64]
primes = [fromIntegral i | (i,True) <- assocs $ sieve m]
  where m = ceiling (sqrt (fromIntegral bound))

isPrime :: Int64 -> Bool
isPrime = go primes
  where go (p:ps) n = p*p > n || n `mod` p /= 0 && go ps n

getFeasible :: [Int64] -> [Int64]
getFeasible ys = go [] 1 ys
  where go acc num []     = num:acc
        go acc num (x:xs) =
          if bound `div` x >= num then go (go acc (x*num) xs) num xs
          else                         num:acc

mod32 :: Int64 -> Int64
mod32 = (.&. (2^32-1))

safeSum :: [Int64] -> Int64
safeSum = mod32 . sum . map mod32

getMultipleSum :: Int64 -> Int64
getMultipleSum y = y * (safeSum $ takeWhile (<=m) hammingNumbers)
  where m = bound `div` y

main :: IO ()
main = do
  let xs = takeWhile (<=bound) hammingNumbers
      ys = dropWhile (<=5) $ filter isPrime $ map (+1) xs
  print $ safeSum $ map getMultipleSum $ getFeasible ys
