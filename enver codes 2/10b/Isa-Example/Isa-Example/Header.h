#include<iostream>
using namespace std;

class A
{
protected:
	int valA;
public:
	A(int n) { this->valA = n; }
	~A() { cout << "Destroy A" << endl; }
};

class B :public A
{
protected:
	int valB;
public:
	B(int n,int m):A(n) { this->valB = m; }
	~B() { cout << "Destroy B" << endl; }
};

class C :public B
{
protected:
	int valC;
public:
	C(int n, int m, int k):B(n,m) { this->valC = k; }
	void printer()
	{
		cout << "ValA:" << this->valA << ", ValB:" << this->valB << ", ValC:" << this->valC << endl;
	}

	~C() { cout << "Destroy C" << endl; }
};