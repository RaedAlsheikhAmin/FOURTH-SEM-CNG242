#include"Header.h"

int main()
{
	Cost c1;
	c1.setdim(3, 5);
	c1.calculatearea();
	c1.setcost(10);
	c1.calculatetotal();
	c1.printerf();

	return 0;
}