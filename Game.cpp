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
    double price_multiplier = .25 * rooms_cleared + 1;
    // calculating total price of purchase
    if (item == "ceramic_pot")
    {
        total_price = 2 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            num_pots += amount;
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
        }
    }
    else if (item == "armor")
    {
        total_price = 25 * price_multiplier * amount;
        if (total_price > gold_avail)
        {
            return false;
        }
        else
        {
            gold_avail -= total_price;
            armor_avail += amount;
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
        if (party.at(party.size() - 1).isArmored())
        {
            armor_avail--;
        }
        party.erase(party.begin() + party.size() - 1);
        weapons.erase(weapons.begin() + party.size() - 1);
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
    // TODO add condition to check for number of cleared rooms, base monster level off that
    // ALSO add condition to check if we are opening a door, choose monster two levels above # of rooms cleared (up to room 4)
    // also add condition so sorcerer not picked until last room
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
                break; // NOTE TO SELF, REMOVE AFTER TESTING FIGHT() TODO
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
 * 1. initialize int outcome = 0, generate random number between 1 and 100
 * 2. if random number is between 1 and 10, player gets key, print, "You found a key!", outcome = 1
 * 3. else if random number is between 11 and 30, player finds treasure, determine appropriate treasure and print result, outcome = 2
 * 4. else if random number is between 31 and 50, outcome = 3
 * 5. else print, "nothing happened." and outcome = 4
 * 6. return outcome
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
    int choice, total_price, quantity;
    double price_multiplier = 1 + level * .25;
    char confirmation;
    bool purchase_return;

    cout << "If you're looking to get supplies, you've come to the right place." << endl;
    cout << "I would be happy to part with some of my wares...for the proper price!" << endl;

    do
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

        switch (choice)
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

            switch (confirmation)
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
        case 2:
            cout << "I have a several types of cookware, which one would you like?" << endl;
            cout << "Each type has a different probability of breaking when used, marked with (XX%)." << endl;
            cout << endl;
            cout << "Choose one of the following (0 to cancel):" << endl;
            cout << "1. (25%) Ceramic Pot [" << 2 * price_multiplier << " Gold]" << endl;
            cout << "2. (10%) Frying Pan [" << 10 * price_multiplier << " Gold]" << endl;
            cout << "3. ( 2%) Cauldron [" << 20 * price_multiplier << " Gold]" << endl;
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
                total_price = quantity * price_multiplier * 20;
                cout << "You want to buy " << quantity << " Cauldron(s) for " << total_price << " gold? (y/n)" << endl;
                cin >> confirmation;
                switch (confirmation)
                {
                case 'y':
                    purchase_return = purchaseItem("cauldron", quantity);
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

    if (player_answer != riddle_solution)
    {
        cout << "Wrong answer!" << endl;
        Monster summoned = pickMonster();
        cout << endl;
        cout << "A " << summoned.getName() << " is approaching! Fight (f) or surrender (s)?" << endl;
        cin >> choice;
        do
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
        cout << "Would you like to barter for some goods?" << endl;
        displayMerchantMenu(rooms_cleared);
    }
}

/**
 * algorithm: checks game status to determine whether player has lost, won, or if the game is in progress
 * 1. if either main player is dead, or there are less than 2 party members, return "lost"
 * 2. else if the player is at the exit tile and there are 2 or more party members remaining, and all the rooms have been cleared return "won"
 * 3. else return "in progress"
 */
string Game::gameResult(bool on_exit)
{
    string result;
    bool leader_alive = false;

    // see if the leader is still alive
    for (int i = 0; i < num_party_members; i++)
    {
        if (party.at(i).getLeadership())
        {
            leader_alive = true;
        }
    }

    if (leader_alive == false)
    {
        result = "lost";
        cout << "The leader is dead. Game over." << endl;
        setGameOver(true);
    }
    else if (num_party_members < 2 && leader_alive)
    {
        result = "lost";
        cout << "There are less than two party members left. Game over." << endl;
        setGameOver(true);
    }
    else if (num_party_members >= 2 && on_exit && rooms_cleared == 5 && leader_alive)
    {
        result = "won";
        cout << "Congratulations! You escaped the dungeon!" << endl;
        setGameOver(true);
    }
    else if (num_party_members >= 2 && rooms_cleared < 5 && leader_alive)
    {
        result = "in progress";
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
void Game::misfortune(int misfortune_chance)
{
    
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
    for (int i = 0; i < num_party_members; i++)
    {
        Player current = party.at(i);
        int fullness = current.getFullness();
        if (fullness == 0 && current.isStarving())
        {
            if (current.getLeadership())
            {
                cout << "You died. Game over." << endl;
                setGameOver(true);
            }
            else
            {
                num_party_members--;
                party.erase(party.begin() + i);
                cout << current.getName() << " starved to death. There are " << num_party_members << " party members remaining." << endl;
            }
            i--;
        }
        else if (fullness = 0 && !current.isStarving())
        {
            current.setStarving(true);
            cout << current.getName() << " is starving. Cook and some food and eat to replenish their fullness or they will die." << endl;
        }
    }
}

/**
 * algorithm: display the door puzzle, determine whether player wins or loses, calculate result (player dies, or party gains access to room)
 * 1. initalize int outcome = -1, char for computer choice, char for player choice
 * 2. do while outcome == 3 (player and computer tie):
 * 3. randomize char for computer choice
 * 4. prompt player for player choice input
 * 5. calculate outcome
 * 6. outcome = 1 if player wins
 * 7. outcome = 2 is computer wins
 * 8. return outcome
 */
int Game::displayDoorPuzzle()
{
    return 0;
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
    string riddles_with_solutions [2];
    int num_elements = 0;
    int counter = 0;
    ifstream input_file;

    input_file.open(riddle_file);
    if (input_file.fail())
    {
        return -1;
    }
    while (!input_file.eof())
    {
        getline(input_file, file_line);
        num_elements = split(file_line, '~', riddles_with_solutions, 2);
        riddles.push_back(riddles_with_solutions[0]);
        riddle_solutions.push_back(riddles_with_solutions[1]);
        counter++;
    }
    return counter;
}