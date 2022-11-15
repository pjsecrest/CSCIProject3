#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include "Item.h"
using namespace std;

class Weapon: public Item
{
    private:
        int damage_bonus;
    public:
        Weapon();
        Weapon(string name_, int damage_bonus_);
        int getDamageBonus();
        void setDamageBonus(int bonus_);
};

#endif