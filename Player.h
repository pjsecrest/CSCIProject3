#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
    private:
        string name;
        int fullness;
        bool armored;
    public:
        Player(string name_);
        string getName();
        int getFullness();
        void changeFullness(int change_);
        bool isArmored();
        void equipArmor();
};

#endif