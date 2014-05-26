-- I dont even...
-- 
-- Okay. Listen.
-- ```
-- toInt :: String -> Int
-- toInt = read
-- ```
-- IS FUCKING SLOW. LIKE REALLY FUCKING SLOW. FUCKING FUCK SLOW. YES, THAT SLOW.
-- (Or did I just do something really wrong in my `toInt`, huh?)
--
-- So for you to even be able to solve this problem you need a faster toInt functions.
-- That's right.
-- You need to reimplent a faster standard function, and it needs to be faster.
--
-- GLHF.
--
--
-- Well... Turns out it is possible to make a faster toInt.
-- WTF HASKELL?
--
-- (but well, maybe it's because my toInt don't give a fuck about negative numbers.)
-- (but actually I implented that too and it was faster, so yeah)
-- WTF HASKELL??
--
-- Anyway.
-- This shit works. 
-- I went from 77.4% (!!!) CPU time in native `toInt` to 18.7% with my own `toInt`. 
--
-- WTF HASKELL??

--
-- disclaimer: I don't know so much about haskell, probably there is a better and faster way. Probably it has to do with these monads and famp and >>= >> stuff.
--


import System.IO (getContents)
import Data.List (sort)


-- Input parse helper
toInt :: String -> Integer
toInt xs = toInt' xs (length xs - 1) 
    where
        toInt' :: String -> Int -> Integer
        toInt' []     _    = 0
        toInt' (x:xs) base = toInteger ((chrToInt x)*10^base) + toInt' xs (base-1)

        chrToInt :: Char -> Int
        chrToInt str
            | str == '0' = 0
            | str == '1' = 1
            | str == '2' = 2
            | str == '3' = 3
            | str == '4' = 4
            | str == '5' = 5
            | str == '6' = 6
            | str == '7' = 7
            | str == '8' = 8
            | str == '9' = 9
            | otherwise  = 0 -- (negative numbers, '-')


-- cordinates -> time
cordsToTime :: [Integer] -> [Integer]
cordsToTime (x:y:xs)  = (x + y)*2 : cordsToTime xs
cordsToTime otherwise = []

main = do
    stdin <- getContents :: IO String

    -- 44.8% of the time is spent here -.-, so my result "0.93 s" should be cut to "~0.50s" I guess. 
    -- But well, even at 0.50s my python code was faster. So the conclution is that
    -- this algorithm with scanl and filter isn't that fast.
    -- I probably should benchmark some more and try to find a even faster way to do this
    --
    -- (This line just format the input into a list of Integers....)
    let stdin' = tail $ map toInt (concat $ map words $ lines stdin) 


    let time   = head $ stdin'
    let cords  = tail $ stdin'

    let summedList = sort $ cordsToTime cords

    -- A haskell solution, should be fast due to laziness. But I'm not sure if it's.
    print $ (length $ filter (>= 0) $ scanl (\acc x -> acc - x) time summedList) - 1