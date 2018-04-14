parseInput :: String -> [Int]
parseInput = map read . words

modList :: [Int] -> [Int]
modList [] = []
modList (x:xs)
  | x > 7     = 7:modList xs
  | otherwise = x:modList xs

main :: IO ()
main = do
  _ <- getLine
  line <- getLine
  putStrLn $ show $ sum $ zipWith (-) (modList $ parseInput line) (cycle [2,3])
