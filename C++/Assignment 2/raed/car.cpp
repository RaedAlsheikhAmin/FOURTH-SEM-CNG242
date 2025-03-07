/* Raed Alsheikh Amin – 2528271
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */
#include"Headers.h"

Car::Car():Vehicle()
{
    carTypee=None;
}
Car::Car(int id, char *brand,char *model, char *plateno, int type):Vehicle(id, brand, model,  plateno)
{
    carTypee=type;

}
Car::~Car()
{
    delete []Brand;
    delete []Model;
    delete []plateNo;
}

int Car:: getSeats() {
    if(carTypee==Sedan || carTypee==Hatchback){
        return 5;
    }
    else if(carTypee==Limousine){
        return 6;
    }
    else{
        return 0;
    }
}
int Car::checkSuitability(int numofpeople) {//overridden
    if(getSeats()>=numofpeople)
    {
        return 1;
    }
    return 0;
}

float Car::annualCost(){//overridden
    float KMD;

    cout<<"Enter the kilometres driven: ";
    cin>>KMD;

    return (KMD*10);
}
void Car::printVehicle() {//overridden
    if(carTypee==0)
    {
        return;
    }
    else {
        cout << "Vehicle ID: " << VehicleId <<", Brand: " << Brand <<", Model: " << Model <<", Plate Number: " << plateNo;
        if (carTypee == 1) {
            cout << ", Car Type: Sedan";
        } else if (carTypee == 2) {
            cout << ", Car Type: Hatchback";
        } else if (carTypee == 3) {
            cout << ", Car Type: Limousine";
        }

        cout << "\n";
    }
}

