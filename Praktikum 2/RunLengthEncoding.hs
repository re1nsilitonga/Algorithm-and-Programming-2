module RunLengthEncoding where

isOneElmt :: [a] -> Bool
isOneElmt l = length l == 1

konso ::  (Char, Int) -> [(Char, Int)] -> [(Char, Int)]
konso e l = [e] ++ l

runLengthEncoding :: String -> [(Char, Int)]
runLengthEncoding s
    | null s = []
    | isOneElmt s = [(head s, 1)]
    | otherwise =
        let
            recursiveResult = runLengthEncoding (tail s)
            (firstCharOfResult, firstCountOfResult) = head recursiveResult
            tailOfResult = tail recursiveResult
        in
            if head s == firstCharOfResult then
                konso (head s, firstCountOfResult + 1) tailOfResult
            else
                konso (head s, 1) recursiveResult