/* Raed Alsheikh Amin – 2528271
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */
#include<iostream>
#include<cstring>



#ifndef Vehicle_h
#define Vehicle_h
class Vehicle{
protected:
    int VehicleId;
    char *Brand;
    char *Model;
    char *plateNo;
public:
    //constructors

    Vehicle();//default constructor to initialize the member values
    Vehicle(int, char*, char*, char*);//constructor to initialize the members by given values.

    //getters and setters to change the member values or return the value of them.

    void setId(int);
    void setBrand(char*);
    void setModel(char*);
    void setPlateNo(char*);

    int getId();
    char* getBrand();
    char* getModel();
    char* getPlateNo();

    //THE FUNCTIONS that we need in the assignment


    virtual void printVehicle();
    virtual void printVehicle(int);
    virtual int checkSuitability(int);
    virtual float annualCost();




    //destructor

    ~Vehicle();


};

#endif


//Bus header


#ifndef BUS_h
#define BUS_h

class Bus : public Vehicle{//because Bus is inherited from Vehicle class, that means will have the same protected member as Vehicle.
private:
    int NumOfseats;
public:
    //constructors


    Bus();
    Bus(int, char*, char*, char*,int);

    //the functions

    int checkSuitability(int) override;
    float annualCost() override;
    void printVehicle() override;



    //destructor


    ~Bus();

};


#endif


//Car header


#ifndef Car_h
#define Car_h

class Car : public Vehicle{
private:
    enum carType {None, Sedan, Hatchback, Limousine};
    int carTypee;
public:

    //constructors


    Car();
    Car(int, char*, char*, char*, int);

    //the functions


    int getSeats();
    int checkSuitability(int) override;
    float annualCost() override;
    void printVehicle() override;


    //destructor

    ~Car();

};

#endif// Car_h

#ifndef BRANCHE_H
#define BRANCHE_H

class Branch
{
private:
    int BId;
    char *city;
    Vehicle *vehiclesArray[30]; //need to be completed later(aggregation)
    int numberOfVehicles;
public:
    //constructors

    Branch();
    Branch(int,char*);

    //getters and setters

    void setId(int);
    void setCity(char*);
    void setNumberOfVehicles(int);
    int getId();
    char* getCity();
    int getNumberOfVehicles();

    //the functions

    void addVehicle();
    void printBranch();
    void printVehicles();
    void printVehiclesByType(int);
    void printTypeStatistics();
    void printVehiclesBySeat(int);
    float printAnnualCost();

    //destructor

    ~Branch();

};


#endif //BRANCHE_H

#ifndef COMPANY_H
#define COMPANY_H
using namespace std;


class Company{
private://members
    char *Name;
    Branch BranchesArray[10];//composition.
    int NumberOfBranches;
public:
    //constructors

    Company();
    Company(char*);
    ~Company();
    //geters and setters

    char* getname();
    int getnumofbranches();

    void setname(char *);
    void setnumofbranches(int);

    void addBranch();
    void printBranches();
    void printVehicles();
    void printVehiclesByType();
    void printTypeStatistics();
    void printVehiclesBySeat();
    void printAnnualCost();

};


#endif //COMPANY_H



