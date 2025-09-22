module Power where

-- isPowerOf n base bernilai True jika n = base ^ k
-- dengan n dan base adalah bilangan asli
-- dan k adalah bilangan bulat nonnegatif
-- contoh: isPowerOf 27 3 = True (3^3 = 27)
-- contoh: isPowerOf 1 5 = True (5^0 = 1)
-- contoh: isPowerOf 5 10 = False

-- DEFINISI DAN SPESIFIKASI UTAMA
isPowerOf :: Int -> Int -> Bool
isPowerOf n base
    | base == 1 = n == 1
    | n == 1    = True
    | n < base || n `mod` base /= 0 = False
    | otherwise = isPowerOf (n `div` base) base