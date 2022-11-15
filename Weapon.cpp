#include "Weapon.h"
using namespace std;

Weapon::Weapon()
{
    name = "";
    damage_bonus = 0;
}

Weapon::Weapon(string name_, int damage_bonus_)
{
    name = name_;
    damage_bonus = damage_bonus_;
}

int Weapon::getDamageBonus()
{
    return damage_bonus;
}

void Weapon::setDamageBonus(int bonus_)
{
    damage_bonus = bonus_;
}