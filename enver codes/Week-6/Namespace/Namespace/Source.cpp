#include"Header.h"

int main()
{
	double rad;
	std::cout << "Please enter the value of radius" << std::endl;
	std::cin >> rad;
	std::cout << "Area:" << Circle::area(rad) << "\nCircumference:" << Circle::circum(rad) << std::endl;
	std::cout << "Pi:" << Circle::pi << std::endl;

	return 0;
}