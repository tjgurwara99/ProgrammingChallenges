import Text.Printf

ncr :: Integer -> Integer -> Integer
ncr n r = product [n,n-1..n-r+1] `div` product [1..r]

main =
  let f i = fromInteger (ncr 32 i) * (-1)^(i+1) / (1 - 2^^(-i))
      ans = sum $ map f [1..32]
  in printf "%.10f\n" (fromRational ans :: Double)
