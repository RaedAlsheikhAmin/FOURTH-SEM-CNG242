#include"Header.h"

Stacky::Stacky(int n)
{
	mystack = new int[n];
	top = 0;
	size = n;
}

void Stacky::push(int n)
{
	if (top == size)
		cout << "Cannor push more stack is full" << endl;
	else
		mystack[top++] = n;
}

int Stacky::pop()
{
	if (top == 0)
	{
		cout << "Empty stack cannot pop" << endl;
		return -1;
	}

	else
		return mystack[--top];
}

int Stacky::peek()
{
	if (top == 0)
	{
		cout << "Empty stack cannot pop" << endl;
		return -1;
	}

	else
		return mystack[top-1];
}

void Stacky::sprint()
{
	cout << "Printing the stack\n----------------------------" << endl;
	for (int i = 0; i < top; i++)
		cout << "Stack[" << i << "]:" << mystack[i] << endl;
}