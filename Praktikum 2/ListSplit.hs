module ListSplit where

-- DEFINISI DAN SPESIFIKASI FUNGSI
-- splitHead: [Int] -> (Int,[Int])
-- {splitHead(l) menghasilkan pasangan (head, rest) dari list l, l tidak kosong}
-- Contoh : splitHead [1,2,3,4,5] = (1,[2,3,4,5])
splitHead :: [Int] -> (Int,[Int])
splitHead li = (head li, tail li)

-- splitTail: [Int] -> ([Int],Int)
-- {splitTail(l) menghasilkan pasangan (rest, tail) dari list l, l tidak kosong}
-- Contoh : splitTail [1,2,3,4,5] = ([1,2,3,4],5)
splitTail :: [Int] -> ([Int],Int)
splitTail li = (init li, last li)
