{-# LANGUAGE BangPatterns #-}
import Control.Monad
import Control.Monad.ST
import Data.Array.ST
import Data.Array
import Data.STRef
import Debug.Trace
import System.Random

-- With some modular arithmetic we can deduce
--  p(k) = largest prime factor of 1+4k^2
-- To compute the answer efficiently we realise that
--  k = 2^(-1)*sqrt(-1) mod p where the modular sqrt
--  is done using Cipollas algorithm
--
--  This is only viable for p where p-1 is a multiple of 4.

-- Slow solution that is O(n^2)

largestPrimeFactor :: Integer -> Integer
largestPrimeFactor n = go 1 2 n
  where go acc p n
          | p*p > n      = if n > 1 then n else acc
          | mod n p == 0 = go p p (n `div` p)
          | otherwise    = go acc (p+1) n

solveSlow :: Int -> Integer
solveSlow n = (`mod` (10^18)) $ sum $ map p [1..n]

p = largestPrimeFactor . (\k -> 4*k*k+1) . fromIntegral

-- Faster O(n log n) using Tonelli-Shanks algorithm going over primes
-- (but more complex)

modPow :: Int -> Int -> Int -> Int
modPow b e m = go 1 b e
  where go !acc !p e
          | e == 0    = acc
          | even e    = go acc ((p*p) `mod` m) (e `div` 2)
          | otherwise = go ((acc*p) `mod` m) ((p*p) `mod` m) (e `div` 2)

legendre :: Int -> Int -> Int
legendre n p = modPow n ((p-1) `div` 2) p

-- Use some fixed 'random' numbers for finding quadratic non-residues
-- (not really random but better than sequential)
rs :: [Int]
rs = randoms (mkStdGen 100)

nonResidue :: Int -> Int
nonResidue p = head $ dropWhile ((==1) . (flip legendre p)) nums
  where nums = if p < 10 then [2..p] else (filter (>0) $ map (`mod` p) rs)

getQS :: Int -> (Int,Int)
getQS = go 0
  where go !s !n = if odd n then (n, s) else go (s+1) (n `div` 2)

-- Find x s.t. x^2 = n mod p where p is an odd prime using Tonelli-Shanks alg.
modRoot :: Int -> Int -> Int
modRoot n p = go s (modPow (nonResidue p) q p) (modPow n q p) (modPow n ((q+1) `div` 2) p)
  where (q,s) = getQS (p-1)
        go m c 0 r = 0
        go m c 1 r = r
        go m c t r = go i b2 ((t*b2) `mod` p) ((r*b) `mod` p)
          where i = findI t 0
                findI tp i = if tp == 1 then i else findI ((tp*tp) `mod` p) (i+1)
                b = (iterate ((`mod` p) . (^2)) c) !! (m-i-1)
                b2 = (b*b) `mod` p

removePowers :: Int -> Int -> Int
removePowers n p
  | n > p && n `mod` p == 0 = removePowers (n `div` p) p
  | otherwise               = n

solve :: Int -> Integer
solve n = runST $ do
  isPrime <- newArray (0,2*n) True :: ST s (STUArray s Int Bool)
  maxPrime <- newArray (0,n) 0 :: ST s (STUArray s Int Int)

  forM_ [1..n] $ \k -> writeArray maxPrime k (1+4*k*k)

  forM_ (2:[3,5..2*n]) $ \i -> do
    prime <- readArray isPrime i
    when prime $ do
      forM_ [(i*i),(i*i+i)..2*n] $ \j -> writeArray isPrime j False
      when ((i-1) `mod` 4 == 0) $ do
        -- k = modInv(2,i) * modSqrt(-1,i)   (2 solutions)
        let k1 = (((i+1) `div` 2) * modRoot (i-1) i) `mod` i
            k2 = i-k1
        forM_ ([k1,k1+i..n] ++ [k2,k2+i..n]) $ \j -> do
          v <- readArray maxPrime j
          writeArray maxPrime j (removePowers v i)
  
  total <- newSTRef 0
  forM_ [1..n] $ \k -> do
    v <- readArray maxPrime k
    modifySTRef' total (+(fromIntegral v))
  tot <- readSTRef total
  return $ tot `mod` (10^18)

main :: IO ()
main = print $ solve 10000000
