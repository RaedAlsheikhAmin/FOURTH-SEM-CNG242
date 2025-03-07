#include<iostream>
using namespace std;

class Pair
{
private:
	char* Name;
	int age;
public:
	Pair();
	Pair(Pair&);
	~Pair();
	void setname(const char*);
	void setage(int);
	int getage()const;
	const int& getage2() { return age; }
	char* getname()const;
	void operator=(Pair);
};