import System.IO (getLine)

toInt :: [String] -> [Int]
toInt = map read

-- Get every nth element in a list
every :: Int -> [Int] -> [Int]
every _ []     = []
every n (x:xs) = x : every n (drop (n-1) xs)

main = do
    stdin <- getLine
    let numbers = toInt $ words stdin
    let total   = sum [foldl (\acc x -> acc + x*3) 0 (every 2 numbers),
                       foldl (\acc x -> acc + x*7) 0 (every 2 (tail numbers))]

    print $ total `mod` 10