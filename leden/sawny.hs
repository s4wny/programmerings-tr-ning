import System.IO (getLine)

toInt :: [String] -> [Int]
toInt = map read

time :: (Num a) => [a] -> a
time (x:y:xs)  = abs(5 - (x-y))*2+60 + time (y:xs)
time otherwise = 0

main = do
    -- Get the data from stdin and process it to a [Int]
    _     <- getLine
    stdin <- getLine
    let wayPoints = toInt $ words stdin

    -- Solve the problem
    print $ time wayPoints