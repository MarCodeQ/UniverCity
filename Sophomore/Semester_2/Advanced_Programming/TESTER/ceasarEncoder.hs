import Data.Char

caesar :: String -> Int -> String
caesar []  =0
caesar (c:cs) shift
    | isAlpha c = shiftChar c shift : caesar cs shift
    | otherwise = c : caesar cs shift

shiftChar :: Char -> Int -> Char
shiftChar c shift
    | isUpper c = chr $ (ord c - ord 'A' + shift) `mod` 26 + ord 'A'
    | isLower c = chr $ (ord c - ord 'a' + shift) `mod` 26 + ord 'a'
    | otherwise = c
main :: IO ()
main = do
  let encoded = ceasar "abc" 3
  putStrLn encoded
