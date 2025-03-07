--lab 3 cng242--

func x = if x > 5
		 then "5"
		 else "else"
		 
--Integral means numeric value--
--Floating means float value--
--fromIntegral coverts any numeric type
--to integral type

--below is the datatype that is either of values
--deriving show in order to be able to print

data SchoolMember = Student [Char] [Char] Int |
	Teacher [Char] [Char] [Char] deriving(Show, Eq, Ord)
	
--if you include Eq to deriving, you can equalize (==)
--the elements of your data type

--if you include Ord to deriving, you can compare (>, <)
--the elements of your data type

--read function takes an input and turns the data type
--to the correct one

data Decisison = Yes | No | Maybe deriving(Show, Eq, Ord)

decide x = if x == "bad job"
		   then Yes
		   else if x == "so so"
		   then Maybe
		   else No
		   
data Boolean = T | F deriving(Show, Eq, Ord, Read)
torn x = if x == "yes"
		 then No
		 else Yes
		 
ask_q x = if x == 1
		then Yes
		else if x == 2
		then No
		else Maybe
		
react Yes = "Nice!"
react No = "Why?"
react Maybe = "To what?"

--data Tree = EmptyTree | Node Int Tree Tree deriving(Show, Ord, Eq)

--tree_func = (Node 5 (Node 2 (Node 1 (EmptyTree) (EmptyTree)) (EmptyTree)) (Node 7 (EmptyTree) (EmptyTree)))

--search EmptyTree number = False
--search (Node x l r) num = if num == x
	--					  then True
		--				  else if num < x
			--			  then search l num
				--		  else search r num
						  
						  
						  
--exercise 1, 2

data ThreeDShapes number = Cube number| Cylinder number number deriving(Show, Eq, Ord)
volume (Cube side) = side**3
volume (Cylinder height radius) = 3.14*(radius**2)*height

--exercise 3

data Tree = EmptyTree | Node Integer Tree Tree deriving (Show, Eq, Ord)
insertElement x EmptyTree = Node x EmptyTree EmptyTree -- BASE CASE
insertElement x (Node a left right) = if x == a -- DO NOTHING
									  then (Node x left right)
									  else if x < a -- INSERT TO LEFT
									  then (Node a (insertElement x left) right)
									  else -- INSERT TO RIGHT
									  Node a left (insertElement x right)

inserter [] = EmptyTree
inserter (x:list) = insertElement x (inserter list)

--exercise 4

my_tree = Node 4 (Node 2 EmptyTree (Node 3 EmptyTree EmptyTree)) EmptyTree
t = EmptyTree

minOf (Node a left right) = minimum (make_list(Node a left right))
make_list EmptyTree = []
make_list (Node a left right) = [a] ++ make_list (left) ++ make_list (right)

--exercise 5

isEmpty tree = if length(make_list(tree)) == 0
							  then True
							  else False
							  
--exercise 6

search x tree = elem x (make_list(tree))