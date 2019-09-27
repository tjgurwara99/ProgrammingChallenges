import Data.Int
import Data.Bits
import Data.List

import Data.Array.Unboxed
import Data.Array.ST
import Control.Monad

n :: Int64
n = 10^8

sieve :: Int64 -> UArray Int64 Bool
sieve bound = runSTUArray $ do
  let m = ceiling $ sqrt (fromIntegral bound)
  isPrime <- newArray (2,bound) True
  forM_ [2..m] $ \i -> do
    p <- readArray isPrime i
    when p $ do
      forM_ [i*i,i*i+i..bound] (\j -> writeArray isPrime j False)
  return isPrime

isPrime :: Int64 -> Bool
isPrime p = p >= 2 && (sieve' ! p)
  where sieve' = sieve n

primes :: [Int64]
primes = filter isPrime [2..n]

solve :: Int64
solve = sum $ map (\p -> solvePrime p (getBs p)) primes

-- Given a and candidates for b, find the sum of all valid (a,b,c) pairs
solvePrime :: Int64 -> [Int64] -> Int64
solvePrime a bs = go 0 bs
  where go acc []     = acc
        go acc (b:bs) = if c <= n then go acc' bs else acc
          where acc' = if isPrime c then a+b+c+acc else acc
                c = div ((b+1)*(b+1)) (a+1)  - 1

intSqrt :: Int64 -> Int64
intSqrt = binSearch 0 n
  where binSearch l u x | u == l+1 = l
        binSearch l u x = if m*m <= x then binSearch m u x else binSearch l m x
          where m = shift (l+u) (-1)

-- Find valid candidates for b given a by considering that (b+1)*(b+1) mod (a+1) == 0
-- so we can iterate over multiples of a+1 that are square then filter those which are prime
getBs :: Int64 -> [Int64]
getBs a = filter isPrime $ dropWhile (<=a) $ map (\x -> k*x-1) [1..u]
  where u = (intSqrt ((a+1)*(n+1)) + 1) `div` k
        k = intSqrt $ fillGaps (a+1) -- all multiples of a+1 that are square are multiples of k*k

-- Get smallest multiple that is a square
fillGaps :: Int64 -> Int64
fillGaps a = go a a primes
  where go acc num []     = acc
        go acc num (p:ps)
          | p*p > num = if num > 1 then num*acc else acc
          | otherwise = go acc' num' ps
            where (num', power) = countPower 0 num p
                  acc' = if odd power then p*acc else acc
        countPower acc num p = if r == 0 then countPower (acc+1) q p else (num, acc)
          where (q,r) = divMod num p

main :: IO ()
main = print solve
