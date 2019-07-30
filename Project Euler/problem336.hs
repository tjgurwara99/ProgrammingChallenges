import Data.Char
import Data.List

toString :: [Int] -> String
toString arr = map (\x -> chr $ 65+n-x) arr
  where n = length arr

maximix :: Int -> [[Int]]
maximix 2 = [[1,2]]
maximix n = concatMap ithPerms [1..n-2]
  where ms = maximix (n-1)
        modify i arr = reverse b ++ [n] ++ a
          where (a,b) = splitAt i arr
        ithPerms i = map (modify i) ms

ithMaximix :: Int -> Int -> String
ithMaximix n i = sort (map toString $ maximix n) !! (i-1)

main :: IO ()
main = putStrLn $ ithMaximix 11 2011
