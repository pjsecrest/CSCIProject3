#ifndef COOKWARE_H
#define COOKWARE_H

#include <iostream>
#include "Item.h"
using namespace std;

class Cookware: public Item
{
    private:
        double break_chance;
    public:
        Cookware(string name_, double break_chance_);
        double getBreakChance();
        void setBreakChance(double break_chance_);
};

#endif