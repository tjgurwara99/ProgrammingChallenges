nck :: Int -> Int -> Integer
nck n k = prod [n,n-1..(n-k+1)] `div` prod [1..k]
  where prod = product . map fromIntegral

colCount :: Int -> Int -> Integer
colCount rowSize tileSize = sum $ map numCount [1..maxCount]
  where numCount count = nck (rowSize - tileSize * count + count) count
        maxCount = rowSize `div` tileSize

main :: IO ()
main = print $ sum $ map (colCount 50) [2,3,4]
