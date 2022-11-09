#include <iostream>
using namespace std;

class Player
{
    private:
        string name;
        int fullness;
        bool armored;
    public:
        Player(string name_, int fullness, bool armored);
        string getName();
        float getHealth();
        int getFullness();
        void changeFullness(int change);
        int getArmor();
        void setArmor(bool is_armored);
};