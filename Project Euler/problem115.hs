-- Same idea for linear DP as in Problem 114
dp :: Int -> [Int]
dp m = cache
  where cache = replicate m 1 ++ map fst (iterate step (2,0,cache))
        fst (x, _, _)  = x
        step (prev,acc,(x:xs)) = (prev+acc+x+1,acc+x,xs)

solve :: Int -> Int
solve = length . takeWhile (<=1000000) . dp

main :: IO ()
main = print $ solve 50
