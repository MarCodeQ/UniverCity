res []     = 0
res (x:xs) = x + res xs
sum_square xs = sum [if x == sqrt x * sqrt x then res [x] else 0 | x <- xs]


