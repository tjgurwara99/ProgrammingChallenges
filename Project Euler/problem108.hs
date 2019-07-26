import Data.List
import qualified Data.Set as Set

{- Solution: (wlog assume a <= b)
 - 1/a + 1/b = 1/n if and only if n <= a <= 2n and b = an / (a-n) is an integer.
 -
 - Let x = a-n >= 0.
 - Then b is an integer iff. x is a factor of an=n(x+n)=xn+n*n
 - which is iff. x is a factor of n*n (and <= n)
 - 
 - Thus the answer is the number of factors of n*n less than or equal to n.
 - Which is equal to (factorCount(n*n)+1)/2
 -
 - The solution is a straight forward BFS for the smallest n represented as a product
 - of prime powers and to find n where factorCount(n*n) >= 1999
 - -}

-- More primes aren't needed as this already has enough factors
primes :: [Int]
primes = [2,3,5,7,11,13,17,19]

reprToNum :: [Int] -> Int
reprToNum = product . zipWith (^) primes

expand :: (Int,Int) -> [(Int,Int)]
expand (num,i) = zipWith (\j p -> (num*p,j)) [i..] (drop i primes)

search :: Set.Set [(Int,Int)] -> [(Int,Int)]
search branches = x : search branches'
  where ((x:xs), withoutMin) = Set.deleteFindMin branches
        expanded = Set.insert (expand x) withoutMin
        branches' = if null xs then expanded else Set.insert xs expanded

primeFactorise :: Int -> [(Int,Int)]
primeFactorise n = map (\xs -> (head xs, length xs)) $ group $ go [] n 2
  where go acc x p
          | p*p > x && x > 1 = x:acc
          | p*p > x          = acc
          | x `mod` p == 0   = go (p:acc) (x `div` p) p
          | otherwise        = go acc x (p+1)

countFactors :: Int -> Int
countFactors = product . map ((+1) . snd) . primeFactorise

countSolutions :: Int -> Int
countSolutions n = (countFactors (n*n) + 1) `div` 2

solve :: Int
solve = head $ dropWhile ((<1000) . countSolutions) nums
  where nums = map fst $ search (Set.singleton [(1,0)])

main :: IO ()
main = print solve
