#include <iostream>
#include "unit.h"
using namespace std;

bool Unit::addSoldier(Soldier* soldier)
{
    if(soldier == nullptr)
        return false;
    sold.push_back(soldier);
    return true;
}

void Unit::calculate()
{
    int sum_age = 0;
    int sum_hp = 0;
    int sum_attack = 0;
    int sum_defence = 0;

    for(unsigned i = 0; i < sold.size(); ++i)
    {
        sum_age += sold[i]->get_age();
        sum_hp += sold[i]->get_HP();
        sum_attack += sold[i]->get_attack();
        sum_defence += sold[i]->get_defence();
    }
    avAge = 1.0 * sum_age / sold.size();
    avHP = 1.0 * sum_hp / sold.size();
    avAttack = 1.0 * sum_attack / sold.size();
    avDefence = 1.0 * sum_defence / sold.size();

    commander = sold[0];
}


void Unit::write_status()
{
    if(stat == active)
        cout << "Status: active" << endl;
    else
        cout << "Status: rest" << endl;
}

Soldier* Unit::find_best_soldier()
{
    double result = 0;
    unsigned index = 0;
    for(unsigned i = 0; i < sold.size(); ++i)
        if(result < sold[i]->get_power())
        {
            index = i;
            result = sold[i]->get_power();
        }
    return sold[index];
}

double Unit::best_soldier()
{
    Soldier* wsk = find_best_soldier();
    return wsk->get_power();
}

void Unit::uwrite()
{
    cout <<"Number: "<<number<<endl;
    write_status();
    cout<<"Average age: "<<avAge<<endl;
    cout <<"Average HP: "<<avHP<<endl;
    cout <<"Average attack: "<<avAttack << endl;
    cout << "Average defence: "<<avDefence<<endl<<endl;
}

double Unit::get_power_sum()
{
    double sum = 0;
    for(unsigned i = 0; i < sold.size(); ++i)
        sum += sold[i]->get_power();
    return sum;
}

int Unit::get_number(){
    return number;
}

int Unit::get_size() const
{
    return sold.size();
}

Unit::Unit(int nr) //constructor
{
    commander = nullptr;
    stat = active;
    number = nr;
    avAge = avHP = avAttack = avDefence = 0;
}

Unit::~Unit()
{
    for(unsigned i = 0; i < sold.size(); ++i)
        delete sold[i];
}


