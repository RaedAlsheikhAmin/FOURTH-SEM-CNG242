/* Raed Alsheikh Amin – 2528271
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */
#include"Headers.h"

Branch::Branch()
{
    numberOfVehicles=0;
    city=new char[30];
    strcpy(city,"Undefined");
    BId=-1;
}
Branch::Branch(int id, char *name) {
    BId=id;
    city=new char[30];
    strcpy(this->city,name);
    numberOfVehicles=0;
}

void Branch::setId(int id) {
    this->BId=id;
}
void Branch::setCity(char *name) {
    this->city=name;
}
void Branch::setNumberOfVehicles(int num) {
    this->numberOfVehicles=num;
}
int Branch::getId() {
    return this->BId;
}
char * Branch::getCity() {
    return this->city;
}
int Branch::getNumberOfVehicles() {
    return this->numberOfVehicles;
}

Branch::~Branch()
{
    delete []city;
}
void Branch::printBranch() {
    cout<<"City: "<<city<<", Number of vehicles: "<<numberOfVehicles<<endl;
}

void Branch::addVehicle() {//function to add a vehicle by given information from the user.
    char VehicleBrand[30], VehicleModel[30], Vehicleplateno[30];
    int vehicletype=-100 , VehicleID;

    while(vehicletype !=0 && vehicletype!=1 && vehicletype!= 2 && vehicletype!=3){
        cout<<"What kind of vehicle would You like to add?\n"<<"Possible options: (0) Bus, (1) Sedan, (2) Hatchback, (3) Limousine\n"<<"Your choice: ";
        fflush(stdin);
        cin>>vehicletype;
        if(vehicletype !=0 && vehicletype!=1 && vehicletype!= 2 && vehicletype!=3){
            cout<<"Please enter a valid vehicle kind"<<endl;
        }
    }

    cout<<"Please enter the ID of the vehicle: ";
    cin>>VehicleID;
    cout<<"Please enter the brand of the vehicle:";
    fflush(stdin);
    cin>>VehicleBrand;
    cout<<"Please enter the model of the vehicle:";
    fflush(stdin);
    cin>>VehicleModel;
    cout<<"Please enter the plate number of the vehicle:";
    fflush(stdin);
    cin>>Vehicleplateno;

    if(vehicletype == 0) {
        int numseats;
        cout << "Please enter the number of seats on the Bus: ";
        cin >> numseats;
        vehiclesArray[numberOfVehicles++] = new Bus(VehicleID, VehicleBrand, VehicleModel, Vehicleplateno,numseats);
    }
    else{
        vehiclesArray[numberOfVehicles++] = new Car(VehicleID, VehicleBrand, VehicleModel, Vehicleplateno, vehicletype);
    }
    cout<<"Vehicle is successfully added!"<<endl<<endl;
}
void Branch::printVehicles() {
    int i=0;
    if(numberOfVehicles!=0){
        cout<<"Vehicles at Branch with ID "<<BId<<":"<<"\n";
    }
    for(; i<numberOfVehicles;i++){
        vehiclesArray[i]->printVehicle();//remember printVehicle is virtual that we can access the children which they are car and bus.
    }
}

float Branch::printAnnualCost() {
    int i=0;
    float fee=0;

    if(numberOfVehicles != 0){
        cout<<"Vehicles at Branch with ID "<<BId<<":"<<endl;
    }
    for(; i<numberOfVehicles; i++){
        cout<<"Vehicle "<<i+1<<":"<<endl;
        fee += vehiclesArray[i]->annualCost();//annualcost is overridden for bus and car.
    }
    return fee;
}

