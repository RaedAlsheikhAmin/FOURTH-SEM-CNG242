#include<iostream>
using namespace std;

int main()
{
	int myarray[3] = { 1,2,3 };
	const int* ptr1 = myarray;
	int* const ptr2 = myarray;

	for (int i = 0; i < 3; i++)
	{
		cout << "Array[" << i << "]:" << *ptr1 << endl;
		ptr1++;
		//ptr1[i] = i * i;
	}
	cout << "\n---------------------" << endl;
	for (int i = 0; i < 3; i++)
	{
		ptr2[i] = i * i;
		cout << "Array[" << i << "]:" << *(ptr2+i) << endl;
		//ptr2++;
	}


	return 0;
}