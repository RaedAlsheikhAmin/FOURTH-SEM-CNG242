#include<iostream>
using namespace std;

class Cars
{
private:
	char* model;
	int ID;
	static int numberofcars;
public:
	Cars(char*, int);
	Cars(const Cars&);
	~Cars();
	static int getnumberofcars();
	char* getmodel() { return model; }
	int getID() { return ID; }
};

