myfunction a b= (mod a b)*0.1  
mm1="i am 1 years old"
mm2="i am 2 years old"
mm= "you can't guess"

showmm1 x@(y:ys)= x --shows the enitre list
showmm2 x@(y:ys)= y --shows the first elemest
showmm3 x@(y:ys)= ys --shows all without first element

--a
sumy[]=0
sumy(x:xs)= x+ sumy xs
totala(x:xs)= sumy xs- last(xs)


--b
body(x:xs)= init(xs) -- init shows the lists without the last element

--c

maxytwolist x@(y:ys) n@(l:ls)=maximum(x++n) -- ++ mean concatation the two lists.


--d

maxytwotuple x@(y:ys) n@(l:ls)= (maximum x, maximum n)

--e

checkyitemlist a x@(y:ys) = if a `elem` x then x else a:x

--f

thirditemtuple(x,y,z)= z

--g

distancetwopoints(x1,y1) (x2,y2)=sqrt((x2-x1)**2+(y2-y1)**2)

--h

employeepayment (1,b,c)= 10*b
employeepayment (2,b,c)=7*b+1.5*b*c
employeepayment (3,b,c)=7*b+1.5*b*c
employeepayment (4,b,c)=5*b+2*b*c

--i
natural b=[1..b]

--j

powerfunc (x,0)= 1
powerfunc (x,y)=powerfunc(x,y-1)*x

--k

fx 5= -4
fx 10=0.1
fx x=x


--l

firstXI x index= take x (drop index (cycle['A'..'Z']))--drop helps to drop the first x elements from the list.



--m

vowelcount xs= length ([x | x<-xs, x=='i'|| x=='a'|| x=='e'|| x=='u' || x=='o' ||x=='y'])


--n(gpa calculator)

letterconverter a= case a of
			'A' ->4
			'B' ->3
			'C' ->2
			'D' ->1
			'F' ->0

gpa [] [] =0
gpa (x:xs) (y:ys)= (letterconverter x *y)+gpa xs ys
calculategpa a b=(gpa a b)/sumy b
			


