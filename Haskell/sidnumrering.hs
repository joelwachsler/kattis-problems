import Data.Map (Map)
import qualified Data.Map as Map

digs :: Integral x => x -> [x]
digs 0 = []
digs x = digs (x `div` 10) ++ [x `mod` 10]

initMap :: Map Int Int
initMap =
  Map.fromList (map makePair [0..9])
    where makePair x = (x, 0)

insertList :: [Int] -> Map Int Int -> Map Int Int
insertList [] dict = dict
insertList (h:t) dict = insertList t $ Map.insertWith' (+) h 1 dict

goThrough :: Int -> Map Int Int -> Map Int Int
goThrough num dict
  | num <= 0  = dict
  | otherwise = goThrough (num - 2) (insertList (digs num) dict)

{- main :: IO () -}
{- main = do -}
  {- let -}
    {- num = 23 -}
  {- if even num -}
    {- then print $ goThrough (num - 1) initMap -}
    {- else print $ goThrough num initMap -}
