#include<iostream>
using namespace std;


class A {
private:
	int valA;
	static int numberofclassA;
public:
	A(int a) { valA = a; numberofclassA++; }
	static int getnumberofclassA() { return numberofclassA; }
};

int A::numberofclassA = 0;