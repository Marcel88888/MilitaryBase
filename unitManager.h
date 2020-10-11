#ifndef PROJECT1_UNITMANAGER_H
#define PROJECT1_UNITMANAGER_H
#include <iostream>
#include <vector>
#include "unit.h"
using namespace std;

class UnitManager
{
private:

    vector <Unit*> units;

public:

    void makeUnit(string); // makes a new unit and adds soldiers
    void write(); // writes out information of all units
    double best_unit(); //returns total power of the best unit
    int number();   // returns the number of the best unit
    Soldier* find_best(); // returns the pointer of the best soldier
    Unit* find_best_unit(); // returns the pointer of the best unit
    ~UnitManager(); // destructor
};

#endif //PROJECT1_UNITMANAGER_H
