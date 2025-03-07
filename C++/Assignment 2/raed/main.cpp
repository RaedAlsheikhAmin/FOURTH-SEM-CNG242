/* Raed Alsheikh Amin – 2528271
I read and accept the submission rules and the extra rules specified in
each question. This is my own work that is done by myself only */

#include "Headers.h"


int main() {

    Company c1 = Company();

    cout << "Welcome to Quick Transports" << "\n" << "\n";
    int choice = 0;
    while (choice != 9) {//creating a menu
        cout << "Options:"<<endl << "1. Add a new branch to the company."<<endl;
        cout<< "2. Add a new vehicle (car or bus) to a branch.\n";
        cout<<"3. Print all the branches along with their cities and the number of vehicles.\n";
        cout<< "4. Print the details stored as member variables for the vehicles in each branch."<<endl;
        cout<< endl<<"5. Print the details stored as member variables for the vehicles in each branch\nwhose type is a given type.\n";
        cout<< "6. Print the number of each type of vehicle in each branch.\n";
        cout << "7. Print the details stored as member variables for the vehicles that can carry a\n";
        cout<<"given number of people in each branch.\n" << "8. Calculate the total annual cost for the company.\n";
        cout<< "9. Exit\n";
        cout<<"Your selection: ";
        cin >> choice;

        if(choice==1){
            c1.addBranch();
        }
        else if(choice==3)
        {
            c1.printBranches();
        }
        else if(choice==4)
        {
            c1.printVehicles();
        }
        else if(choice==8)
        {
            c1.printAnnualCost();
        }
        else if(choice==9)
            cout<<"Good Bye!";
    }

        return 0;

}