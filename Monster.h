#include <iostream>

class Monster
{
    private:
        string name;
        int challenge_rating;
    public:
        Monster(string name_, int challenge_rating_);
        string getName();
        int getRating();
};