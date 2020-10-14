data Tree t = Leaf
            | Node (Tree t) t (Tree t)

data LCA x = True
            | False
            | Integer

sumTree Leaf = 0
sumTree (Node leftSub v rightSub) = 
    v + sumTree leftSub + sumTree rightSub

isInTree _ Leaf = Prelude.False
isInTree x (Node leftSub v rightSub) =
        x == v || isInTree x leftSub || isInTree x rightSub


-- List Method For Trees
-- https://www.schoolofhaskell.com/user/edwardk/online-lca#lowest-common-ancestor
type Id = Int

data Path = [Id] :# !Int

empty :: Path
empty = [] :# 0

cons :: Id -> Path -> Path
cons a (ys :# n) = (a:ys) :# (n + 1)

lca :: Path -> Path -> Path
lca (xs0 :# i) (ys0 :# j) = go k (drop (i-k) xs0) (drop (j-k) ys0) where
    k = min i j
    go !n xxs@(x:xs) (y:ys)
        | x == y = xxs :# n
        |otherwise = go (n - 1) xs ys

{- lost my train of thought
lcaInTree x y Leaf = False
lcaInTree x y t@(Node leftSub v rightSub)
    | x == v || y == v = t
    | lcaInTree x y leftSub \= False = lcaInTree x y leftSub
    | lcaInTree x y rigd
pathTo x (Node leftSub v rightSub)
    |
-}

{-bad news
isInTree _ Leaf = False
isInTree x (n left v right) = v == x
                || isInTree x left
                || isInTree x right
-}

{-bad news
data ListTree t = []
                | [Integer,[Integer],[Integer]]
-}
