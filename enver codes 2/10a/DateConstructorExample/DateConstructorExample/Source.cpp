#include"Header.h"

ostream& operator <<(ostream& os, Date d)
{
	os << d.day << "/" << d.month << "/" << d.year;
	return os;
}

int main()
{
	try {
		Date d1(9, May, 2023);
		cout << d1 << endl;
		//Date d2(29, Feb, 2023);
		Date d3(1, Def, 2020);
	}

	catch (const char* str)
	{
		cout << str << endl;
	}
	return 0;
}