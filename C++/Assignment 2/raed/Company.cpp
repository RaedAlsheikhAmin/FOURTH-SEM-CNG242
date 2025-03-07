/* Raed Alsheikh Amin – 2528271
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */
#include "Headers.h"
Company::Company() {
    Name=new char[30];
    strcpy(Name,"Undefined");
    NumberOfBranches=0;

}
Company::Company(char *name) {
    this->Name= new char[30];
    strcpy(this->Name,name);
    NumberOfBranches=0;
}
Company::~Company()
{
    delete []Name;
}
char *Company::getname() {
    return this->Name;
}

int Company::getnumofbranches() {
    return this->NumberOfBranches;
}
void Company::setname(char *name) {
    strcpy(this->Name,name);
}
void Company::setnumofbranches(int number) {
    this->NumberOfBranches=number;
}
//functions need to be completed after I finish Branch class.

void Company::addBranch() {
    int branchId; char branchSite[30];

    cout<<"Please enter branch's ID: ";
    cin>>branchId;
    cout<<"Please enter the city, where branch is located: ";
    fflush(stdin);
    cin>>branchSite;

    BranchesArray[NumberOfBranches++] = *new Branch(branchId, branchSite);//we use *new because we don't have operator overloading.

}

void Company::printBranches() {
    int i=0;
    for(;i<NumberOfBranches;i++){
        BranchesArray[i].printBranch();
    }
}

void Company::printVehicles() {
    for(int i=0; i<NumberOfBranches;i++){
        BranchesArray[i].printVehicles();
    }
}

void Company::printAnnualCost() {
    float allbranchescost=0;
    float costofbranches=0;
    for(int i=0; i<NumberOfBranches; i++){
        costofbranches = BranchesArray[i].printAnnualCost();
        cout<<"Total Annual Cost for Branch with ID:"<<BranchesArray[i].getId()<<" is "<<costofbranches<<endl;
        allbranchescost += costofbranches;
    }
    cout<<"Total Annual Cost for Quick Transport is "<<allbranchescost<<endl;
}






