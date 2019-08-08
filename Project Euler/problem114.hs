solve :: Int -> Integer
solve n = dp !! n
  where dpSlow = 1:1:1:(map f [3..])
        f n = 1 + (dpSlow !! (n-1)) + sum (take (n-3) dpSlow)
        dp = 1:1:1:map fst (iterate step (2,0,dp))
        fst (x, _, _)  = x
        step (prev,acc,(x:xs)) = (prev+acc+x+1,acc+x,xs)
-- Faster DP is linear rather than quadratic and much more memory efficient

main :: IO ()
main = print $ solve 50
