import System.IO (getLine)

listToFloat :: [String] -> [Double]
listToFloat = map read

main = do
    stdin <- getLine
    let (n:k:p:_) = listToFloat $ words stdin

    putStr $ if n*p >= k then "Spela inte!" else "Spela"