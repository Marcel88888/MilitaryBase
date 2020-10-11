#ifndef PROJECT1_TEST_H
#define PROJECT1_TEST_H
#include <iostream>
#include "soldier.h"
#include "unit.h"
#include "unitManager.h"

class Test {

    public:

    bool testingSoldier(UnitManager *ptr); // tests the result of searching the best soldier
    bool testingUnit(UnitManager *ptr); // tests the result of searching the best unit
};

#endif //PROJECT1_TEST_H
