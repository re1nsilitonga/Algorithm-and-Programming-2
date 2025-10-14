module TreeFold where

-- DEFINISI DATA STRUKTUR
-- Binary Tree dengan konstruktor Node dan Empty
data BinTree a = Empty | Node a (BinTree a) (BinTree a)
  deriving (Show, Eq)

-- KONSTRUKTOR
-- Definisi dan Spesifikasi utama
makeBinTree :: Int -> (BinTree Int) -> (BinTree Int) -> (BinTree Int)
-- Realisasi
makeBinTree a l r = Node a l r

-- SELEKTOR
-- Definisi dan Spesifikasi utama
akar  :: BinTree Int -> Int
left  :: BinTree Int -> BinTree Int
right :: BinTree Int -> BinTree Int

-- Realisasi
akar Empty          = error "akar: pohon kosong tidak punya akar"
akar (Node v _ _)   = v

left Empty          = error "left: pohon kosong tidak punya subpohon kiri"
left (Node _ l _)   = l

right Empty         = error "right: pohon kosong tidak punya subpohon kanan"
right (Node _ _ r)  = r

-- PREDIKAT
-- Definisi dan Spesifikasi utama
isTreeEmpty  :: BinTree a -> Bool
isOneElmt    :: BinTree a -> Bool
isExistLeft  :: BinTree a -> Bool
isExistRight :: BinTree a -> Bool
isUnerLeft   :: BinTree a -> Bool
isUnerRight  :: BinTree a -> Bool
isBiner      :: BinTree a -> Bool

-- Realisasi
isTreeEmpty Empty                = True
isTreeEmpty _                    = False

isOneElmt (Node _ Empty Empty)   = True
isOneElmt _                      = False

isExistLeft (Node _ l _)         = not (isTreeEmpty l)
isExistLeft _                    = False

isExistRight (Node _ _ r)        = not (isTreeEmpty r)
isExistRight _                   = False

isUnerLeft (Node _ l r)          = not (isTreeEmpty l) && isTreeEmpty r
isUnerLeft _                     = False

isUnerRight (Node _ l r)         = isTreeEmpty l && not (isTreeEmpty r)
isUnerRight _                    = False

isBiner (Node _ l r)             = not (isTreeEmpty l) && not (isTreeEmpty r)
isBiner _                        = False

-- SPESIFIKASI
-- treeFoldPost f b t menghasilkan akumulasi nilai pohon t dengan fold post-order menggunakan f dan basis b.
-- Definisi: proses subpohon kiri, lalu subpohon kanan, terakhir akar.
treeFoldPost :: (a -> a -> Int -> a) -> a -> BinTree Int -> a
treeFoldPost _ b Empty = b
treeFoldPost f b (Node x leftTree rightTree) = 
    let leftResult = treeFoldPost f b leftTree
        rightResult = treeFoldPost f b rightTree
    in f leftResult rightResult x

-- SPESIFIKASI
-- treeFoldPre f b t menghasilkan akumulasi nilai pohon t dengan fold pre-order menggunakan f dan basis b.
-- Definisi: proses akar terlebih dahulu, lalu subpohon kiri dan subpohon kanan.
treeFoldPre :: (Int -> a -> a -> a) -> a -> BinTree Int -> a
treeFoldPre _ b Empty = b
treeFoldPre f b (Node x leftTree rightTree) = 
    let leftResult = treeFoldPre f b leftTree
        rightResult = treeFoldPre f b rightTree
    in f x leftResult rightResult

-- SPESIFIKASI
-- treeFoldIn f b t menghasilkan akumulasi nilai pohon t dengan fold in-order menggunakan f dan basis b.
-- Definisi: proses subpohon kiri, kemudian akar, dan terakhir subpohon kanan.
treeFoldIn :: (a -> Int -> a -> a) -> a -> BinTree Int -> a
treeFoldIn _ b Empty = b
treeFoldIn f b (Node x leftTree rightTree) = 
    let leftResult = treeFoldIn f b leftTree
        rightResult = treeFoldIn f b rightTree
    in f leftResult x rightResult