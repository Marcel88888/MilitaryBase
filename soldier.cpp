#include <iostream>
#include "soldier.h"
using namespace std;

//constructor
Soldier::Soldier(int n, int ag, int hp, int att, int def, int rank, int un)
{
    nr = n;
    age = ag;
    HP = hp;
    attack = att;
    defence = def;
    switch(rank)
    {
        case 0:
            ranking = priv;
            break;
        case 1:
            ranking = major;
            break;
        case 2:
            ranking = general;
            break;
        default:
            break;
    }
    alive = true;
    unit = un;
}

void Soldier::swrite()
{
    cout<< "Soldier informations: "<< endl<< endl;
    cout<< "Number: "<<nr<< endl;
    cout<< "Age: "<<age<< endl;
    cout << "HP: "<<HP<< endl;
    cout << "Attack: "<<attack << endl;
    cout << "Defence: " << defence << endl;
    cout << "Rank: " ;
    if (ranking == priv)
        cout << "private" << endl;
    else if (ranking == major)
        cout << "major" << endl;
    else cout << "general" << endl;
    cout << "Unit: " << unit<< endl;
    cout << "Alive: " << alive<< endl << endl;
}

double Soldier::get_power() const
{
    return 1.0 * (attack + defence) / 2;
}

int Soldier::get_number() const {
    return nr;
}
int Soldier::get_age() const
{
    return age;
}
int Soldier::get_HP() const
{
    return HP;
}
int Soldier::get_attack() const
{
    return attack;
}
int Soldier::get_defence() const
{
    return defence;
}
int Soldier::get_unit() const
{
    return unit;
}
ran Soldier::get_ranking() const
{
    return ranking;
}