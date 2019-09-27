-- DP solution to recursion:
-- pwin(t,bneeded)=(pwin(t-1,bneeded-1)+pwin(t-1,bneeded)*t) / (t+1)
solve :: Int -> Int
solve n = floor (1 / probWin)
  where probWin = dps !! n !! (1+div n 2)
        dps = map snd $ iterate (\(i,dp) -> (i+1, step (i+1) dp)) (0,1:(repeat 0))
        step t dp = map (/(t+1)) $ zipWith (+) (1:dp) (map (t*) dp)

main :: IO ()
main = print $ solve 15
