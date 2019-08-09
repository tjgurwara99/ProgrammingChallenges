solve :: Int -> Int
solve n =  go 0 3 1
  where go acc s k 
          | k > s-2     = acc
          | s*s-k*k > n = go acc s (k+1)
          | otherwise   = go (acc+(s-k)`div`2) (s+1) k

main :: IO ()
main = print $ solve 1000000
