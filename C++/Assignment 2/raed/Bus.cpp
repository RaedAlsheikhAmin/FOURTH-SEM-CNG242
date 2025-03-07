/* Raed Alsheikh Amin – 2528271
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */
#include"Headers.h"

Bus::Bus():Vehicle(){
    NumOfseats=0;
}
Bus::Bus(int id, char *brand,char *model, char *plateno, int NUMOFSEATS):Vehicle(id, brand, model,  plateno){

    this->NumOfseats=NUMOFSEATS;
}
Bus::~Bus(){
    delete [] plateNo;
    delete [] Model;
    delete [] Brand;
}
int Bus::checkSuitability(int seats){//overriden
    if(NumOfseats>=seats){
        return 1;
    }
    return 0;
}

float Bus::annualCost(){//overriden
    int Numoftimeserviced; float maintenance_cost;

    cout<<"Enter the maintenance cost: ";
    cin>>maintenance_cost;
    cout<<"Enter the number of times bus has been serviced: ";
    cin>>Numoftimeserviced;

    return (maintenance_cost*Numoftimeserviced);
}

void Bus::printVehicle() {//overriden
    cout<<"Vehicle ID: "<<VehicleId<<
        ", Brand: "<<Brand<<
        ", Model: "<<Model<<
        ", Plate Number: "<<plateNo<<
        ", Car Type: Bus"<<
        ", Number of Seats: "<<NumOfseats;

    cout<<endl;
}
