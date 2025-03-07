--head : give the first element of the list
--tail : give all the elements in the list except head
--init : give all the elements in the list except last
--last : give last element in the list

--if you create a list of characters, it will be
--converted to a string

--we can concatenate 2 strings with '++' operator

-- if we use @, it means we refer to the entire list
testing_func something@(number:numbers_list) = something

heady (number:numbers) = number --head function by myself
taily (number: numbers) = numbers --tail function by myself

--below is function that takes lists as inputs
func ['1'] = "one"
func [x] = "else"
func [x, y] = "Your list of 2 elems:" ++ [x,y]
func smth = "wtf bro"

--function to find factorial
factorial 0 = 1
factorial n = n*factorial (n-1)


lengthy [] = 0
lengthy (x:xs) = 1 + lengthy xs


sumy [] = 0
sumy (x:y) = x+sumy(y)
sumy x = (head x) + sumy (tail x)
sumy x = if x == []
         then 0
		 else (head x) + sumy (tail x)
		 
		 
--exercise a
--I used predifined body function from exercise b
--in order to get the body of the list
--and then passed this output into summy function
--which bascially calculates the sum of the list
--that it received

sum_body list = sumy (body (list))
summy [] = 0
summy (x:list) = x+sumy(list)

--exercise b
body list = init (tail (list))

--exercise c 
max_in_2 list_1 list_2 = (maximum (list_1), maximum(list_2))

--exercise e
--exists checks whether the item is in the list or no
--find_or_add adds element exists returns false
find_or_add list item = if exists list item == True
						then list
						else item:list
						
exists [] item = False
exists (x:list) item = if item /= x
				   then exists list item
				   else True
				   
--exercise f
get_third (a,b,c) = c

--exercise g
distance (x1, y1) (x2, y2) = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))

--exercise h
salary_finder emp_class reg_hours over_hours = if emp_class == 1
											   then 10*reg_hours
											   else if emp_class == 2 || emp_class == 3
											   then 7*reg_hours + 1.5*7*over_hours
											   else if emp_class == 4
											   then 5*reg_hours + 2*5*over_hours
											   else 0

--exercise i
natural number = [1..number]

--exercise j

power x y = if y == 0
		    then 1
		    else x*power x (y-1)

--exercise k
fx 5 = 1-5
fx 10 = 10 / power 10 2
fx x = x

--exercise m
vowel_count string = length [letter | letter<-string, is_vowel letter]
is_vowel letter = if letter == 'a'
				  then True
				  else if letter == 'e'
				  then True
				  else if letter == 'u'
				  then True
				  else if letter == 'o'
				  then True
				  else if letter == 'i'
				  then True
				  else False
				  
				  
--exercise l
firstXI x index = if x > 1
				  then [helper (index)] ++ firstXI (x-1) (index+1)
				  else [helper (index)]
helper index = cycle(['A'..'Z'])!!index
--exercise n
calculateGPA string credits = calculate_numerator (letter_grades_eval (string)) (credits) / sum (credits)
letter_grades_eval string = [if letter == 'A'
							 then 4
							 else if letter == 'B'
							 then 3
							 else if letter == 'C'
							 then 2
							 else if letter == 'D'
							 then 1
							 else 0| letter<-string]

calculate_numerator [] [] = 0
calculate_numerator (x:eval_grades) (y:credits) =  x*y + calculate_numerator eval_grades credits