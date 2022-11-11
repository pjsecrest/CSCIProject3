#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Cookware.h"
#include "Monster.h"
#include "Map.h"
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
    vector<string> riddles;
    vector<string> riddle_solutions;
    int num_party_members = 5;
    int num_total_weapons, num_clubs, num_spears, num_rapiers, num_axes, num_longswords;
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
    void setNumGoblets(int goblets);
    int readMonsters(string monster_file_);

    /**
     * algorithm: popuulates the riddle vector with riddles from a file
     * 1. open file stream
     * 2. while there is content to read in the file, add the riddles to the riddles vector, ignoring empty lines
     * 3. add solutions to the riddle_solutions vector
     * 4. increment amount of riddles added
     * 5. return amount of riddles added
     */
    int readRiddles(string riddle_file);

    /**algorithm: adds a player to the party if not full
     * 1. check if party is full, return 0 if true
     * 2. add player to party vector, increment party members
     * 3. return party members
     */
    int addPlayer(Player player_);

    // not sure how we want to do this, will return whether fight is won or not
    /**
     * algorithm: calculate variables for a fight, determine whether it is won or not
     * 1. declare variables for fighting equation: w, d, a, c, r_1, r_2
     * 2. calculate value for w
     * 3. calculate random values for r_1 and r_2, initialize rest of variables
     * 4. calculate outcome
     * 5. if outcome greater than 0, calculate winnings and add to inventory, remove monster from the monsters vector, return true
     * 6. else return false
     */
    bool fight(int monster_challenge, int bonus_1, int bonus_2, int bonus_3, int bonus_4, int bonus_5);

    /**
     * algorithm: investigates a space, determines outcome of investigation
     * 1. check if current space is unexplored, if false, return false
     * 2. else, generate random number, calculate whether player gets a key
     * 3. generate random number, determine whether player finds treasure
     * 4. generate random number, determine whether player has to fight
     * 5. generate random number, determine whether part members' fullness drops by one
     * 6. return true
     */
    bool investigateSpace();

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

    /**
     * algorithm: sorts the scores of previous games into top 10
     * 1. read in scores from external text file, add to a vector, all_scores
     * 2. declare second vector, top, for top 10 scores
     * 3. iterate through all_scores, find max
     * 4. add max value to top, remove from all_scores
     * 5. continue sorting until the top 10 scores have been stored
     */
    void sortScores(string score_file);

    /**
     * algorithm: creates and displays the status update that is displayed each turn
     * 1. initializes variables for game stats: rooms cleared, keys, anger level, gold, ingredients, cookware, weapons, armor, treasures, fullness levels
     * 2. display the menu with updated values
     */
    void displayStatusUpdate();

    /**
     * algorithm: displays the merchant menu with all options available
     * 1. gets player level through function input and multiplies merchant prices accordingly
     * 2. prompts player for input (what items they wish to select on the menu)
     * 3. input validation warns player of invalid inputs
     * 4. uses getters and setters to change gold values and items values based on what is sold and purchased
     */
    void displayMerchantMenu(int level);

    /**
     * algorithm: diplays general NPC menu with interaction options
     * 1. random number generator is used to find a random index in the puzzle array
     * 2. prompts user with random puzzle
     * 3. if answer is correct the npc acts friendly and calls merchant menu function
     * 4. if answer is incorrect a monester is summoned
     * 5. calls fight function
     */
    void displayNPCMenu();
};

#endif