import Data.Ratio
import Debug.Trace

query :: [Bool]
query = map (=='P') "PPPPNNPPPNPPNPN"

isPrime :: Int -> Bool
isPrime x | x <= 1 = False
isPrime x = all (\i -> mod x i /= 0) [2..(x-1)]

memo :: [[Rational]] 
memo = [[search pos step | step <- [0..15]] | pos <- [1..500]]

searchMemo :: Int -> Int -> Rational
searchMemo pos step = memo !! (pos-1) !! step

getProbCorrect :: Int -> Int -> Rational
getProbCorrect pos step = if isPrime pos == query !! step then 2 % 3 else 1 % 3

search :: Int -> Int -> Rational
search _ 15 = 1 % 500
search 1 step = getProbCorrect 1 step * searchMemo 2 (step + 1)
search 500 step = getProbCorrect 500 step * searchMemo 499 (step + 1)
search pos step = (1 % 2) * (a + b) * getProbCorrect pos step
    where a = searchMemo (pos-1) (step+1)
          b = searchMemo (pos+1) (step+1)

main :: IO ()
main = print $ sum $ map (\i -> searchMemo i 0) [1..500]
