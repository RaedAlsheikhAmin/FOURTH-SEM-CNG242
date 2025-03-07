#include<iostream>
using namespace std;

enum months{Def,Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec};
class Date
{
private:
	int day, year;
	enum months month;
	int leapy(int n) { if (n % 4 == 0) return 1; else return 0; }


public:
	Date(int dd = 1, enum months mm = Def, int yy=1900)
	{
		int maxi;
		if ((yy < 1900) || (yy > 2200)) yy = 1900;
		switch (mm)
		{
		case Feb:maxi = 28 + leapy(yy); break;
		case Apr:case Jun:case Sep: case Nov: maxi = 30; break;
		case Jan:case Mar:case May:case Jul:case Aug:case Oct:case Dec:maxi = 31; break;
		default:throw "Bad month!!";
		}

		if ((dd < 1) || (dd > maxi)) throw "Bad day!!";

		day = dd;
		month = mm;
		year = yy;
	}

	friend ostream& operator<<(ostream&, Date);

};