#include "Player.h"
using namespace std;

Player::Player(string name_)
{
    name = name_;
    fullness = 50;
    armored = false;
    starving = false;
    is_leader = false;
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

bool Player::isStarving()
{
    return starving;
}

void Player::setStarving(bool starve_status_)
{
    starving = starve_status_;
}

void Player::setLeader()
{
    is_leader = true;
}

bool Player::getLeadership()
{
    return is_leader;
}