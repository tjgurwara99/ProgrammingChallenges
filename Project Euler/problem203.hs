import Data.List

n :: Int
n = 51

isPrime :: Int -> Bool
isPrime p = go 2
  where go x = x*x > p || p `mod` x /= 0 && go (x+1)

primes :: [Int]
primes = filter isPrime [2..(n-1)]

primeRepr :: Int -> [Int]
primeRepr x = map power primes
  where power p = length $ takeWhile ((==0) . (`mod` p)) $ iterate (`div` p) x

third (a,b,c) = c

-- Operations on prime representations
squareFree = all (<=1)
addRepr = zipWith (+)
subRepr = zipWith (-)

squareFreeNums :: Int -> [Integer]
squareFreeNums row = third $ foldl step (primeRepr 1, 1, [1]) [1..row]
  where step (repr,num,acc) i = (repr', num', acc')
          where repr' = repr `addRepr` (primeRepr (row-i+1)) `subRepr` (primeRepr i)
                num' = (num * (fromIntegral (row-i+1))) `div` (fromIntegral i)
                acc' = if squareFree repr' then num':acc else acc

removeDups :: Ord a => [a] -> [a]
removeDups = collect [] . sort
  where collect acc [] = acc
        collect acc (x:xs) = collect (x:acc) (dropWhile (==x) xs)

main :: IO ()
main = print $ sum $ removeDups $ concatMap squareFreeNums [0..(n-1)]
