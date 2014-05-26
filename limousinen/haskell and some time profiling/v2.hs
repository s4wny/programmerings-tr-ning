import System.IO (getContents)
import Data.List (sort)

-- Input parse helper
toInt :: String -> Int
toInt = read

cordsToTime :: [Int] -> [Int]
cordsToTime (x:y:xs)  = (abs x + abs y)*2 : cordsToTime xs
cordsToTime otherwise = []


main = do
    stdin <- getContents :: IO String
    let stdin' = tail $ map toInt $ concat $ map words $ lines stdin
    let time   = head $ stdin'
    let cords  = tail $ stdin'

    let summedList = sort $ cordsToTime cords

    --print $ summedList
    --print $ scanl (\acc x -> acc - x) time summedList
    print $ (length $ filter (>= 0) $ scanl (\acc x -> acc - x) time summedList) - 1