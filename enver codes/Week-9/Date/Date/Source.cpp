#include<iostream>
using namespace std;

enum months {Def,Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
class Date {
private:
	int day, year;
	enum months month;
public:
	Date(int dd=0, enum months mm=Def, int yy=0)
	{
		day = dd;
		month = mm;
		year = yy;
	}

	void Dateprint()
	{
		cout << day << "/" << month << "/" << year << endl;
	}
};

int main()
{
	Date d1, d2(2), d3(2, May), d4(2, May, 2023);
	d1.Dateprint();
	d2.Dateprint();
	d3.Dateprint();
	d4.Dateprint();
}