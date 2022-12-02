#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
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
    num_total_treasure = 0;
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
    game_over = false;
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

void Game::useKey()
{
    keys_found--;
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

bool Game::isGameOver()
{
    return game_over;
}

void Game::setGameOver(bool game_status)
{
    game_over = game_status;
}

/**
 * algorithm: takes input of item and amount of item to buy, spends gold, and sets amount of item purchased
 * 1. declare variable for total price of purchase
 * 2. based on the item and amount passed to the function, compute the total price
 * 3. check that the player has enough gold to make the purchase, if not return false
 * 4. if the player has enough gold, subtract the gold and set number of purchased item
 * 5. return true
 */
bool Game::purchaseItem(string item, int amount)
{
    int total_price;
    double price_multiplier = 1 + .25 * rooms_cleared;
    // calculating total price of purchase
    if (item == "ceramic_pot") // if loop sorts input
    {
        total_price = 2 * price_multiplier * amount;
        if (total_price > gold_avail) // not enough money, purchase fails
        {
            return false;
        }
        else // otherwise gold, number of specific cookware and total number of cookware updates
        {
            gold_avail -= total_price;
            num_pots += amount;
            num_total_cookware++;
        }
    }
    else if (item == "frying_pan")
    {
        total_price = 10 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_pans += amount;
            num_total_cookware++;
        }
    }
    else if (item == "cauldron")
    {
        total_price = 20 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_cauldrons += amount;
            num_total_cookware++;
        }
    }
    else if (item == "ingredients")
    {
        total_price = 1 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            ingredients_avail += amount;
        }
    }
    else if (item == "stone_club")
    {
        total_price = 2 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_clubs += amount;
            Weapon added(item, 0);
            addWeapon(added); // calls add weapon function in order to add the weapon to inventory
        }
    }
    else if (item == "iron_spear")
    {
        total_price = 2 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_spears += amount;
            Weapon added(item, 0);
            addWeapon(added);
        }
    }
    else if (item == "mythril_rapier")
    {
        total_price = 5 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_rapiers += amount;
            Weapon added(item, 1);
            addWeapon(added);
        }
    }
    else if (item == "flaming_battle_axe")
    {
        total_price = 15 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_axes += amount;
            Weapon added(item, 2);
            addWeapon(added);
        }
    }
    else if (item == "vorpal_longsword")
    {
        total_price = 50 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_longswords += amount;
            Weapon added(item, 3);
            addWeapon(added);
        }
    }
    else if (item == "armor")
    {
        total_price = 5 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            armor_avail += amount;
            for (int i = 0; i < armor_avail; i++)
            {
                if (i < num_party_members)
                {
                    party.at(i).equipArmor();
                }
            }
        }
    }
    return true;
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
        if (party.at(party.size() - 1).isArmored()) // kills party member and reduces armor amount
        {
            armor_avail--;
        }
        party.erase(party.begin() + party.size() - 1); // alters party size
    }
    return num_party_members;
}

int Game::readMonsters(string monster_file)
{
    ifstream fin(monster_file);
    string line;
    string elements[2];

    if (fin.fail()) //  if file fails to open
    {
        return -1;
    }

    while (!fin.eof())
    {
        getline(fin, line); //  reads each line of monster file
        if (line != "") // while there is info to read
        {
            int split_return = split(line, ',', elements, 2); // calls split function
            Monster temp_monster(elements[0], stoi(elements[1])); // stores monster in monster class with specs based on elements array
            monsters.push_back(temp_monster); // adds monster at end of array
            num_monsters++;
        }
    }
    return num_monsters;
}
/**algorithm: adds a player to the party if not full
 * 1. check if party is full, return -1 if true
 * 2. add player to party vector, increment party members
 * 3. return party members
 */
int Game::addPlayer(Player player_)
{
    if (party.size() == 5) // can't add party member once limit is met
    {
        return -1;
    }
    else
    {
        party.push_back(player_); // adds player to end of vector
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
            if (weapons.at(i).getDamageBonus() < weapon_.getDamageBonus()) // if statement acts as a way to sort the weapons by order of damage bonus
            {
                weapons.at(i) = weapon_;
                num_total_weapons++;
            }
            else if (i == 5) // replaces last weapon if new weapon is stronger
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
        if (weapons.at(i).getDamageBonus() < weapons.at(i + 1).getDamageBonus()) // used as sorting algorithm with less than condition
        {
            Weapon temp_weapon = weapons.at(i);
            weapons.at(i) = weapons.at(i + 1);
            weapons.at(i + 1) = temp_weapon;
        }
    }

    return num_total_weapons;
}

/**
 * algorithm: randomly picks a monster from the monsters vector based off amount of rooms cleared and whether we are on a room
 * 1. declare bool valid_monster, and int monster_selection
 * 2. while valid_monster is false:
 *  a. randomly generate value in the range 0-monsters.size()-1 (inclusive) for monster_selection
 *  b. create Monster chosen, chosen = monsters.at(monster_selection)
 *  c. if chosen.getRating() is not the appropriate level, valid_monster = false, choose another monster
 *  d. else valid_monster = true
 *  e if valid_monster is true, return chosen
 */
