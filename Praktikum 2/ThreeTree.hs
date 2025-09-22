module ThreeTree where

threeTree :: [Int] -> [Int]
threeTree li
  | null li = []
  | head li `mod` 3 == 0 = head li : threeTree (tail li)
  | otherwise = threeTree (tail li)

