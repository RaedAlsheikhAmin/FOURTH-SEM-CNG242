module Ration(rat,adder,subtractor,multiplier,divisor) where
data Myration= Rat(Int,Int) deriving Show
mygcd a b=if(b==0) then a else if (a>b) then mygcd b (mod a b) else mygcd b a
simplify(Rat(a,b))=if(b==0) then (Rat(div a b,b))else Rat(div a (mygcd a b),div b (mygcd a b))                        
rat a b= simplify(Rat(a,b))
adder (Rat(a,b))(Rat(c,d))= simplify(Rat(a*d+c*b,b*d))
subtractor(Rat(a,b))(Rat(c,d))= simplify(Rat(a*d-c*b,b*d))
multiplier(Rat(a,b))(Rat(c,d))= simplify(Rat(a*c,b*d))
divisor(Rat(a,b))(Rat(c,d))= simplify(Rat(a*d,c*b))