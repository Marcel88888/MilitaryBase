#include <iostream>
#include <fstream>
#include "unit.h"
#include "unitManager.h"
using namespace std;

void UnitManager::makeUnit(string fl)
{
    ifstream file;
    file.open(fl.c_str());
    if(file.good())
    {
        Soldier* wsk;
        int ag, hp, att, def, rank, nr;
        file >> nr;
        if (nr<0){
            cout<<"Incorrect data"<<endl;
            return;
        }
        Unit* base = new Unit(nr);
        while(!file.eof())
        {
            file >> ag >> hp >> att >> def >> rank;
            if ( ag < 0 || hp < 0 || hp > 100 || att < 0 || att > 100 || def < 0 || def > 100 || ( rank!=0 && rank!=1 && rank!=2) ) {
                cout << "Incorrect data" << endl;
                return;
            }
            wsk = new Soldier(base->get_size() + 1, ag, hp, att, def, rank, nr);
            if(!base->addSoldier(wsk))
            {
                cout << "Error loading" << endl;
                return;
            }
        }
        file.close();
        base->calculate();
        units.push_back(base);
        return;
    }
    else
    {
        cout << "Program failed to open the file" << endl;
        return;
    }
}


void UnitManager::write()
{
    for(unsigned i = 0; i < units.size(); ++i)
        units[i]->uwrite();
}

Soldier* UnitManager::find_best()
{
    double res = 0;
    Soldier* best = nullptr;

    for(unsigned i = 0; i < units.size(); ++i)
    {
        if(units[i]->best_soldier() > res)
        {
            res = units[i]->best_soldier();
            best = units[i]->find_best_soldier();
        }
    }
    return best;
}


Unit* UnitManager::find_best_unit()
{
    double res = 0;
    Unit* best = nullptr;
    for(unsigned i = 0; i < units.size(); ++i)
        if(units[i]->get_power_sum() > res)
        {
            res = units[i]->get_power_sum();
            best = units[i];
        }
    return best;
}

double UnitManager::best_unit()
{
    Unit* best = find_best_unit();
    return best->get_power_sum();
}

int UnitManager::number() {
    Unit* best = find_best_unit();
    return best->get_number();
}

//destructor
UnitManager::~UnitManager()
{
    for(unsigned i = 0; i < units.size(); ++i)
        delete units[i];
}
