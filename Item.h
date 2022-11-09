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
        int getprice();
        void setprice(int price_);
};