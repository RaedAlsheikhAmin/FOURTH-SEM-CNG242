gcdy(X,X,X).
gcdy(X,Y,R):- X>Y, X1 is X-Y, gcdy(Y,X1,R).
gcdy(X,Y,R):- Y>X, gcdy(Y,X,R).

factori(0,1).
factori(X,R):- X>0, X1 is X-1, factori(X1,R1), R is R1*X.


find_max(X,Y,X):- X>=Y.
find_max(X,Y,Y):- Y>=X.

find_min(X,Y,Y):- X>=Y.
find_min(X,Y,X):- Y>=X.

fibo(0,1).
fibo(1,1).
fibo(X,R):- X>1, X1 is X-1, X2 is X-2, fibo(X1,R1),fibo(X2,R2), R is R1+R2.


count_digits(0, 0).
count_digits(N, Count) :- N > 0, N1 is N // 10, count_digits(N1, Count1),Count is Count1 + 1 . /* YOU CAN USE DIV OR DOUBLE BACK SLASH */


reverse_number(N, Rev) :-
    reverse_number_helper(N, 0, Rev).

reverse_number_helper(0, Acc, Acc).
reverse_number_helper(N, Acc, Rev) :-
    N > 0,
    Digit is N mod 10,
    NewAcc is Acc * 10 + Digit,
    N1 is N div 10,
    reverse_number_helper(N1, NewAcc, Rev).
	
	
power(_, 0, 1).
power(X, N, Result) :-
    N > 0,
    N1 is N - 1,
    power(X, N1, Result1),
    Result is X * Result1.
