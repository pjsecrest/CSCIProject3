#include <iostream>
#include <fstream>
#include <vector>
#include "Game.h"
#include "Monster.h"

using namespace std;

/**
 * algorithm: splits it at every occurrence of a desired character, populates an array of strings with the split pieces, up to the provided maximum number of pieces, and return nubmer of pieces
 * 1. initialize int for num_elements = 1
 * 2. if input_string length is 0, return 0
 * 3. else for every index i in input_string:
 *  a. if input_string[i] == separator, increment num_elements
 * 4. if num_elements is 1 and arr_size is greater than 0, arr[0] = input_string and return num_elements
 * 5. else if num_elements > arr_size
 *  a. declare string temp, temp_index, arr_index
 *  b. for every index i in input_string, check if input_string[i] equals our deliminator
 *   i. if true, temp = temp = input_string.substr(temp_index, i - temp_index)
 *   ii. arr[arr_index] = temp
 *   iii. arr_index++ and temp_index = i + 1
 *   iv. return -1 once arr_index == arr_size
 *  c. else if num_elements > 1 && arr_size >= num_elements
 *   i. populate arr using algorithm given in (5),
 *   ii. once (arr_index + 1) == num_elements, set remaining substr of input_string as value for arr[arr_index]
 * 6. return num_elements
 */
int split(string input_string, char separator, string arr[], int arr_size)
{
    int num_elements = 1;
    if (input_string.length() == 0)
    {
        return 0;
    }
    // calculate the total number of elements there will be in arr
    for (int i = 0, max = input_string.length(); i < max; i++)
    {
        if (input_string[i] == separator)
        {
            num_elements++;
        }
    }
    // if there is only one element and there is space in arr, input the string into arr
    if (num_elements == 1 && arr_size > 0)
    {
        arr[0] = input_string;
        return num_elements;
    }
    // if the number of elements is greater than arr_size, input as many values into arr as possible
    else if (num_elements > arr_size)
    {
        string temp;
        int temp_index = 0;
        int arr_index = 0;
        for (int i = 0, max = input_string.length(); i < max; i++)
        {
            if (input_string[i] == separator)
            {
                // temp stores the element before the deliminator
                temp = input_string.substr(temp_index, i - temp_index);
                arr[arr_index] = temp; // temp stored into arr
                arr_index++;           // index of our array is incremented so that we move to next element in arr
                temp_index = i + 1;    // temp index set to i + 1 so we do not include deliminator in future elemtents
            }
            if (arr_index == arr_size) // return -1 once we run out of space in arr
            {
                return -1;
            }
        }
    }
    // if there is space for all the elements in arr, stores using same algorithm as above
    else if (num_elements > 1 && arr_size >= num_elements)
    {
        string temp;
        int temp_index = 0;
        int arr_index = 0;

        for (int i = 0, max = input_string.length(); i < max; i++)
        {
            if (input_string[i] == separator)
            {
                temp = input_string.substr(temp_index, i - temp_index);
                arr[arr_index] = temp;
                arr_index++;
                temp_index = i + 1;
            }
            // once we get to the final element, stores it into arr
            if ((arr_index + 1) == num_elements)
            {
                temp = input_string.substr(temp_index, input_string.length() - temp_index);
                arr[arr_index] = temp;
            }
        }
    }
    return num_elements;
}

Game::Game()
{
    rooms_cleared = 0;
    keys_found = 0;
    ingredients_avail = 0;
    armor_avail = 0;
    gold_avail = 100;
    anger_level = 0;
    num_total_weapons, num_clubs, num_spears, num_rapiers, num_axes, num_longswords, num_total_cookware, num_pots, num_pans, num_cauldrons, num_rings, num_necklaces, num_circlets, num_goblets = 0;
}

int Game::getRoomsCleared()
{
    return rooms_cleared;
}

void Game::clearRoom()
{
    rooms_cleared++;
}

int Game::getKeysFound()
{
    return keys_found;
}

void Game::findKey()
{
    keys_found++;
}

int Game::getAvailableIngredients()
{
    return ingredients_avail;
}

void Game::setAvailableIngredients(int ingredients)
{
    ingredients_avail = ingredients;
}

int Game::getAvailableArmor()
{
    return armor_avail;
}

void Game::setAvailableArmor(int armor)
{
    armor_avail = armor;
}

int Game::getAvailableGold()
{
    return gold_avail;
}

void Game::spendGold(int spend)
{
    gold_avail = gold_avail - spend;
}

