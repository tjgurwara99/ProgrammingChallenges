import Data.List

primes :: [Integer]
primes = 2 : 3 : filter (isPrime (tail primes)) [5,7..]
  where isPrime (p:ps) n = p*p > n || n `mod` p /= 0 && isPrime ps n

-- Much more efficient grid-based search with pruning than in problem 108
gridSearch :: [Integer] -> Int -> Integer -> Integer -> Int -> Int -> Integer
gridSearch (p:ps) maxPow currNum currMin sqrFacts needed
  | currNum >= currMin = currMin
  | sqrFacts >= needed = currNum
  | otherwise          = foldl' step currMin [1..maxPow]
    where step currMin pow = gridSearch ps pow (currNum * (p^pow)) currMin (sqrFacts * (2*pow+1)) needed

solve :: Int -> Integer
solve n = gridSearch primes 100 1 (10^50) 1 (2*n-1)

main :: IO ()
main = print $ solve 4000000
