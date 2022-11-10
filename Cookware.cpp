#include "Cookware.h"
using namespace std;

Cookware::Cookware(string name_, double break_chance_)
{
    name = name_;
    break_chance = break_chance_;
}

double Cookware::getBreakChance()
{
    return break_chance;
}

void Cookware::setBreakChance(double break_chance_)
{
    break_chance = break_chance_;
}