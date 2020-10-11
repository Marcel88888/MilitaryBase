#include <iostream>
#include "menu.h"
#include "test.h"
using namespace std;

void Menu::menuOperation() {
    int c;
    UnitManager management;
    cout<<"-----------------MENU-----------------"<<endl<<"--------SOLDIERS MANAGER--------"<<endl<<endl;
    cout<<"What do you want to do?"<<endl;
    cout<<"Press:"<<endl;
    cout<<"1- to create a new unit from file"<<endl;
    cout<<"2- to write units' statistics"<<endl;
    cout<<"3- to present the best soldier"<<endl;
    cout<<"4- to search the best unit"<<endl;
    cout<<"5- to test the result of searching the best soldier of 3 units"<<endl;
    cout<<"6- to test the result of searching the best unit"<<endl;
    cout<<"7- to exit."<<endl<<endl;
    do {
        cout << "Your choice: ";
        cin >> c;
        switch (c) {
            case 1: {
                string file;
                cout << "Type the name of the file containing the unit's data: ";
                cin >> file;
                management.makeUnit(file);
                break;
            }
            case 2: {
                cout<<endl<<"Units informations: "<<endl<<endl;
                management.write();
                break;
            }
            case 3: {
                cout << endl << "THE BEST SOLDIER "<<endl;
                Soldier *best = management.find_best();
                best->swrite();
                break;
            }
            case 4: {
                cout << endl<< "THE BEST UNIT" << endl << endl;
                cout << "Number: " << management.number() << endl;
                cout << "Total power of the best unit: " << management.best_unit() << endl << endl;
                break;
            }
            case 5: {
                Test manager;
                manager.testingSoldier(&management);
                break;
            }
            case 6: {
                Test manager;
                manager.testingUnit(&management);
                break;
            }
            case 7:
                exit(0);
            default: {
                cout << "There is no such a choice. ";
                break;
            }
        }
    } while (c!=7);
}


