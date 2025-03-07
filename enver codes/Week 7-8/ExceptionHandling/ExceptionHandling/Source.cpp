#include"Header.h"

int main()
{
	double divident, divisor;
	try {
		
		cout << "Please enter the divident" << endl;
		cin >> divident;
		cout << "Please enter the divisor" << endl;
		cin >> divisor;
		cout << "Result:" << dividefunc(divident, divisor) << endl;;
	}

	catch (const char* str)
	{
		cout << str;
		while (divisor == 0)
		{
			cout << "Please enter the divisor" << endl;
			cin >> divisor;
		}
		cout << "Result:" << dividefunc(divident, divisor) << endl;;


	}

	return 0;
}