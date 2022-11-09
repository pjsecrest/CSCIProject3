#include <iostream>
#include "Player.h"
#include "Item.h"
#include <vector>
using namespace std;

class Game
{
    private:
        int rooms_cleared;
        int keys_found;
        int fullness1, fullness2, fullness3, fullness4;
        int ingredients_avail;
        int armor_avail;
        int gold_avail;
        int anger_level;
        vector<Item> weapons;
        vector<Item> cookware;
        vector<Item> treasures;
        int num_total_weapons, num_clubs, num_spears, num_rapiers, num_axes, num_lonswords;
        int num_total_cookware, num_pots, num_pans, num_cauldrons;
        int num_rings, num_necklaces, num_circlets, num_goblets;
        static const int num_party_members = 5;
        Player party[num_party_members];

    public:
        Game();
        int getRoomsCleared();
        void clearRoom();
        int getKeysFound();
        void findKey();
        int getFullness1();
        int getFullness2();
        int getFullness3();
        int getFullness4();
        int getFullness5();
        int getAvailableIngredients();
        void setAvailableIngredients(int ingredients);
        int getAvailableArmor();
        void setAvailableArmor(int armor);
        int getAvailableGold();
        void spendGold(int spent);
        int getAngerLevel();
        void increaseAnger();
        int getNumClubs();
        void setNumClubs(int clubs);
        int getNumSpears();
        void setNumSpears(int spears);
        int getNumRapiers();
        void setNumRapiers(int rapiers);
        int getNumAxes();
        void setNumAxes(int axes);
        int getNumLongswords();
        void setNumLongswords(int swords);
        int getNumPots();
        void setNumPots(int pots);
        int getNumPans();
        void setNumPans(int pans);
        int getNumCauldrons();
        void setNumCauldrons(int cauldrons);
        int getNumRings();
        void setNumRings(int rings);
        int getNumNecklaces();
        void setNumNecklaces(int necklaces);
        int

};