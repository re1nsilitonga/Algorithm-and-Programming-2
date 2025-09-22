module SecondLargest where

isOneElmt :: [Int] -> Bool
isOneElmt li = length li == 1

max2 :: Int -> Int -> Int
max2 a b = if a>=b then a else b

min2 :: Int -> Int -> Int
min2 a b = if a<=b then a else b

maxList :: [Int] -> Int
maxList l = if (isOneElmt l) then head l
else max2 (head l) (maxList (tail l))

konso :: Int -> [Int] -> [Int]
konso e l = [e] ++ l

delElmt :: Int -> [Int] -> [Int]
delElmt e li =
    if head li == e then
        tail li
    else
        konso (head li) (delElmt e (tail li))


secondLargest :: [Int] -> Int
secondLargest l =
    if isOneElmt l then head l
    else
        let li = delElmt (maxList l) l
        in
            if isOneElmt li then head li
            else max2 (head li) (maxList (tail li))

