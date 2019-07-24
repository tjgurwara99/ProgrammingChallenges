import Data.List
import Data.Ratio

type Point = (Int, Int)
type Line = (Point, Point)

ss :: [Integer]
ss = iterate (\x -> (x * x) `mod` 50515093) 290797

ts :: [Int]
ts = map (\x -> fromIntegral (mod x 2000 - 1000)) ss

points :: [Point]
points = collect (tail ts)
  where collect (x:y:xs') = (fromIntegral x, fromIntegral y) : collect xs'

getGradients :: [Point] -> [(Int,Int)]
getGradients []     = []
getGradients (_:[]) = []
getGradients (x:xs) = unique gs ++ getGradients xs
  where gs = map (gradient . ((,) x)) xs

gradient :: Line -> (Int, Int)
gradient ((x1,y1), (x2,y2)) = (dy `div` k, dx `div` k)
  where dy = y2 - y1
        dx = x2 - x1
        k = gcd (abs dy) (abs dx)

frequencies :: Ord a => [a] -> [(a,Int)]
frequencies xs = collect [] $ sort xs
  where collect acc [] = acc
        collect acc (x:xs) = collect ((x, (1 + length as)) : acc) bs
          where (as,bs) = span (==x) xs

removeDups :: Ord a => [a] -> [a]
removeDups xs = collect [] $ sort xs
  where collect acc [] = acc
        collect acc (x:xs) = collect (x:acc) (dropWhile (==x) xs)

-- Return only elements that occur uniquely in the input list
unique :: Ord a => [a] -> [a]
unique = map fst . filter ((==1) . snd) . frequencies

pairCount :: Int -> Integer
pairCount n = ((fromIntegral n)*(fromIntegral n - 1))

solve :: Int -> Integer
solve n = pairCount (length xs) - innerSum
  where xs = getGradients $ removeDups $ take n points
        innerSum = sum $ map (pairCount . snd) $ frequencies xs

main :: IO ()
main = print $ solve 2500