Monster Game::pickMonster(int level)
{

    // also add condition so sorcerer not picked until last room
    bool valid_monster = false;
    int monster_selection;

    while (!valid_monster) // runs as longs as a valid monster has not been found
    {
        monster_selection = rand() % monsters.size(); // randomizes index selection based on number of indeces in the monster vector
        Monster chosen = monsters.at(monster_selection); // defines chosen monster in monster class

        if (chosen.getRating() != level) // if statement makes sure levels line up with rating
        {
            valid_monster = false;
        }
        else
        {
            valid_monster = true;
        }

        if (valid_monster)
        {
            return chosen;
        }
    }
    Monster non_chosen("NO MONSTER CHOSEN", 0);
    return non_chosen;
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
    int w = weapons.size();
    int temp_bonus;
    bool different_weapons = true;
    int d = 4;
    int c = monster_.getRating();
    int rand1, rand2;
    double outcome;

    if (armor_avail == 0) // kills party memeber when armor is equal to 0
    {
        cout << "You had no armor, so a party member was killed." << endl;
        killPartyMember();
        return -1;
    }

    // setting the value for d - checks for when each party memebr has a different weapon
    for (int i = 0; i < weapons.size(); i++)
    {
        Weapon current_weapon = weapons.at(i);
        w += current_weapon.getDamageBonus();
        if (i > 0)
        {
            if (current_weapon.getName() == weapons.at(i - 1).getName()) // makes sure weapon name and weapon at index line up
            {
                different_weapons = false;
                d = 0;
            }
        }
    }

    // random number generation, two numbers 1 - 6
    rand1 = rand() % 6 + 1;
    rand2 = rand() % 6 + 1;

    outcome = double((rand1 * w + d));  
    outcome -= (double((rand2 * c)) / armor_avail);

    if (outcome > 0) // if battle is won
    {
        // remove monster from monsters vector so that it can't be fought again
        for (int i = 0; i < monsters.size(); i++) // sorts through monster vector
        {
            if (monster_.getName() == monsters.at(i).getName()) // removes monster when name is found
            {
                monsters.erase(monsters.begin() + i);
                num_monsters--;
            }
        }
        // calculating reward
        int key_chance = rand() % 100; // calculates number between 0 and 99
        int gold_reward = 10 * c;
        int ingredient_reward = 5 * c;
        if (key_chance >= 0 && key_chance <= 10) // if chance is between 0 and 9 key is found and reward is recieved
        {
            findKey();
            gold_avail += gold_reward;
            ingredients_avail += ingredient_reward;
            cout << "You won the fight and found a key! Your rewards are " << gold_reward << " gold, " << ingredient_reward << " kg of ingredients, and one key." << endl;
        }
        else // if chance is not in ideal zone key is not found but rest of reward is given
        {
            gold_avail += gold_reward;
            ingredients_avail += ingredient_reward;
            cout << "You won the fight! Your rewards are " << gold_reward << " gold and " << ingredient_reward << " kg of ingredients." << endl;
        }
    }
    else // if battle is lost
    {
        // calculate whether party members die or not
        int num_dead = 0;
        for (int i = 0; i < num_party_members; i++) // applies death chance to each party member
        {
            int death_chance = rand() % 100 + 1; // randomizes death chance between 1 and 100
            Player current = party.at(i);
            if (current.isArmored()) // death chance changes based on armor
            {
                if (death_chance > 0 && death_chance <= 5) // half the chance of dying with armor as compared to without armor
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
        cout << "You lost the fight. " << num_dead << " party members died." << endl;
    }
    for (int i = 0; i < num_party_members; i++) //  change fullness after deaths occur
    {
        int fullness_chance = rand() % 100 + 1;
        if (fullness_chance >= 1 && fullness_chance <= 50) // half chance of fullness decreasing
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
    int party_member = rand() % num_party_members + 1; // randomizes which party member is taken
    party.erase(party.begin() + party_member);
    num_party_members--;
    cout << "You surrendered and one of your party members was taken. There are " << num_party_members << " party members left." << endl;
}

/*
 * algorithm: investigates a space, determines outcome of investigation
 * 1. initialize int outcome = 0, generate random number between 1 and 100
 * 2. if random number is between 1 and 10, player gets key, print, "You found a key!", outcome = 1
 * 3. else if random number is between 11 and 30, player finds treasure, determine appropriate treasure and print result, outcome = 2
 * 4. else if random number is between 31 and 50, outcome = 3
 * 5. else print, "nothing happened." and outcome = 4
 * 6. return outcome
 */
int Game::investigateSpace()
{
    int event_chance = rand() % 100 + 1; // randomizes event chance one in a hundred
    int outcome = 0;
    if (event_chance >= 1 && event_chance <= 10) //  ten percent chance of finding a key
    {
        findKey();
        cout << "You found a key!" << endl;
        outcome = 1;
    }
    else if (event_chance >= 11 && event_chance <= 30) // used to sort between number of rooms cleared and evaluates reward based on rooms
    {
        // FOUND TREASURE
        outcome = 2;
        string treasure_type;
        if (rooms_cleared == 0) // no rooms cleared no reward
        {
            cout << "You didn't find anything." << endl;
            return outcome;
        }
        else if (rooms_cleared == 1) // reward is given repectivelly based on cleared spaces
        {
            treasure_type = "Silver ring";
            num_rings++;
            num_total_treasure++;
        }
        else if (rooms_cleared == 2)
        {
            treasure_type = "Ruby necklace";
            num_necklaces++;
            num_total_treasure++;
        }
        else if (rooms_cleared == 3)
        {
            treasure_type = "Emerald bracelet";
            num_bracelets++;
            num_total_treasure++;
        }
        else if (rooms_cleared == 4)
        {
            treasure_type = "Diamond circlet";
            num_circlets++;
            num_total_treasure++;
        }
        else if (rooms_cleared == 5)
        {
            treasure_type = "Gem-encrusted goblet";
            num_goblets++;
            num_total_treasure++;
        }
        cout << "You found a " << treasure_type << "!" << endl;
    }
    else if (event_chance >= 31 && event_chance <= 50 && rooms_cleared < 5)
    {
        outcome = 3; // must fight a monster
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
    int ingredients_for_cooking = 0;
    char cookware_choice = 'y';

    while (ingredients_for_cooking < 1)
    {
        cout << "Input the number of ingredients you want to cook:" << endl;
        cin >> ingredients_for_cooking;
        if (ingredients_for_cooking < 1)
        {
            cout << "Please input a valid amount." << endl;
        }
    }

    int change_in_fullness = ingredients_for_cooking / 5;

    while (cookware_choice != 'p' && cookware_choice != 'f' && cookware_choice != 'c')
    {
        cout << "Input the cookware you wish to use ('p' for pot, 'f' for pan, 'c' for cauldron):" << endl;
        cin >> cookware_choice;
        if (cookware_choice != 'p' && cookware_choice != 'f' && cookware_choice != 'c')
        {
            cout << "Please input a valid cookware item." << endl;
        }
    }
    if (cookware_choice == 'p') // 25% chance of breaking (1 in 4)
    {
        int chance_P = 3;
        int random_num_P = rand() % 4 + 1;
        if (random_num_P == chance_P)
        {
            // destroy ingredients
            // destroy cookware
            cout << "The cook was unsuccessful because your ceramic pot broke. Your ingredients have been lost." << endl;
            num_pots--;
            ingredients_avail -= ingredients_for_cooking;
            cook_successful = false;
        }
        else
        {
            // fullness goes up proportionally for all, one fullness point for 5kg
            for (int i = 0; i < party.size(); i++)
            {
                party.at(i).changeFullness(change_in_fullness);
            }
            cout << "The cook was successful and everyones fullness just went up by " << change_in_fullness << "." << endl;
            ingredients_avail -= ingredients_for_cooking;
        }
    }
    else if (cookware_choice == 'f') // 20% chance of breaking (1 in 5)
    {
        int chance_F = 2;
        int random_num_F = rand() % 5 + 1;
        if (random_num_F == chance_F)
        {
            // destroy ingredients
            // destroy cookware
            cout << "The cook was unsuccessful because your frying pan broke. Your ingredients have been lost." << endl;
            num_pans--;
            ingredients_avail -= ingredients_for_cooking;
            cook_successful = false;
        }
        else
        {
            // fullness goes up proportionally for all
            for (int i = 0; i < party.size(); i++)
            {
                party.at(i).changeFullness(change_in_fullness);
            }
            cout << "The cook was successful and everyones fullness just went up by " << change_in_fullness << "." << endl;
            ingredients_avail -= ingredients_for_cooking;
        }
    }
    else if (cookware_choice == 'C') // 2% chance of breaking (1 in 50)
    {
        int chance_C = 23;
        int random_num_C = rand() % 50 + 1;
        if (random_num_C == chance_C)
        {
            // destroy ingredients
            // destroy cookware
            cout << "The cook was unsuccessful because your cauldron broke. Your ingredients have been lost." << endl;
            num_cauldrons--;
            ingredients_avail -= ingredients_for_cooking;
            cook_successful = false;
        }
        else
        {
            // fullness goes up proportionally for all
            for (int i = 0; i < party.size(); i++)
            {
                party.at(i).changeFullness(change_in_fullness);
            }
            cout << "The cook was successful and everyones fullness just went up by " << change_in_fullness << "." << endl;
            ingredients_avail -= ingredients_for_cooking;
        }
    }

    return cook_successful;
}

/**
 * algorithm: sorts the scores of previous games, calculate last game score, display where player is on score board
 * 1. read in scores from external text file, add to a vector, all_scores
 * 2. declare second vector, top, for top 10 scores
 * 3. declare variable for last score, calculate last score
 * 33. iterate through all_scores, find max
 * 4. add max value to top, remove from all_scores
 * 5. continue sorting until the top 10 scores have been stored
 */
void Game::sortScores(string score_file)
{
    ifstream fscore_in(score_file);
    vector<int> all_scores;
    vector<string> player_names;
    int last_score = 0;
    double point_multiplier = 1 + .25 * rooms_cleared;

    /*
        calculating last_score, score is based on:
        1. amount of gold left at end of game
        2. amount of rooms cleared
        3. whether the sorcerer was killed (game beat)
        4. amount of treasure left at end of game (pts per treasure = gold value)
        5. amount of weapons left at end of game (pts per weapon = gold value)
        6. amount of ingredients left at end of game (pts per ingredient = gold value)
        7. amount of cookware left at end of game (pts per cookware = gold value)
        8. amount of players left at end of game
    */
    last_score += gold_avail;
    for (int i = 0; i < rooms_cleared; i++)
    {
        last_score += 25;
    }
    if (rooms_cleared == 5) // player beat the game/sorcerer
    {
        last_score += 100;
    }
    for (int i = 0; i < num_party_members; i++)
    {
        last_score += 15;
    }
    // calculate amount of points player gets for cookware
    // int
    // for (int i = 0; i < num_pots; i++)
    // {
    // }
    // num_total_cookware, num_pots 5, num_pans 10, num_cauldrons 20;
    last_score += (num_pots * 5) * point_multiplier;
    last_score += (num_pans * 10) * point_multiplier;
    last_score += (num_cauldrons * 20) * point_multiplier;
    // calculate amount of points player gets for treasure
    // while (num_total
    // num_rings 10, num_necklaces 20, num_bracelets 30, num_circlets 40, num_goblets 50
    last_score += (num_necklaces * 20);
    last_score += (num_bracelets * 30);
    last_score += (num_circlets * 40);
    last_score += (num_goblets * 50);
    // calculate points for ingredients
    last_score += (ingredients_avail)*point_multiplier;
    // calculate points for weapons
    // num_clubs 2, num_spears 2, num_rapiers 5, num_axes 15, num_longswords 50;
    last_score += (num_clubs * 2) * point_multiplier;
    last_score += (num_spears * 2) * point_multiplier;
    last_score += (num_rapiers * 5) * point_multiplier;
    last_score += (num_axes * 15) * point_multiplier;
    last_score += (num_longswords * 50) * point_multiplier;

    // read in scores + corresponding names for past scores from score_file
    while (!fscore_in.eof())
    {
        string elements[2];
        string line;
        getline(fscore_in, line);
        if (line != "")
        {
            int split_return = split(line, ',', elements, 2); // elements[0] is name, elements[1] is score

            // populate the vectors
            player_names.push_back(elements[0]);
            all_scores.push_back(stoi(elements[1]));
        }
    }

    fscore_in.close();

    // append last_score and name to all_scores and player_names vectors
    player_names.push_back(party.at(0).getName());
    all_scores.push_back(last_score);

    // sort the scores highest to lowest
    if (all_scores.size() >= 2)
    {
        for (int i = 0; i < all_scores.size(); i++)
        {
            for (int j = i + 1; j < all_scores.size(); j++)
            {
                if (all_scores.at(i) < all_scores.at(j))
                {
                    int temp_score = all_scores.at(i);
                    all_scores.at(i) = all_scores.at(j);
                    all_scores.at(j) = temp_score;
                    string temp_name = player_names.at(i);
                    player_names.at(i) = player_names.at(j);
                    player_names.at(j) = temp_name;
                }
            }
        }
    }

    // find last_score in ranking
    int last_score_index = 0;
    for (int i = 0; i < all_scores.size(); i++)
    {
        if (all_scores.at(i) == last_score && player_names.at(i) == party.at(0).getName())
        {
            last_score_index = i;
            break;
        }
    }

    // output scores and names to output file
    ofstream fscore_out(score_file, ios::out | ios::trunc);
    for (int i = 0; i < all_scores.size(); i++)
    {
        fscore_out << player_names.at(i) << ',' << all_scores.at(i) << "\n";
    }
    fscore_out.close();

    // display message to player showing score and placement on leaderboard and where player stands in scores
    last_score_index++;
    cout << "Congratulations! Your final score was " << last_score << " points. Your current ranking is: " << last_score_index << endl;
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
    int choice, total_price, quantity;
    double price_multiplier = 1 + level * .25;
    char confirmation;
    bool purchase_return;

    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;

    do // prints initial menu
    {
        cout << "+-------------+" << endl;
        cout << "| INVENTORY   |" << endl;
        cout << "+-------------+" << endl;
        cout << "| Gold        | " << gold_avail << endl;
        cout << "| Ingredients | " << ingredients_avail << " kg" << endl;
        cout << "| Cookware    | P: " << num_pots << " | F: " << num_pans << " | C: " << num_cauldrons << endl;
        cout << "| Weapons     | C: " << num_clubs << " | S: " << num_spears << " | R: " << num_rapiers << " | B: " << num_axes << " | L: " << num_longswords << endl;
        cout << "| Armor       | " << armor_avail << endl;
        cout << "| Treasures   | R: " << num_rings << " | N: " << num_necklaces << " | B: " << num_bracelets << " | C: " << num_circlets << " | G: " << num_goblets << endl;

        cout << "Choose one of the following:" << endl;
        cout << " 1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << " 2. Cookware: You will need something to cook those ingredients." << endl;
        cout << " 3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << " 4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << " 5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << " 6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cin >> choice;
        // cascades onwards based on switch statement selection, getting more specific as more options ar selected, confirmation statement is then printed based on input and updated inventory
        switch (choice) // initial switch statement sorts between initial choices listed in menu
        {
        case 1:
            cout << "How many kg of ingredients do you need [" << 1 * price_multiplier << " Gold/kg]? (Enter a positive mulitple of 5, or 0 to cancel)" << endl;
            cin >> quantity;
            if (quantity == 0)
            {
                cout << "Let me know if you change your mind!" << endl;
                break;
            }
            total_price = quantity * price_multiplier * 1;
            cout << "You want to buy " << quantity << " kg of ingredients for " << total_price << " Gold? (y/n)" << endl;
            cin >> confirmation;

            switch (confirmation) // input validation switch statement
            {
            case 'y':
                purchase_return = purchaseItem("ingredients", quantity);
                if (purchase_return)
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                }
                else
                {
                    cout << "Insufficient funds. Please make a different selection." << endl;
                }
                break;
            case 'n':
                cout << "Let me know if you change your mind!" << endl;
                break;
            default:
                cout << "Invalid input. Please enter a valid input." << endl;
                break;
            }
            break;
        case 2: // specific cookware switch
            cout << "I have a several types of cookware, which one would you like?" << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            cout << endl;
            cout << "Choose one of the following (0 to cancel):" << endl;
            cout << "1. (25%) Ceramic Pot [" << 2 * price_multiplier << " Gold]" << endl;
            cout << "2. (10%) Frying Pan [" << 10 * price_multiplier << " Gold]" << endl;
            cout << "3. ( 2%) Cauldron [" << 20 * price_multiplier << " Gold]" << endl;
            cin >> choice;
            switch (choice) // switch used to purchase specific items
            {
            case 0:
                cout << "Let me know if you change your mind!" << endl;
                break;
            case 1:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 2;
                cout << "You want to buy " << quantity << " Ceramic Pot(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("ceramic_pot", quantity);
                    if (purchase_return)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;

                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    break;
                }
                break;
            case 2:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 10;
                cout << "You want to buy " << quantity << " Frying Pan(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("frying_pan", quantity);
                    if (purchase_return) // purchase statement
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    break;
                }
                break;
            case 3:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 20;
                cout << "You want to buy " << quantity << " Cauldron(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("cauldron", quantity);
                    if (purchase_return) // purchase statement
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    break;
                }
                break;
            default:
                cout << "Invalid input. Please make a valid selection." << endl;
                choice = 0;
                break;
            }
            break;
        case 3:
            cout << "I have a plentiful collection of weapons to choose from, what would you like?" << endl;
            cout << "Note that some of them provide you a special bonus in combat, marked by a (+X)." << endl;
            cout << endl;
            cout << "Choose one of the following (0 to cancel):" << endl;
            cout << " 1. Stone Club [" << 2 * price_multiplier << " Gold]" << endl;
            cout << " 2. Iron Spear [" << 2 * price_multiplier << " Gold]" << endl;
            cout << " 3. (+1) Mythril Rapier [" << 5 * price_multiplier << " Gold]" << endl;
            cout << " 4. (+2) Flaming Battle-Axe [" << 15 * price_multiplier << " Gold]" << endl;
            cout << " 5. (+3) Vorpal Longsword [" << 50 * price_multiplier << " Gold]" << endl;
            cin >> choice;

            switch (choice)
            {
            case 0:
                cout << "Let me know if you change your mind!" << endl;
                break;
            case 1:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 2;
                cout << "You want to buy " << quantity << " Stone Club(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("stone_club", quantity);
                    if (purchase_return)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    break;
                }
                break;
            case 2:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 2;
                cout << "You want to buy " << quantity << " Iron Spear(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("iron_spear", quantity);
                    if (purchase_return)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    break;
                }
                break;
            case 3:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 5;
                cout << "You want to buy " << quantity << " Mythril Rapier(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("mythril_rapier", quantity);
                    if (purchase_return)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    break;
                }
                break;
            case 4:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 15;
                cout << "You want to buy " << quantity << " Flaming Battle-Axe(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("flaming_battle_axe", quantity);
                    if (purchase_return)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    choice = 0;
                    break;
                }
                break;
            case 5:
                cout << "How many would you like? (Enter a positive integer, or 0 to cancel)" << endl;
                cin >> quantity;
                if (quantity == 0)
                {
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                }
                total_price = quantity * price_multiplier * 50;
                cout << "You want to buy " << quantity << " Vorpal Longsword(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("vorpal_longsword", quantity);
                    if (purchase_return)
                    {
                        cout << "Thank you for your patronage! What else can I get for you?" << endl;
                    }
                    else
                    {
                        cout << "Insufficient funds. Please make a different selection." << endl;
                    }
                    break;
                case 'n':
                    cout << "Let me know if you change your mind!" << endl;
                    break;
                default:
                    cout << "Invalid input. Please enter a valid input." << endl;
                    break;
                }
                break;
            default:
                cout << "Invalid input. Please make a valid selection." << endl;
                choice = 0;
                break;
            }
            break;
        case 4:
            cout << "How many sets of armor you like? Armor is " << 5 * price_multiplier << " Gold/set. (Enter a positive integer, or 0 to cancel)" << endl;
            cin >> quantity;
            if (quantity == 0)
            {
                cout << "Let me know if you change your mind!" << endl;
                break;
            }
            total_price = quantity * price_multiplier * 5;
            cout << "You want to buy " << quantity << " Armor Set(s) for " << total_price << " gold? (y/n)" << endl;
            cin >> confirmation;
            switch (confirmation)
            {
            case 'y':
                purchase_return = purchaseItem("armor", quantity);
                if (purchase_return)
                {
                    cout << "Thank you for your patronage! What else can I get for you?" << endl;
                }
                else
                {
                    cout << "Insufficient funds. Please make a different selection." << endl;
                }
                break;
            case 'n':
                cout << "Let me know if you change your mind!" << endl;
                break;
            default:
                cout << "Invalid input. Please enter a valid input." << endl;
                break;
            }

            break;
        case 5:
            cout << "What would you like to sell today? (0 to cancel)" << endl;
            cout << " 1. Silver Rings - 10 gold/piece" << endl;
            cout << " 2. Ruby Necklaces - 20 gold/piece" << endl;
            cout << " 3. Emerald Bracelets - 30 gold/piece" << endl;
            cout << " 4. Diamond Circlets - 40 gold/piece" << endl;
            cout << " 5. Gem-encrusted Goblets - 50 gold/piece" << endl;
            cin >> choice;

            switch (choice)
            {
            case 0:
                cout << "Let me know if you change your mind!" << endl;
                break;
            case 1:
                if (num_rings > 0)
                {
                    cout << "How many Silver Rings would you like to sell?" << endl;
                    cin >> quantity;
                    if (quantity < 0 || quantity > num_rings)
                    {
                        cout << "Invalid input. Please enter a different amount." << endl;
                    }
                    else if (quantity == 0)
                    {
                        cout << "Let me know if you change your mind!" << endl;
                        break;
                    }
                    else
                    {
                        total_price = 30 * quantity;
                        cout << "Are you sure you would like to sell " << quantity << " Silver Rings for " << total_price << " gold? (y/n)" << endl;
                        cin >> confirmation;

                        switch (confirmation)
                        {
                        case 'y':
                            gold_avail += total_price;
                            num_rings -= quantity;
                            cout << "Pleasure doing business with you!" << endl;
                            break;
                        case 'n':
                            cout << "Let me know if you change your mind!" << endl;
                            break;
                        default:
                            cout << "Invalid input. Please enter a valid input." << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "You don't have any Silver Rings to sell. Please select a different item." << endl;
                }
                break;
            case 2:
                if (num_necklaces > 0)
                {
                    cout << "How many Ruby Necklaces would you like to sell?" << endl;
                    cin >> quantity;
                    if (quantity < 0 || quantity > num_necklaces)
                    {
                        cout << "Invalid input. Please enter a different amount." << endl;
                    }
                    else if (quantity == 0)
                    {
                        cout << "Let me know if you change your mind!" << endl;
                        break;
                    }
                    else
                    {
                        total_price = 20 * quantity;
                        cout << "Are you sure you would like to sell " << quantity << " Ruby Necklaces for " << total_price << " gold? (y/n)" << endl;
                        cin >> confirmation;

                        switch (confirmation)
                        {
                        case 'y':
                            gold_avail += total_price;
                            num_necklaces -= quantity;
                            cout << "Pleasure doing business with you!" << endl;
                            break;
                        case 'n':
                            cout << "Let me know if you change your mind!" << endl;
                            break;
                        default:
                            cout << "Invalid input. Please enter a valid input." << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "You don't have any Ruby Necklaces to sell. Please select a different item." << endl;
                }
                break;
            case 3:
                if (num_bracelets > 0)
                {
                    cout << "How many Emerald Bracelets would you like to sell?" << endl;
                    cin >> quantity;
                    if (quantity < 0 || quantity > num_bracelets)
                    {
                        cout << "Invalid input. Please enter a different amount." << endl;
                    }
                    else if (quantity == 0)
                    {
                        cout << "Let me know if you change your mind!" << endl;
                        break;
                    }
                    else
                    {
                        total_price = 30 * quantity;
                        cout << "Are you sure you would like to sell " << quantity << " Emerald Bracelets for " << total_price << " gold? (y/n)" << endl;
                        cin >> confirmation;

                        switch (confirmation)
                        {
                        case 'y':
                            gold_avail += total_price;
                            num_bracelets -= quantity;
                            cout << "Pleasure doing business with you!" << endl;
                            break;
                        case 'n':
                            cout << "Let me know if you change your mind!" << endl;
                            break;
                        default:
                            cout << "Invalid input. Please enter a valid input." << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "You don't have any Emerald Bracelets to sell. Please select a different item." << endl;
                }
                break;
            case 4:
                if (num_circlets > 0)
                {
                    cout << "How many Diamond Circlets would you like to sell?" << endl;
                    cin >> quantity;
                    if (quantity < 0 || quantity > num_circlets)
                    {
                        cout << "Invalid input. Please enter a different amount." << endl;
                    }
                    else if (quantity == 0)
                    {
                        cout << "Let me know if you change your mind!" << endl;
                        break;
                    }
                    else
                    {
                        total_price = 40 * quantity;
                        cout << "Are you sure you would like to sell " << quantity << " Diamond Circlets for " << total_price << " gold? (y/n)" << endl;
                        cin >> confirmation;

                        switch (confirmation)
                        {
                        case 'y':
                            gold_avail += total_price;
                            num_circlets -= quantity;
                            cout << "Pleasure doing business with you!" << endl;
                            break;
                        case 'n':
                            cout << "Let me know if you change your mind!" << endl;
                            break;
                        default:
                            cout << "Invalid input. Please enter a valid input." << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "You don't have any Diamond Circlets to sell. Please select a different item." << endl;
                }
                break;
            case 5:
                if (num_goblets > 0)
                {
                    cout << "How many Gem-encrusted Goblets would you like to sell?" << endl;
                    cin >> quantity;
                    if (quantity < 0 || quantity > num_goblets)
                    {
                        cout << "Invalid input. Please enter a different amount." << endl;
                    }
                    else if (quantity == 0)
                    {
                        cout << "Let me know if you change your mind!" << endl;
                        break;
                    }
                    else
                    {
                        total_price = 50 * quantity;
                        cout << "Are you sure you would like to sell " << quantity << " Gem-encrusted Goblets for " << total_price << " gold? (y/n)" << endl;
                        cin >> confirmation;

                        switch (confirmation)
                        {
                        case 'y':
                            gold_avail += total_price;
                            num_goblets -= quantity;
                            cout << "Pleasure doing business with you!" << endl;
                            break;
                        case 'n':
                            cout << "Let me know if you change your mind!" << endl;

                            break;
                        default:
                            cout << "Invalid input. Please enter a valid input." << endl;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "You don't have any Gem-encrusted Goblets to sell. Please select a different item." << endl;
                }
                break;
            default:
                cout << "Invalid input. Please make a different selection." << endl;
                choice = 6;
                break;
            }
            break;
        case 6:
            cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
            cin >> confirmation;

            switch (confirmation)
            {
            case 'y':
                cout << "Stay safe out there! Goodbye!" << endl;
                break;
            case 'n':
                cout << "What would you like?" << endl;
                choice = 0;
                break;
            default:
                cout << "Invalid input. Please enter a valid input." << endl;
                choice = 0;
                break;
            }
            break;
        default:
            cout << "Invalid input. Please make a different selection." << endl;
            choice = 0;
            break;
        }
    } while (choice != 6);
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
    string riddle, riddle_solution, player_answer;
    char choice;

    // set values for riddle and solution
    int riddle_index = rand() % riddles.size(); // pick a random number for riddle
    riddle = riddles.at(riddle_index);
    riddle_solution = riddle_solutions.at(riddle_index);

    // display riddle to player and ask for solution
    cout << "In order to speak to me, you must answer this riddle:" << endl;
    cout << riddle << endl;
    cin >> player_answer;

    if (player_answer != riddle_solution) // when answer is incorrect
    {
        cout << "Wrong answer!" << endl;
        Monster summoned = pickMonster(rooms_cleared + 1); // spawn monster
        cout << endl;
        cout << "A " << summoned.getName() << " is approaching! Fight (f) or surrender (s)?" << endl; // alert player
        cin >> choice;
        do // gives player menu of options in monster encounter
        {
            if (choice == 'f')
            {
                double fight_return = fight(summoned);
            }
            else if (choice == 's')
            {
                surrender();
            }
            else
            {
                cout << "Enter a valid input." << endl;
                cout << "Fight (f) or surrender (s)?" << endl;
                cin >> choice;
                if (choice == 'f')
                {
                    double fight_return = fight(summoned);
                }
                else if (choice == 's')
                {
                    surrender();
                }
            }
        } while (choice != 'f' && choice != 's');
    }
    else
    {
        cout << "Congratulations, that was the correct answer!" << endl;
        cout << "Would you like to barter for some goods?" << endl; // if answer is correct show merchant menu
        displayMerchantMenu(rooms_cleared);
    }
}

/**
 * algorithm: checks game status to determine whether player has lost, won, or if the game is in progress
 * 1. if either main player is dead, or there are less than 2 party members, return "lost"
 * 2. else if the player is at the exit tile and there are 2 or more party members remaining, and all the rooms have been cleared return "won"
 * 3. else return "in progress"
 */
string Game::gameResult()
{
    string result;
    bool leader_alive = false;

    // see if the leader is still alive
    for (int i = 0; i < num_party_members; i++)
    {
        if (party.at(i).getLeadership())
        {
            leader_alive = true;
            break;
        }
    }

    if (!leader_alive) // if leader dies game is lost
    {
        result = "lost";
        cout << "The leader is dead. Game over." << endl;
        setGameOver(true);
    }
    else if (num_party_members < 2 && leader_alive) // if leader is alive but less than two other poarty members remain game is lost
    {
        result = "lost";
        cout << "There are less than two party members left. Game over." << endl;
        setGameOver(true);
    }
    else if (num_party_members >= 2 && rooms_cleared == 5 && leader_alive && anger_level < 100) // if leader is alive and more than one party member is alive game is won after all rooms are cleared
    {
        result = "won";
        setGameOver(true);
    }
    else if (num_party_members >= 2 && rooms_cleared < 5 && leader_alive && anger_level < 100) //  if sufficient people are alive but rooms have not been all cleared print progress statement
    {
        result = "in progress";
    }
    else if (anger_level == 100) // lost if anger level reaches max
    {
        cout << "The Sorcerer was angered too much by your actions and destroyed the dungeon. Game over." << endl;
        setGameOver(true);
        result = "lost";
    }
    return result;
}

/**
 * algorithm: calculate whether misfortune happens, execute misfortune if true
 * 1. generate random number
 * 2. if the random number is between 1 and misfortune_chance, run misfortune
 * 3. generate another random number
 *  a. if random number between 1 and 30
 *   i. generate additional random number, use to determine whether party loses ingredients, cookware, or armor
 *  b. if random number between 31 and 40
 *   i. generate additional random number, use to determine whether armor or weapon breaks
 *   ii. if weapon breaks, randomly choose weapon to break
 *   iii. otherwise subtract one armor
 *  c. if random number between 41 and 70
 *   i. subtract 10 fullness points from a randomly chosen party member
 *   ii. if the party member is at fullness = 0, kill party member
 *  d. if random number between 71 and 100
 *   i. party member locked in room, kill party member
 */
void Game::misfortune(int chance)
{
    int misfortune_chance = rand() % chance + 1;
    int misfortune_type = rand() % 100 + 1;
    bool occurred = false;

    // misfortune actually occurs
    if (misfortune_chance >= 1 && misfortune_chance <= chance)
    {
        // party is robbed
        if (misfortune_type >= 1 && misfortune_type <= 30)
        {
            cout << "Oh no! Your team was robbed by dungeon bandits!" << endl;
            cout << endl;
            /*
                determine which misfortune occurs:
                 misfortune_type = 1: lose 10kg ingredients
                 misfortune_type = 2: lose a cookware item (generated randomly from the types that the player has)
                 misfortune_type = 3: lose 10kg ingredients

                if an item is not available to take, print out a message informing the player
            */
            misfortune_type = rand() % 3 + 1; // 33% chance calculator
            if (misfortune_type == 1 && ingredients_avail >= 10) // 33% chance of losing 10kg of ingredients
            {
                cout << "You lost 10 of ingredients!" << endl;
                ingredients_avail--;
            }
            else if (misfortune_type == 2 || ingredients_avail < 10) // 33% chance of encountering bandits
            {
                /*
                    determine the type of cookware that is lost
                     misfortune_type = 1: pot
                     misfortune_type = 2: pan
                     misfortune_type = 3: cauldron

                    every time a cookware is calculated should also be checked that there is an item available to take
                    If there is not an item available to take, generate another number, or if there are not items to take, print a message to the player
                */
                while (!occurred) //  while initial bool value is still false run through while statement
                {
                    misfortune_type = rand() % 3 + 1; // sorts through whether cookware is lost or armor to bandits
                    if (misfortune_type == 1 && num_pots >= 1)
                    {
                        cout << "You lost a ceramic pot!" << endl;
                        num_pots--;
                        occurred = true;
                    }
                    else if (misfortune_type == 2 && num_pans >= 1)
                    {
                        cout << "You lost a frying pan!" << endl;
                        num_pans--;
                        occurred = true;
                    }
                    else if (misfortune_type == 3 && num_cauldrons >= 1)
                    {
                        cout << "You lost a cauldron!" << endl;
                        num_cauldrons--;
                        occurred = true;
                    }
                    else if (misfortune_type == 3 && armor_avail > 0)
                    {
                        cout << "You lost a set of armor!" << endl;
                        armor_avail--;
                        occurred = true;
                    }
                    else // if nothing available bandits take nothing
                    {
                        cout << "The bandits saw you had nothing and left without taking anything." << endl;
                        occurred = true;
                    }
                }
            }
        }
        else if (misfortune_type >= 31 && misfortune_type <= 40) // equipment breaks
        {
            /*
                calculating what item breaks
                if misfortune_type =
                 1: armor breaks
                 2: club breaks
                 3: spear breaks
                 4: rapier breaks
                 5: battle-axe breaks
                 6: longsword breaks

                If there are none of the selected item, keep generating numbers to select items until one is either able to be broken
                or if there are no items that can be broken, nothing will happen
            */
            while (!occurred) // runs through what occurences until one is found true
            {
                misfortune_type = rand() % 6 + 1; // chance of each specific weapon breaking
                if (misfortune_type == 1 && armor_avail > 0)
                {
                    cout << "Oh no! One of your party's sets of armor broke!" << endl;
                    armor_avail--;
                    occurred = true;
                }
                else if (misfortune_type == 2 && num_clubs > 0)
                {
                    cout << "Oh no! Your club broke!" << endl;
                    num_clubs--;
                    occurred = true;
                }
                else if (misfortune_type == 3 && num_spears > 0)
                {
                    cout << "Oh no! Your spear broke!" << endl;
                    num_spears--;
                    occurred = true;
                }
                else if (misfortune_type == 4 && num_rapiers > 0)
                {
                    cout << "Oh no! Your +1 Rapier broke!" << endl;
                    num_rapiers--;
                    occurred = true;
                }
                else if (misfortune_type == 5 && num_axes > 0)
                {
                    cout << "Oh no! Your +2 Flaming Battle-Axe broke!" << endl;
                    num_axes--;
                    occurred = true;
                }
                else if (misfortune_type == 6 && num_longswords > 0)
                {
                    cout << "Oh no! Your +3 Vorpal Longsword broke!" << endl;
                    num_longswords--;
                    occurred = true;
                }
            }
        }
        else if (misfortune_type >= 41 && misfortune_type <= 70) // party member gets food poisoning
        {
            cout << "One of your party members got food poisoning!" << endl;
            int member_index = (rand() % (num_party_members - 1));
            party.at(member_index).changeFullness(-10);
            if (party.at(member_index).getFullness() <= 0)
            {
                if (party.at(member_index).getLeadership()) // leaders dies party dies
                {
                    cout << "You died. Game over." << endl;
                    setGameOver(true);
                }
                else // otherwise party member is lost
                {
                    cout << party.at(member_index).getName() << " died from starvation." << endl;
                }
            }
        }
    }
}

/**
 * algorithm: check fullness of players, if any is 0, display warning about player fullness, kill player if it has been more than one turn with
 * 1. if player.isStarved() is true
 *  a. kill player
 *  b. print message telling player that a party member starved
 * 2. else if the player is at 0 fullness and player.isStarved() is false
 *  a. set player starved status to true
 *  b. print warning about player fullness status
 */
void Game::checkFullness()
{
    for (int i = 0; i < num_party_members; i++) // sorts through each party member with for loop
    {
        Player current = party.at(i); //  player selected
        int fullness = current.getFullness();
        if (fullness == 0 && current.isStarving()) // no fullness and starving
        {
            if (current.getLeadership()) // leader dies
            {
                cout << "You died. Game over." << endl;
                setGameOver(true);
            }
            else // party member dies to starvation
            {
                num_party_members--;
                party.erase(party.begin() + i);
                cout << current.getName() << " starved to death. There are " << num_party_members << " party members remaining." << endl;
            }
            i--;
        }
        else if (fullness = 0 && !current.isStarving()) // give warning for 0 fullness
        {
            current.setStarving(true);
            cout << current.getName() << " is starving. Cook and some food and eat to replenish their fullness or they will die." << endl;
        }
    }
}

/**
 * algorithm: display the door puzzle, determine whether player wins or loses, calculate result (player dies, or party gains access to room)
 * 1. initalize int outcome = -1, char for computer choice, char for player choice
 * 2. do while outcome == 0 (player and computer tie):
 * 3. randomize char for computer choice
 * 4. prompt player for player choice input
 * 5. calculate outcome
 * 6. outcome = 1 if player wins
 * 7. outcome = 2 is computer wins
 * 8. outcome = 0 if tie
 * 9. return outcome
 */
int Game::displayDoorPuzzle()
{
    int outcome = 0;
    char player_choice;
    int computer_choice = 0;
    int num_tries = 0;

    do // lists initial menu (rock, paper, scissors)
    {
        cout << "Choose an option:" << endl;
        cout << "| b: boulder | p: parchment | s: shears |" << endl;
        cin >> player_choice;

        /*
            selecting computer choice, number corresponds to boulder, parchment, or shears
            1 = boulder
            2 = parchment
            3 = shears
        */
        computer_choice = rand() % 3 + 1; // randomizes opponent selection

        if (player_choice == 'b') // evaluates based on selection and randomization, prints outcome accordingly
        {
            if (computer_choice == 1)
            {
                cout << "Tie." << endl;
                cout << endl;
                outcome = 0;
                num_tries++;
            }
            else if (computer_choice == 2)
            {
                cout << "You lost." << endl;
                outcome = 2;
                num_tries++;
            }
            else if (computer_choice == 3)
            {
                cout << "You won and gained access to the room!" << endl;
                outcome = 1;
            }
        }
        else if (player_choice == 'p')
        {
            if (computer_choice == 1)
            {
                cout << "You won and gained access to the room!" << endl;
                outcome = 1;
            }
            else if (computer_choice == 2)
            {
                cout << "Tie." << endl;
                cout << endl;
                num_tries++;
                outcome = 0;
            }
            else if (computer_choice == 3)
            {
                cout << "You lost." << endl;
                outcome = 2;
                num_tries++;
            }
        }
        else if (player_choice == 's')
        {
            if (computer_choice == 1)
            {
                cout << "You lost." << endl;
                outcome = 2;
                num_tries++;
            }
            else if (computer_choice == 2)
            {
                cout << "You won and gained access to the room!" << endl;
                outcome = 1;
            }
            else if (computer_choice == 3)
            {
                cout << "Tie." << endl;
                outcome = 0;
                num_tries++;
                cout << endl;
            }
        }
        else // input validation
        {
            cout << "Invalid input. Please make a valid selection." << endl;
            cout << endl;
        }
    } while (num_tries < 3 && outcome != 1);

    if (num_tries == 3 && outcome != 1) // more than three tries, door does not open
    {
        cout << "You took too many tries to open the door. One of your party members was locked in the room." << endl;
        int player_lost = (rand() % num_party_members - 1) + 1;
        party.erase(party.begin() + player_lost);
        num_party_members--;
    }
    else if (num_tries < 3 && outcome == 1) // monster selected by calling pickMonster function
    {
        Monster temp = pickMonster(rooms_cleared+2);
        cout << "There was a " << temp.getName() << " (challenge rating " << temp.getRating() << ") in the room!" << endl;
        fight(temp);
    }

    return outcome;
}
/**
 * algorithm: popuulates the riddle vector with riddles from a file
 * 1. open file stream
 * 2. while there is content to read in the file, add the riddles to the riddles vector, ignoring empty lines
 * 3. add solutions to the riddle_solutions vector
 * 4. increment amount of riddles added
 * 5. return amount of riddles added
 */
int Game::readRiddles(string riddle_file)
{
    string file_line;
    string riddles_with_solutions[2];
    int num_elements = 0;
    int counter = 0;
    ifstream input_file;

    input_file.open(riddle_file); // reads from riddle file
    if (input_file.fail())
    {
        return -1;
    }
    while (!input_file.eof()) // splits riddles read from array into vectors with riddles and answers seperate
    {
        getline(input_file, file_line);
        num_elements = split(file_line, '~', riddles_with_solutions, 2);
        riddles.push_back(riddles_with_solutions[0]);
        riddle_solutions.push_back(riddles_with_solutions[1]);
        counter++;
    }
    return counter;
}

/**
 * algorithm: calculates whether party member loses fullness after moving and subtracts fullness
 * 1. for each player in the party, generate a random number 1-100, dec_chance
 * 2. if dec_chance is between 1 and 20, decrease the fullness of the current party member
 */
void Game::decFullness()
{
    int dec_chance = 0;
    for (int i = 0; i < num_party_members; i++) //  cycles through all party members
    {
        dec_chance = rand() % 100 + 1; // probability of decreasing fullness
        if (dec_chance >= 1 && dec_chance <= 20) // 20% chance og losing 1 fullness for each party member
        {
            party.at(i).changeFullness(-1);
        }
    }
}