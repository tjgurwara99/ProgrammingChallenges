-- Iterative memory saving DP for the recursion:
--    count(i) = SUM count(j) for i-4 <= j < i
solve :: Int -> Integer
solve n = ans $ (!! n) $ iterate step (0,0,0,1)
  where ans (_, _, _, x) = x
        step (a,b,c,d) = (b,c,d,a+b+c+d)

main :: IO ()
main = print $ solve 50
