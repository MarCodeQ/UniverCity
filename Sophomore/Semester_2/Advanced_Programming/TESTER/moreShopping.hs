type Name = String
type PriceInCents = Int
type ShoppingListItem = (Name, PriceInCents)
type ShoppingList = [ShoppingListItem]

shoppingList :: ShoppingList
shoppingList =  [ ("Bananas", 300)
                , ("Chocolate", 250)
                , ("Milk", 300)
                , ("Apples", 450)
                ]

sumShoppingList :: ShoppingList -> PriceInCents
sumShoppingList []     = 0
sumShoppingList (x:xs) = getPriceFromItem x + sumShoppingList xs

getPriceFromItem :: ShoppingListItem -> PriceInCents
getPriceFromItem (_, price) = price

main :: IO ()
main = putStrLn ("Price of shopping list is "
                ++ show (sumShoppingList shoppingList)
                ++ " cents.")