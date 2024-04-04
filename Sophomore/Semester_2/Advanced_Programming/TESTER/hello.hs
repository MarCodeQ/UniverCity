multiples :: Int -> Int -> Int
multiples x limit = sum [n | n <- [x,2*x..limit]]
sumOfMultiples :: [Int] -> Int -> Int
sumOfMultiples factors limit = sum [multiples x limit | x <- factors]

edd= \a -> (\b -> (\c -> ( \d -> a + b + c + d)))