int Game::getAngerLevel()
{
    return anger_level;
}

void Game::increaseAnger()
{
    anger_level++;
}

int Game::getNumClubs()
{
    return num_clubs;
}

void Game::setNumClubs(int clubs)
{
    num_clubs = clubs;
}

int Game::getNumSpears()
{
    return num_spears;
}

void Game::setNumSpears(int spears)
{
    num_spears = spears;
}

int Game::getNumRapiers()
{
    return num_rapiers;
}

void Game::setNumRapiers(int rapiers)
{
    num_rapiers = rapiers;
}

int Game::getNumAxes()
{
    return num_axes;
}

void Game::setNumAxes(int axes)
{
    num_axes = axes;
}

int Game::getNumLongswords()
{
    return num_longswords;
}

void Game::setNumLongswords(int swords)
{
    num_longswords = swords;
}

int Game::getNumPots()
{
    return num_pots;
}

void Game::setNumPots(int pots)
{
    num_pots = pots;
}

int Game::getNumPans()
{
    return num_pans;
}

void Game::setNumPans(int pans)
{
    num_pans = pans;
}

int Game::getNumCauldrons()
{
    return num_cauldrons;
}

void Game::setNumCauldrons(int cauldrons)
{
    num_cauldrons = cauldrons;
}

int Game::getNumRings()
{
    return num_rings;
}

void Game::setNumRings(int rings)
{
    num_rings = rings;
}

int Game::getNumNecklaces()
{
    return num_necklaces;
}

void Game::setNumNecklaces(int necklaces)
{
    num_necklaces = necklaces;
}

int Game::getNumCirclets()
{
    return num_circlets;
}

void Game::setNumCirclets(int circlets)
{
    num_circlets = circlets;
}

int Game::getNumGoblets()
{
    return num_goblets;
}

void Game::setNumGoblets(int goblets)
{
    num_goblets = goblets;
}

// TODO rest of getters/setters, other functions

int Game::readMonsters(string monster_file)
{
    ifstream fin(monster_file);
    string line;
    string elements[2];

    while (!fin.eof())
    {
        getline(fin, line);
        if (line != "")
        {
            int split_return = split(line, ',', elements, 2);
            Monster temp_monster(elements[0], stoi(elements[1]));
            monsters.push_back(temp_monster);
            num_monsters++;
        }
    }
    return num_monsters;
}
/**algorithm: adds a player to the party if not full
 * 1. check if party is full, return 0 if true
 * 2. add player to party vector, increment party members
 * 3. return party members
 *
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
bool Game::fight(int monster_challenge, int bonus_1, int bonus_2, int bonus_3, int bonus_4, int bonus_5)
{
    bool fight_result;
    return fight_result;
}

/**
 * algorithm: investigates a space, determines outcome of investigation
 * 1. check if current space is unexplored, if false, return false
 * 2. else, generate random number, calculate whether player gets a key
 * 3. generate random number, determine whether player finds treasure
 * 4. generate random number, determine whether player has to fight
 * 5. generate random number, determine whether part members' fullness drops by one
 * 6. return true
 */
bool Game::investigateSpace()
{
    bool investigated;
    return investigated;
}

/**
 * 1. prompt player for amount of ingredients to cook (increments of 5 kg)
 * 2. validate input
 * 3. prompt player for type of cookware
 * 4. calculate values for amount of fullness points
 * 5. calculate whether cookware breaks, return false if cookware breaks
 * 6. else, distribute fullness points to players
 * 7. return whether cook successful
 */
bool Game::cook()
{
    bool cook_successful;
    return cook_successful;
}

/**
 * algorithm: sorts the scores of previous games into top 10
 * 1. read in scores from external text file, add to a vector, all_scores
 * 2. declare second vector, top, for top 10 scores
 * 3. iterate through all_scores, find max
 * 4. add max value to top, remove from all_scores
 * 5. continue sorting until the top 10 scores have been stored
 */
void Game::sortScores(string score_file)
{
}

/**
 * algorithm: creates and displays the status update that is displayed each turn
 * 1. initializes variables for game stats: rooms cleared, keys, anger level, gold, ingredients, cookware, weapons, armor, treasures, fullness levels
 * 2. display the menu with updated values
 */
void Game::displayStatusUpdate()
{
}

/**
 * algorithm: displays the merchant menu with
 */
void Game::displayMerchantMenu(int level)
{
}

/**
 * algorithm: diplays general NPC menu with interaction options
 */
void Game::displayNPCMenu()
{

}
