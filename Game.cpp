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
    num_total_weapons, num_clubs, num_spears, num_rapiers, num_axes, num_lonswords, num_total_cookware, num_pots, num_pans, num_cauldrons, num_rings, num_necklaces, num_circlets, num_goblets = 0;
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