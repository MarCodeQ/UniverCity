-- isGood:: String -> Bool
-- isGood (x:_) = x <= 'M'
-- isGood _ = False

-- assess :: String -> String
-- assess movie = movie ++ " - " ++ assessment
--   where assessment = if isGood movie
--                      then "Good"
--                      else "Bad"

-- assessMovies1 :: [String] -> [String]
-- assessMovies1 [] = []
-- assessMovies1 [x:y] = [assess y]

-- assessMovies2 :: [String] -> [String]
-- assessMovies2 []       = []
-- assessMovies2 (y:[])   = assess y : []
-- assessMovies2 (x:y:[]) = assess x : assess y : []

-- assessMovies3 :: [String] -> [String]
-- assessMovies3 []     = []
-- assessMovies3 (x:xs) = assess x : assessMovies3 xs

import qualified Data.List as L

movies =
  [ "Aeon Flux"
  , "The Black Cat"
  , "Superman"
  , "Stick It"
  , "The Matrix Revolutions"
  , "The Raven"
  , "Inception"
  , "Looper"
  , "Hoodwinked"
  , "Tell-Tale"
  ]

isGood :: String -> Bool
isGood (x:_) = x <= 'M'
isGood _     = False

assess :: String -> String
assess movie = movie ++ " - " ++ assessment
  where assessment = if isGood movie
                     then "Good"
                     else "Bad"

assessMovies :: [String] -> [String]
assessMovies = map assess

assessedMovies :: [String]
assessedMovies = assessMovies movies

main :: IO ()
main = putStrLn (L.intercalate "\n" assessedMovies)

type Name = [Char]
