import Data.Char
--lab 4 Haskell

func x = x + myfunc where myfunc = 1

func x = let myfunc = 1
		 in x + myfunc
		 
data List = Node Int List | Na deriving(Show)

create [] = Na
create (x:list) = Node x (create (list))



		 
--exercise 1

repli [] number = []
repli (char:string) number = seprint(char) (number)++repli(string) (number)

seprint char 0 = []
seprint char number = [char]++seprint (char) (number-1)

--exercise 2

compress (char:string) = trav (string) (char)

trav [] charr = [charr]
trav (char:string) charr = if charr==char
						   then trav (string) (charr)
						   else [charr]++trav (string) (char)
						   
--exercise 4 (list comprehension)


counter string = length([char | char<-string , decider char])
 
decider char = if Data.Char.ord char > 47 && Data.Char.ord char < 58
			   then True
			   else False

--exercise 4 (recursion)

counter_rec string = counter_rec_help string 0

counter_rec_help [] number = number
counter_rec_help (char:string) number = if decider(char) == True
										then counter_rec_help (string) (number+1)
										else counter_rec_help (string) (number)
										
--exercise 5 

sum_eq 0 = (6)
sum_eq number = (number**2+6)/(2*number+1) + sum_eq (number-1)

sum_eq_alt number = foldr (equation) 0 (lister(number))
equation number base = (number**2+6)/(2*number+1)+base
lister number = [number, (number-1)..0]

--exercise 7

set_intersection list_1 list_2 = [number | number<-list_1, number `elem` list_2]

set_union list_1 list_2 = compress(list_1++list_2)

set_difference list_1 list_2 = [number | number<-list_1, number `nelem` list_2]
nelem number list= if number `elem` list
				   then False
				   else True
				   
set_rest list_1 list_2 = [number | number<-list_1, number `nelem` list_2]++[number | number<-list_2, number `nelem` list_1]



familytree [] = []
familytree (y:(x:list)) = [x]++familytree(list)