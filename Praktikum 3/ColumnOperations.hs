module ColumnOperations where 



konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

-- REALISASI
konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l


transpose :: [[Int]] -> [[Int]]
transpose [] = []
transpose ([]:_) = []
transpose x = map head x : transpose (map tail x)

columnOperations :: [[Int]] -> [Int]
columnOperations a
	| null a = []
	| null (head a) = []
	| otherwise = zipWith applyOp [0..] (transpose a)
	where

		ops = cycle [maximum, minimum, sum]
		applyOp i col = (ops !! i) col

