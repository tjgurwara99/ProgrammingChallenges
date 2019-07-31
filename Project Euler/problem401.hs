-- Re-arrange sum to give SUM(d^2 * floor(n/d)) 1<=d<=n and then use sqrt(n) trick
solve :: Integer -> Int
solve n = (below + above) `mod` (10^9)
  where root = 1 + (floor $ sqrt $ fromIntegral n)
        below = sum $ map (\d -> modOut (d*d*(div n d))) [1..div n root]
        ssum x = modOut $ div (x*(x+1)*(2*x+1)) 6
        above = sum (map (ssum . div n) [1..root-1]) - (fromIntegral root-1) * ssum (div n root)
        modOut x = fromIntegral (x `mod` (10^9))

main :: IO ()
main = print $ solve (10^15)
