/* Raed Alsheikh Amin – 2528271
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */
#include "Headers.h"

Vehicle::Vehicle() {
    VehicleId=-1;
    Brand=new char[20];
    Model=new char[20];
    plateNo=new char[20];
    strcpy(this->Brand,"Undefined");
    strcpy(this->Model,"Undefined");
    strcpy(this->plateNo,"Undefined");

}
Vehicle::Vehicle(int id, char brand[20], char model[20], char plateno[20]) {
    VehicleId=id;
    Brand=new char[20];
    Model=new char[20];
    plateNo=new char[20];
    strcpy(this->Brand,brand);
    strcpy(this->Model,model);
    strcpy(this->plateNo,plateno);

}
Vehicle::~Vehicle() {
    delete []Brand;
    delete []Model;
    delete []plateNo;
}

void Vehicle::setId(int id) {
    this->VehicleId=id;
}

void Vehicle::setBrand(char *brand) {
    this->Brand=brand;
}
void Vehicle::setModel(char *model) {
    this->Model=model;
}
void Vehicle::setPlateNo(char *plateno) {
    this->plateNo=plateno;
}
int Vehicle::getId() {
    return this->VehicleId;
}
char * Vehicle::getBrand() {
    return this->Brand;
}
char * Vehicle::getModel() {
    return this->Model;
}
char * Vehicle::getPlateNo() {
    return this->plateNo;
}


void Vehicle::printVehicle() {//this function to have access to the cars and busses.
}

void Vehicle::printVehicle(int) {//this is for the type that we need to print.
}

int Vehicle::checkSuitability(int) {//to check if we can carry the people.
    return 0;
}

float Vehicle::annualCost() {//overloaded for bus and car.
    return 0.0;
}

