module SlidingWindow where

konso:: a -> [a] -> [a]
konso e l = e : l

konsDot:: [a] -> a -> [a]
konsDot l e = l ++ [e]

isEmpty:: [a] -> Bool
isEmpty l = null l

nbElement:: [a] -> Int
nbElement l = if isEmpty l then 0 else 1 + nbElement (tail l)

{-|
  TakeN menerima sebuah integer n dan sebuah list l, dan menghasilkan sebuah list yang berisi n elemen pertama dari l. Jika n lebih besar dari panjang l, maka dihasilkan l itu sendiri.
  Prekondisi: n >= 0, l bisa kosong.
-}
takeN:: Int -> [a] -> [a]
takeN n l =
    if n >= length l then
        l
    else
        if length l == 0 || n == 0 then
            []
        else
            konso (head l) (takeN (n-1) (tail l))                                                                                                                                                                                   

{-|
  Deskripsi:
  Fungsi slidingWindow menerima sebuah integer ukuran window n prekondisi : 0 < n <= panjang xs,
  sebuah fungsi pemroses f, dan sebuah list xs, prekondisi : panjang xs > 0. Fungsi ini akan
  menghasilkan sebuah list baru yang berisi hasil dari penerapan
  fungsi f ke setiap window dengan ukuran n. Dapat menggunakan fungsi takeN.

  Contoh:
  slidingWindow 3 windowRange [1, 2, 3, 4, 5] akan menghasilkan [2, 2, 2]
-}
slidingWindow :: Int -> ([a] -> b) -> [a] -> [b]
slidingWindow n f l
    | isEmpty l = []
    | n > length l = []
    | otherwise = konso (f (takeN n l)) (slidingWindow n f (tail l))

{-|
  Deskripsi:
  Fungsi windowRange menghasilkan selisih antara nilai maksimum dan nilai minimum dari list tersebut.
  nilai minimum dari list tersebut.

  Contoh:
  windowRange [1, 2, 3, 4, 5] akan menghasilkan 4
-}
windowRange:: [Int] -> Int
windowRange l =
    if isEmpty l then
        0
    else if length l == 1 then
        0
    else
        (maxList l) - (minList l)
        
maxList :: [Int] -> Int
maxList l =
    if isEmpty l then
        0
    else 
        let 
            maks = -99999
        in
            maxList2 maks l

maxList2 :: Int -> [Int] -> Int
maxList2 maks l =
    if length l == 1 then
        if maks > head l then
            maks
        else
            head l
    else 
        if maks > head l then
            maxList2 maks (tail l)
        else 
            maxList2 (head l) (tail l)

minList :: [Int] -> Int
minList l =
    if isEmpty l then
        0
    else 
        let 
            mins = 99999
        in
            minList2 mins l

minList2 :: Int -> [Int] -> Int
minList2 mins l =
    if length l == 1 then
        if mins < head l then
            mins
        else
            head l
    else 
        if mins < head l then
            minList2 mins (tail l)
        else 
            minList2 (head l) (tail l)