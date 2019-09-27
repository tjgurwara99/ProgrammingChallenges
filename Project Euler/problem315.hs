import Data.Bits

lights :: Int -> Int
lights = ([0x77, 0x24, 0x5D, 0x6D, 0x2E, 0x6B, 0x7B, 0x27, 0x7F, 0x6F] !!)

digits :: Int -> [Int]
digits 0 = []
digits n = n `mod` 10 : digits (n `div` 10)

digitalRoot :: Int -> [Int]
digitalRoot n = if n' == n then [n] else n : digitalRoot n'
  where n' = sum $ digits n

digitLightCount :: Int -> Int
digitLightCount = popCount . lights

lightCount :: Int -> Int
lightCount = sum . map digitLightCount . digits

transitionCount :: Int -> Int -> Int
transitionCount a b = go 0 (digits a) (digits b)
  where go acc xs [] = acc + (sum $ map digitLightCount xs)
        go acc [] xs = acc + (sum $ map digitLightCount xs)
        go acc (x:xs) (y:ys) = go (acc + digitTrans x y) xs ys
        digitTrans x y = popCount $ (lights x) `xor` (lights y)

samRoot :: Int -> Int
samRoot = (*2) . sum . map lightCount . digitalRoot

maxRoot :: Int -> Int
maxRoot n = lightCount (head xs) + lightCount (last xs) + transitions
  where xs = digitalRoot n
        transitions = sum $ zipWith transitionCount xs (tail xs)

primes :: [Int]
primes = 2 : 3 : 5 : primes'
  where isPrime (p:ps) x = p*p > x || x `rem` p /= 0 && isPrime ps x
        primes' = 7 : filter (isPrime primes') (scanl (+) 11 $ cycle [2,4,2,4,6,2,6,4])

main :: IO ()
main = print $ sum $ map (\p -> samRoot p - maxRoot p) ps
  where ps = takeWhile (<20000000) $ dropWhile (<10000000) primes
