#include "Player.h"
using namespace std;

Player::Player(string name_)
{
    name = name_;
    fullness = 50;
    armored = false;
}

string Player::getName()
{
    return name;
}

int Player::getFullness()
{
    return fullness;
}

void Player::changeFullness(int change_)
{
    fullness += change_;
}

bool Player::isArmored()
{
    return armored;
}

void Player::equipArmor()
{
    armored = true;
}

