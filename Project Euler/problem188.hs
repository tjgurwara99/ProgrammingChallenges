-- Solution using Euler's theorem a^tot(m) mod m == 1
-- and prime power property of totient.
--
-- Solved in 0.021s

expMod :: Int -> Int -> Int -> Int
expMod a b m = go a b 1
  where go y p acc
          | p == 0    = acc
          | even p    = go ((y*y)`mod`m) (p`div`2) acc
          | otherwise = go ((y*y)`mod`m) (p`div`2) ((acc*y)`mod`m)

totient :: Int -> Int
totient a = go 2 a a
  where remove p n
          | n `mod` p == 0 = remove p (n `div` p)
          | otherwise      = n
        go p n acc
            | p*p > n        = if n > 1 then div acc n * (n-1) else acc
            | n `mod` p == 0 = go (p+1) (remove p n) (div acc p * (p-1))
            | otherwise      = go (p+1) n acc

hyperExpMod :: Int -> Int -> Int -> Int
hyperExpMod a 1 m = a `mod` m
hyperExpMod a b m = expMod a (hyperExpMod a (b-1) (totient m)) m

main :: IO ()
main = print $ hyperExpMod 1777 1855 (10^8)
