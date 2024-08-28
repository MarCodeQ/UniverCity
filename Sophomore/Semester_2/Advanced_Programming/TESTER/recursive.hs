f [] = []
f (x:xs) = f ys ++ [x] ++ f zs
  where
    ys = [a | a <- xs, a <= x]
    zs = [b | b <- xs, b > x]
no :: Bool -> Bool
no False = True
no True = False
ignoreArgs :: a -> b -> c -> ()
ignoreArgs _ _ _ = ()
alwaysFive :: a -> Int
alwaysFive _ = 5
add :: (Double,Double)-> Double
add (x,y) = x+y

factors :: Int -> [Int]
factors n = [x | x <- [1..n-1], n `mod` x == 0]
perfects :: Int -> [Int]
perfects limit = [n | n <- [1..limit], n == sum (factors n)]
scalarProduct :: [Int] -> [Int] -> Int
scalarProduct xs ys = sum [x * y | (x, y) <- zip xs ys]