#include"Header.h"

int main()
{
	Stacky s1(10);
	cout << "Trying to pop" << s1.pop() << endl;
	for (int i = 0; i < 10; i++)
		s1.push(i * i);
	s1.push(1000);
	s1.sprint();
	//s1.top = 2;
	//Stacky::mystack[Stacky::top];
	Stacky s2(100);
	for (int i = 0; i < 100; i++)
		s2.push(2* i);

	s2.sprint();

	return 0;
}