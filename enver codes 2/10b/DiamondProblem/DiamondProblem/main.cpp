#include"Header.h"

int main()
{
	Person p1("John Smith", 10);
	Student s1("Alice Cooper", 65, 1111);
	Staff st1("Steve Harris", 60, 666);
	StudentStaff TA("James Hatfield", 55, 1112, 667);
	TA.printer();

	return 0;
}