#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item
{
    protected:
        string name;
        int price;
    public:
        Item();
        Item(string name_, int price_);
        string getName();
        void setName(string name_);
        int getPrice();
        void setPrice(int price_);
};

#endif