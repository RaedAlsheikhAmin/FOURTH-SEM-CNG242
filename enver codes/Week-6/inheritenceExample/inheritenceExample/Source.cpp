#include"Header.h"

void Shape::setdim(double l, double w)
{
	this->length = l;
	width = w;
}

void Rectangle::calculatearea()
{
	area = width * length;

}

void Cost::setcost(double c)
{
	this->cost = c;
}

void Cost::calculatetotal()
{
	totalcost = cost * area;
}

void Cost::printerf()
{
	cout << "Printing the totalcost\n-------------" << endl;
	cout << "Width:" << width << endl;
	cout << "Length:" << length << endl;
	cout << "Area:" << area << endl;
	cout << "Cost:" << cost << endl;
	cout << "Total Cost:" << totalcost << endl;
}