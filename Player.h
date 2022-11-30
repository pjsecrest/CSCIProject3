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
    bool starving;
    bool is_leader;

public:
    Player(string name_);
    string getName();
    int getFullness();
    void changeFullness(int change_);
    bool isArmored();
    void equipArmor();
    bool isStarving();
    void setStarving(bool starve_status_);
    void setLeader();
    bool getLeadership();
};

#endif