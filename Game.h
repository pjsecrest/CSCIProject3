#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Cookware.h"
#include "Monster.h"
using namespace std;

class Game
{
    private:
        int rooms_cleared;
        int keys_found;
        int ingredients_avail;
        int armor_avail;
        int gold_avail;
        int anger_level;
        int num_monsters;
        vector<Weapon> weapons;
        vector<Cookware> cookware;
        vector<Item> treasures;
        vector<Monster> monsters;
        vector<Player> party;
        int num_party_members = 5;
        int num_total_weapons, num_clubs, num_spears, num_rapiers, num_axes, num_lonswords;
        int num_total_cookware, num_pots, num_pans, num_cauldrons;
        int num_rings, num_necklaces, num_circlets, num_goblets;

    public:
        Game();
        int getRoomsCleared();
        void clearRoom();
        int getKeysFound();
        void findKey();
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
        int getNumCirclets();
        void setNumCirclets(int circlets);
        int getNumGoblets();
        void setNumGoblets();
        int readMonsters(string monster_file_);

        // not sure how we want to do this, will return whether fight is won or not
        bool fight(int monster_challenge, int bonus_1, int bonus_2, int bonus_3, int bonus_4, int bonus_5); 
        void investigateSpace();

        /**
         * 1. prompt player for amount of ingredients to cook (increments of 5 kg)
         * 2. validate input
         * 3. prompt player for type of cookware
         * 4. calculate values for amount of fullness points
         * 5. calculate whether cookware breaks, return false if cookware breaks
         * 6. else, distribute fullness points to players
         * 7. return whether cook successful
        */
        bool cook();

        
};