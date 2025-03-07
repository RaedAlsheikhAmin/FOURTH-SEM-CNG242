#include<iostream>
using namespace std;

class A
{
private:
	int valA;
public:
	A(int n) { valA = n; }
	int getA() { return valA; }
	
};

class B
{
private:
	int valB;
public:
	B(int n) { valB = n; }
	int getB() { return valB; }
};

class C
{
private: 
	A aobj;
	B bobj;
	int valC;
public:
	C(int i,int j,int k):aobj(i),bobj(j){ valC = k; }
	void printC() { cout << "Aobj:" << aobj.getA() << ", Bobj:" << bobj.getB() << ", ValC:" << valC << endl; }
};