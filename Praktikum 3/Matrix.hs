module Matrix where 

-- UTILITY FUNCTIONS
konsdot :: [Int] -> Int -> [Int]
konso :: Int -> [Int] -> [Int]
isEmpty :: [Int] -> Bool

konso e l = [e] ++ l
konsdot l e = l ++ [e]
isEmpty l = null l

konsdotMatrix :: [[Int]] -> [Int] -> [[Int]]
konsoMatrix :: [Int] -> [[Int]] -> [[Int]]
isEmptyMatrix :: [[Int]] -> Bool

konsoMatrix e l = [e] ++ l
konsdotMatrix l e = l ++ [e]
isEmptyMatrix l = null l

-- NOTES: Semua Index dipastikan valid, yaitu tidak negatif dan tidak melebihi panjang list/Matrix

-- MATRIX MANIPULATION FUNCTIONS
-- TYPE: Matrix adalah [[Int]]
-- Dengan definisi type sebagai berikut, kita dapat mensubstitusi [[Int]] dengan Matrix
type Matrix = [[Int]]

-- addAtIndex :: Int -> [Int] -> Int -> [Int]
-- {addAtIndex x l i menambahkan elemen x pada posisi i dalam l}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [x] apabila l kosong
addAtIndex :: Int -> [Int] -> Int -> [Int]
addAtIndex x [] _ = [x]
addAtIndex x l 0 = konso x l
addAtIndex x (y:ys) i = y : addAtIndex x ys (i-1)

-- deleteAtIndex :: [Int] -> Int -> [Int]
-- {deleteAtIndex l i menghapus elemen pada posisi i dalam l}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [] apabila l kosong
deleteAtIndex :: [Int] -> Int -> [Int]
deleteAtIndex [] _ = []
deleteAtIndex (_:ys) 0 = ys
deleteAtIndex (y:ys) i = y : deleteAtIndex ys (i-1)

-- editAtIndex :: [Int] -> Int -> Int -> [Int]
-- {editAtIndex l i newValue mengubah elemen l pada posisi i dengan newValue}
-- 
-- Note: list l mungkin kosong
--       Mengembalikan [] apabila l kosong
editAtIndex :: [Int] -> Int -> Int -> [Int]
editAtIndex [] _ _ = []
editAtIndex (_:ys) 0 newValue = newValue : ys
editAtIndex (y:ys) i newValue = y : editAtIndex ys (i-1) newValue

-- addMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
-- {addMatrixElement m row col value menambahkan value pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
addMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
addMatrixElement [] _ _ _ = []
addMatrixElement (r:rs) 0 col value = addAtIndex value r col : rs
addMatrixElement (r:rs) row col value = r : addMatrixElement rs (row-1) col value

-- deleteMatrixElement :: Matrix -> Int -> Int -> Matrix  
-- {deleteMatrixElement m row col menghapus elemen pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
deleteMatrixElement :: Matrix -> Int -> Int -> Matrix
deleteMatrixElement [] _ _ = []
deleteMatrixElement (r:rs) 0 col = deleteAtIndex r col : rs
deleteMatrixElement (r:rs) row col = r : deleteMatrixElement rs (row-1) col

-- editMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
-- {editMatrixElement m row col newValue mengubah elemen pada posisi (row,col) dengan newValue}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan [] apabila m kosong
editMatrixElement :: Matrix -> Int -> Int -> Int -> Matrix
editMatrixElement [] _ _ _ = []
editMatrixElement (r:rs) 0 col newValue = editAtIndex r col newValue : rs
editMatrixElement (r:rs) row col newValue = r : editMatrixElement rs (row-1) col newValue

-- getMatrixElement :: Matrix -> Int -> Int -> Int
-- {getMatrixElement m row col mengambil elemen pada posisi (row,col) dalam m}
-- 
-- Note: Matrix m mungkin kosong
--       Mengembalikan 0 apabila m kosong
getMatrixElement :: Matrix -> Int -> Int -> Int
getMatrixElement [] _ _ = 0
getMatrixElement (r:_) 0 col = r !! col
getMatrixElement (_:rs) row col = getMatrixElement rs (row-1) col

-- printMatrix :: Matrix -> IO ()
-- {printMatrix m mencetak m dalam format yang mudah dibaca}
printMatrix :: Matrix -> IO ()
printMatrix [] = putStrLn "Empty m"
printMatrix m = mapM_ print m
