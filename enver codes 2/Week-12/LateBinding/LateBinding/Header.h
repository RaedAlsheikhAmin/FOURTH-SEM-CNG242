#include<iostream>
using namespace std;

class A
{
public:
	virtual void get()=0;
};

class B :public A
{
public: void get();
};