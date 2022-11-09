#include <iostream>
#include "Item.h"
using namespace std;

class Weapon: public Item
{
    private:
        int damage_bonus;
    public:
        Weapon(string name_, int damage_bonus_);
        int getDamageBonus();
        void setDamageBonus(int bonus_);
};