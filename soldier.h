#ifndef PROJECT1_SOLDIER_H
#define PROJECT1_SOLDIER_H
#include <iostream>
using namespace std;

enum ran
{
    priv,
    major,
    general
};

class Soldier
{
private:

    int nr;
    int age;
    int HP;
    int attack;
    int defence;
    ran ranking;
    int unit;
    bool alive;

public:

    void swrite(); //writes out information of a soldier
    double get_power() const; //calculates power of a soldier
    int get_number() const; // getter of number
    int get_age() const; // getter of age
    int get_HP() const; // getter of HP
    int get_attack() const; // getter of attack
    int get_defence() const; //getter of defence
    int get_unit() const; // getter of number of unit
    ran get_ranking() const; // getter of rank
    Soldier(int n, int ag, int hp, int att, int def, int rank, int un); //constructor

};
#endif
