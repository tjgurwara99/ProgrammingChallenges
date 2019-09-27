{-# LANGUAGE BangPatterns #-}
-- Count increasing/decreasing numbers up to n using a simple DP
count :: Bool -> Int -> Integer
count isIncreasing n = sum $ map (sum . tail) $ take n $ iterate step (replicate 10 1)
  where step = if isIncreasing then prefixSum . reverse else reverse . prefixSum
        prefixSum = go 0 []
        go !total !acc [] = acc
        go !total !acc (x:xs) = let total' = total+x in go total' (total':acc) xs
-- step dp = [ sum (if isIncreasing then drop d dp else take (d+1) dp) | d <- [0..9]]
-- The version in the code is optimised and runs about 5x less memory and time

-- Count increasing and decreasing and subtract double counted expressions
solve :: Int -> Integer
solve n = count True n + count False n - 9*(fromIntegral n)

main :: IO ()
main = print $ solve 100
