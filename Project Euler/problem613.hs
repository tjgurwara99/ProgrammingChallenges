import Text.Printf

simpsons :: Int -> (Double -> Double) -> Double -> Double -> Double
simpsons n f a b = ((h/3) *) $ sum $ map (\i -> f (getX i) * coeff i) [0..n]
  where coeff i = if odd i then 4 else if i == 0 || i == n then 1 else 2
        x i = a + h*(fromIntegral i)
        h = (b-a)/(fromIntegral n)

theta :: Double -> Double -> Double
theta x y = pi/2 + atan2 y x + atan2 (30-x) (40-y)

main :: IO ()
main = do
  let n = 20000
      integral = simpsons n (\x -> simpsons n (theta x) 0 (4*x/3)) 0 30
      ans = integral / (1200 * pi)
  printf "%.10f\n" ans
