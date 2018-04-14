parseInput :: String -> [Int]
parseInput = map read . words

main :: IO ()
main = do
  _ <- getLine
  line <- getLine
  putStrLn $ show $ sum $ parseInput line
