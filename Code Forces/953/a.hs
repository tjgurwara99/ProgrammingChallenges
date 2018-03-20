countNums :: Integer -> Integer -> Integer -> Int -> Int
countNums n p2 p3 cnt
  | p2 >= n       = cnt
  | p2*p3 >= n    = countNums n (p2*2) 1 cnt
  | otherwise     = countNums n p2 (p3*3) (cnt+1)

countLT :: Integer -> Int
countLT n = countNums n 1 1 0

main :: IO ()
main = do
    xs <- fmap (map (read :: String -> Integer) . words) getLine
    print $ countLT ((xs!!1) + 1) - countLT (head xs) 
