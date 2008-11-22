import Monad
import Control.Monad.Cont

-- create the computation for calculating the product of a given list
makeComp :: (MonadCont m) => [Integer] -> m Integer
makeComp ls =
    do res <- callCC $ (\esc -> let m t i = do when (i == 0) (esc 0)
			                       return (t * i)
			        in foldM m 1 ls)
       return res

-- infinite list, but the computation will abort on encountering 0
nats :: [Integer]
nats = [0..]

-- result type is String, even though the computation is of type Integer
initK :: Integer -> String
initK = show

-- run the computation
main :: IO ()
main = putStrLn $ (makeComp nats) `runCont` initK
