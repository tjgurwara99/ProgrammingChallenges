findX :: Int -> Double
findX k = ((-b) - sqrt (b*b-4*a*c)) / (2*a)
  where a = 1 + 1 / (fromIntegral (k*k))
        b = (-2)*(1 + 1 / (fromIntegral k))
        c = 1 

getRatio :: Int -> Double
getRatio k = (y + sin theta - theta) / (2 - pi / 2)
  where x = findX k
        y = x / (fromIntegral k)
        theta = atan $ (1 - x) / (1 - y)

main :: IO ()
main = print $ head $ filter ((<0.001) . getRatio) [1..]
