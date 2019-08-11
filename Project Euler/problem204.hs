data Heap a = Leaf | Tree a (Heap a) (Heap a)

minHeapify :: Ord a => Heap a -> Heap a
minHeapify Leaf = Leaf
minHeapify root@(Tree _ Leaf Leaf) = root
minHeapify root@(Tree p (Tree l x y) Leaf) 
  | p <= l    = root
  | otherwise = Tree l (minHeapify $ Tree p x y) Leaf
minHeapify root@(Tree p Leaf (Tree r x y))
  | p <= r    = root
  | otherwise = Tree r Leaf (minHeapify $ Tree p x y)
minHeapify root@(Tree p left@(Tree l x1 y1) right@(Tree r x2 y2))
  | p <= l && p <= r = root
  | l <= r           = Tree l (minHeapify $ Tree p x1 y1) right
  | otherwise        = Tree r left (minHeapify $ Tree p x2 y2)

halve :: [a] -> ([a],[a])
halve [] = ([],[])
halve (x:xs) = let (a,b) = halve xs in (x:b,a)

buildMinHeap :: Ord a => [a] -> Heap a
buildMinHeap [] = Leaf 
buildMinHeap (x:xs) = minHeapify $ Tree x (buildMinHeap l) (buildMinHeap r)
  where (l,r) = halve xs

primes :: [Int]
primes = 2 : filter (isPrime primes) [3,5..]
  where isPrime (p:ps) n = p*p > n || n `mod` p /= 0 && isPrime ps n

hammingNums :: Int -> [Int]
hammingNums n = nums 
  where nums = 1 : go 1 (buildMinHeap chains)
        chains = map (\p -> map (p*) nums) $ takeWhile (<=n) primes
        go p (Tree (x:xs) l r) = if x == p then rest else x:rest
          where rest = go x (minHeapify $ Tree xs l r)
        go _ Leaf = []

solve :: Int -> Int -> Int
solve n bound = length $ takeWhile (<=bound) $ hammingNums n

main :: IO ()
main = print $ solve 100 (10^9)
