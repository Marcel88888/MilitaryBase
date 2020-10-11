#include <iostream>
#include "test.h"

using namespace std;

bool Test::testingSoldier(UnitManager* ptr) {

    Soldier *bes = ptr->find_best();

    if ( bes->get_number() == 1 && bes->get_age() == 30 && bes->get_HP() == 45 && bes->get_attack() == 100 &&
         bes->get_defence() == 100 && bes->get_ranking() == general && bes->get_unit() == 3) {
        cout << "Test of the best soldier is CORRECT" << endl << endl;
        return true;
    } else {
        cout << "Test of the best soldier is INCORRECT" << endl << endl;
        return false;
    }

}

bool Test::testingUnit(UnitManager* ptr) {

    if ( ptr->number() == 2){
        cout << "Test of the best unit is CORRECT" << endl << endl;
        return true;
    }
    else {
        cout << "Test of the best unit is INCORRECT" << endl << endl;
        return false;
    }

}
