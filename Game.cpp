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
    party.clear();
    cookware.clear();
    treasures.clear();
    monsters.clear();
    weapons.clear();
    riddles.clear();
    riddle_solutions.clear();

    rooms_cleared = 0;
    keys_found = 0;
    ingredients_avail = 0;
    armor_avail = 0;
    gold_avail = 100;
    anger_level = 0;
    num_total_weapons = 0;
    num_clubs = 0;
    num_spears = 0;
    num_rapiers = 0;
    num_axes = 0;
    num_longswords = 0;
    num_total_cookware = 0;
    num_pots = 0;
    num_pans = 0;
    num_cauldrons = 0;
    num_rings = 0;
    num_necklaces = 0;
    num_bracelets = 0;
    num_circlets = 0;
    num_goblets = 0;
    num_party_members = 0;
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

int Game::getNumPartyMembers()
{
    return num_party_members;
}

Player Game::getCurrentPartyMember(int index)
{
    return party.at(index);
}

int Game::killPartyMember()
{
    if (num_party_members > 0)
    {
        num_party_members--;
        if (party.at(party.size() - 1).isArmored())
        {
            armor_avail--;
        }
        party.erase(party.begin() + party.size() - 1);
        weapons.erase(weapons.begin() + party.size() - 1);
        return num_party_members;
    }
    return num_party_members;
}

// TODO rest of getters/setters, other functions

