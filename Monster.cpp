#include <iostream>
#include "Monster.h"

Monster::Monster(string name_, int challenge_rating_)
{
    name = name_;
    challenge_rating = challenge_rating_;
}

string Monster::getName()
{
    return name;
}

int Monster::getRating()
{
    return challenge_rating;
}