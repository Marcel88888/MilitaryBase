#ifndef PROJECT1_UNIT_H
#define PROJECT1_UNIT_H
#include <iostream>
#include <vector>
#include "soldier.h"

using namespace std;

enum status
{
    active,
    rest
};

class Unit
{
private:

    Soldier* commander;
    status stat;
    int number;
    double avAge;
    double avHP;
    double avAttack;
    double avDefence;
    vector <Soldier*> sold;

public:

    void uwrite(); // writes out information of a unit
    void write_status(); // writes out enum status of a soldier
    bool addSoldier(Soldier*); // adds a soldier to a vector
    void calculate(); // calculates statistics of a unit
    double best_soldier(); // returns total power of the best soldier of a unit
    double get_power_sum(); // returns total power of a unit
    int get_number(); // getter of number
    int get_size() const; //returns the size of a vector of soldiers
    Soldier* find_best_soldier(); // returns the pointer of the best soldier in a vector of the unit
    explicit Unit(int nr); // constructor
    ~Unit(); // destructor
};
#endif
