#include"Header.h"

void Carprint(Cars c)
{
	cout <<"ID:"<<c.getID()<< ", Model: " << c.getmodel() << endl;
}

int main()
{
	Cars c1("Audi A7", 1111), c2("Mercedes C180",1112),c3("Volkswagen",1113);
	Cars c4 = c2;
	Carprint(c1);
	Carprint(c2);
	Carprint(c3);
	Carprint(c4);

	cout <<"The number of cars:"<< Cars::getnumberofcars() << endl;

	return 0;
}