#include<iostream>
using namespace std;

class Shape {
protected:
	double width, length;
public:
	void setdim(double, double);
};

class Rectangle:public Shape
{
protected:
	double area;
public:
	void calculatearea();
};

class Cost :public Rectangle
{
private:
	double cost;
	double totalcost;
public:
	void setcost(double);
	void calculatetotal();
	void printerf();
};