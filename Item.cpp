#include "Item.h"
using namespace std;

Item::Item()
{
    name = "";
    price = 0;
}

Item::Item(string name_, int price_)
{
    name = name_;
    price = price_;
}

string Item::getName()
{
    return name;
}

void Item::setName(string name_)
{
    name = name_;
}

int Item::getPrice()
{
    return price;
}

void Item::setPrice(int price_)
{
    price = price_;
}
