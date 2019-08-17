-- Solved using some modular arithmetic
-- Haskell solution runs in ~0.2s
egcd :: Int -> Int -> (Int,Int,Int)
egcd a 0 = (a,1,0)
egcd a b = (g,t,s-q*t)
  where (q,r) = divMod a b
        (g,s,t) = egcd b r

modInv :: Int -> Int -> Int
modInv n p = s `mod` p
  where (_, s, _) = egcd n p

primes :: [Int]
primes = 2 : filter (isPrime primes) [3,5..]
  where isPrime (p:ps) n = p*p > n || n `mod` p /= 0 && isPrime ps n

s :: Int -> Int -> Integer
s p1 p2 = (fromIntegral n)*(fromIntegral x)+(fromIntegral p1)
  where x = ((p2-p1)*(modInv n p2)) `mod` p2
        n = 10 ^ (length $ show p1)

solve :: Int -> Integer
solve n = sum $ zipWith s ps (tail ps)
  where (a,b) = span (<=n) primes
        ps = dropWhile (<5) $ a ++ [head b] -- include first prime > n

main :: IO ()
main = print $ solve 1000000