int Game::readMonsters(string monster_file)
{
    ifstream fin(monster_file);
    string line;
    string elements[2];

    if (fin.fail())
    {
        return -1;
    }

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
 * 1. check if party is full, return -1 if true
 * 2. add player to party vector, increment party members
 * 3. return party members
 *
 */
int Game::addPlayer(Player player_)
{
    if (party.size() == 5)
    {
        return -1;
    }
    else
    {
        party.push_back(player_);
        num_party_members++;
    }

    return num_party_members;
}

/**
 * algorithm: adds a weapon to the weapons vector, sorts the vector in order of damage bonus
 */
int Game::addWeapon(Weapon weapon_)
{
    if (weapons.size() == num_party_members) // weapons vector "full", every party member has a weapon
    {
        for (int i = 0; i < weapons.size(); i++)
        {
            if (weapons.at(i).getDamageBonus() < weapon_.getDamageBonus())
            {
                weapons.at(i) = weapon_;
                num_total_weapons++;
            }
            else if (i == 5)
            {
                weapons.at(i) = weapon_;
                num_total_weapons++;
            }
        }
    }
    else
    {
        weapons.push_back(weapon_);
        num_total_weapons++;
    }

    // sort weapons in descending order of damage bonus
    for (int i = 0; i < num_total_weapons - 1; i++)
    {
        if (weapons.at(i).getDamageBonus() < weapons.at(i + 1).getDamageBonus())
        {
            Weapon temp_weapon = weapons.at(i);
            weapons.at(i) = weapons.at(i + 1);
            weapons.at(i + 1) = temp_weapon;
        }
    }

    return num_total_weapons;
}

Monster Game::pickMonster()
{
    srand((unsigned)time(NULL));
    int random = rand() % monsters.size();
    Monster chosen = monsters.at(random);
    return chosen;
}

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
double Game::fight(Monster monster_)
{
    // TODO test function
    int w = weapons.size();
    int temp_bonus;
    bool different_weapons = true;
    int d = 4;
    int c = monster_.getRating();
    int rand1, rand2;
    double outcome;

    for (int i = 0; i < weapons.size(); i++)
    {
        Weapon current_weapon = weapons.at(i);
        w += current_weapon.getDamageBonus();
        if (i > 0)
        {
            if (current_weapon.getDamageBonus() == weapons.at(i - 1).getDamageBonus())
            {
                different_weapons = false;
            }
        }
    }

    // set value for d
    if (!different_weapons)
    {
        d = 0;
    }

    // random number generation, two numbers 1 - 6
    srand((unsigned)time(NULL));
    rand1 = rand() % 6 + 1;
    rand2 = rand() % 6 + 1;

    outcome = double((rand1 * w + d));
    outcome -= (double((rand2 * c)) / armor_avail);

    if (outcome > 0)
    {
        // remove monster from monsters vector so that it can't be fought again
        for (int i = 0; i < monsters.size(); i++)
        {
            if (monster_.getName() == monsters.at(i).getName())
            {
                monsters.erase(monsters.begin() + i);
                num_monsters--;
                break; // NOTE TO SELF, REMOVE AFTER TESTING FIGHT()
                /**
                 * only needed when removing monsters from monsters.txt when we have multiple of the same,
                 * in future: chagne monsters.txt so there are no repeats
                 */
            }
        }
        // calculating reward
        int key_chance = rand() % 100;
        int gold_reward = 10 * c;
        int ingredient_reward = 5 * c;
        if (key_chance >= 0 && key_chance <= 10)
        {
            findKey();
            cout << "You won the fight and found a key! Your rewards are " << gold_reward << " gold, " << ingredient_reward << " kg of ingredients, and one key." << endl;
        }
        else
        {
            cout << "You won the fight! Your rewards are " << gold_reward << " gold and " << ingredient_reward << " kg of ingredients." << endl;
        }
    }
    else
    {
        // calculate whether party members die or not
        int num_dead = 0;
        for (int i = 0; i < num_party_members; i++)
        {
            int death_chance = rand() % 100 + 1;
            Player current = party.at(i);
            if (current.isArmored())
            {
                if (death_chance > 0 && death_chance <= 5)
                {
                    killPartyMember();
                    num_dead++;
                }
            }
            else
            {
                if (death_chance > 0 && death_chance <= 10)
                {
                    killPartyMember();
                    num_dead++;
                }
            }
        }
        cout << "You lost the fight. " << num_dead << " party members died" << endl;
    }
    for (int i = 0; i < num_party_members; i++)
    {
        int fullness_chance = rand() % 100 + 1;
        if (fullness_chance >= 1 && fullness_chance <= 50)
        {
            party.at(i).changeFullness(-1);
            cout << "Party member's fullness was decreased by 1." << endl;
        }
    }
    // return fight_won;
    return outcome;
}

void Game::surrender()
{
    int party_member = rand() % num_party_members + 1;
    party.erase(party.begin() + party_member);
    num_party_members--;
    cout << "You surrendered and one of your party members was taken. There are " << num_party_members << " party members left." << endl;
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
int Game::investigateSpace()
{
    int event_chance = rand() % 100 + 1;
    int outcome = 0;
    if (event_chance >= 1 && event_chance <= 10)
    {
        findKey();
        cout << "You found a key!" << endl;
        outcome = 1;
    }
    else if (event_chance >= 11 && event_chance <= 30)
    {
        // FOUND TREASURE
        outcome = 2;
        string treasure_type;
        if (rooms_cleared == 1)
        {
            treasure_type = "Silver ring";
            num_rings++;
        }
        else if (rooms_cleared == 2)
        {
            treasure_type = "Ruby necklace";
            num_necklaces++;
        }
        else if (rooms_cleared == 3)
        {
            treasure_type = "Emerald bracelet";
            num_bracelets++;
        }
        else if (rooms_cleared == 4)
        {
            treasure_type = "Diamond circlet";
            num_circlets++;
        }
        else if (rooms_cleared == 5)
        {
            treasure_type = "Gem-encrusted goblet";
            num_goblets++;
        }
        cout << "You found a " << treasure_type << "!" << endl;
    }
    else if (event_chance >= 31 && event_chance <= 50)
    {
        outcome = 3;

        cout << "A monster appeared!" << endl;
    }
    else
    {
        cout << "Nothing happened." << endl;
        outcome = 4;
    }

    return outcome;
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
    cout << "+-------------+" << endl;
    cout << "| STATUS      |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Rooms Cleared: " << rooms_cleared << " | Keys: " << keys_found << " | Anger Level: " << anger_level << endl;
    cout << "+-------------+" << endl;
    cout << "| INVENTORY   |" << endl;
    cout << "+-------------+" << endl;
    cout << "| Gold        | " << gold_avail << endl;
    cout << "| Ingredients | " << ingredients_avail << " kg" << endl;
    cout << "| Cookware    | P: " << num_pots << " | F: " << num_pans << " | C: " << num_cauldrons << endl;
    cout << "| Weapons     | C: " << num_clubs << " | S: " << num_spears << " | R: " << num_rapiers << " | B: " << num_axes << " | L: " << num_longswords << endl;
    cout << "| Armor       | " << armor_avail << endl;
    cout << "| Treasures   | R: " << num_rings << " | N: " << num_necklaces << " | B: " << num_bracelets << " | C: " << num_circlets << " | G: " << num_goblets << endl;
    cout << "+-------------+" << endl;
    cout << "| PARTY       |" << endl;
    cout << "+-------------+" << endl;
    for (int i = 0; i < num_party_members; i++)
    {
        cout << "| " << party.at(i).getName() << " | Fullness: " << party.at(i).getFullness() << endl;
    }
    cout << "+-------------+" << endl;
}

/**
 * algorithm: displays the merchant menu with all options available
 * 1. gets player level through function input and multiplies merchant prices accordingly
 * 2. prompts player for input (what items they wish to select on the menu)
 * 3. input validation warns player of invalid inputs
 * 4. uses getters and setters to change gold values and items values based on what is sold and purchased
 */
void Game::displayMerchantMenu(int level)
{
}

/**
 * algorithm: diplays general NPC menu with interaction options
 * 1. random number generator is used to find a random index in the puzzle array
 * 2. prompts user with random puzzle
 * 3. if answer is correct the npc acts friendly and calls merchant menu function
 * 4. if answer is incorrect a monester is summoned
 * 5. calls fight function
 */
void Game::displayNPCMenu()
{
}