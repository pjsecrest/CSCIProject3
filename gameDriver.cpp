#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include "Game.h"
// #include "Item.h"
// #include "Monster.h"
// #include "Player.h"
// #include "Treasure.h"
// #include "Weapon.h"
using namespace std;

int main()
{
    // STARTING THE GAME
    // create game
    Game g;
    g.readMonsters("monsters.txt");
    g.readRiddles("riddles.txt");

    // create and populate map
    Map m;
    m.resetMap();

    // seed the rand() function
    srand(time(0));

    int rand_row_room, rand_col_room, rand_row_npc, rand_col_npc; // variables for npc and room position
    int num_npcs = 0;
    int num_rooms = 0;
    while (num_npcs < 5 || num_rooms < 5)
    {
        rand_row_room = rand() % 12;
        rand_col_room = rand() % 12;
        rand_row_npc = rand() % 12;
        rand_col_npc = rand() % 12;

        if (m.isFreeSpace(rand_row_room, rand_col_room) && num_rooms < 5) // will run until there are 5 rooms generated
        {
            m.addRoom(rand_row_room, rand_col_room);
            num_rooms++;
        }
        if (m.isFreeSpace(rand_row_npc, rand_col_npc) && num_npcs < 5) // wil run until there are 5 npcs generated
        {
            m.addNPC(rand_row_npc, rand_col_npc);
            num_npcs++;
        }
    }

    // print initial game setup,
    string name;
    cout << "Welcome to Dungeon Escape! What's your name?" << endl;
    cin >> name;
    Player leader(name);
    leader.setLeader(); // adds the party leader and sets status as the leader
    g.addPlayer(leader);

    cout << "Nice to meet you " << name << "! What are your friends names?" << endl;

    // prompt player for party names and populate party
    int count = 1;
    do
    {
        cout << endl;
        cout << "Party member " << count << ":" << endl;
        cin >> name;
        Player temp(name);
        g.addPlayer(temp);
        count++;
    } while (count < 5);

    cout << endl;
    cout << "While searching your surroundings, you found 100 gold to start your journey with. All of a sudden a strange man approaches you..." << endl;
    cout << endl;
    // display initial merchant menu
    g.displayMerchantMenu(0);

    char action, confirmation;     // use these variables for player input
    bool is_exit_unlocked = false; // to tell if the player has met the conditions to win the game and can exit
    do
    {
        // display status update and map
        g.displayStatusUpdate();
        m.displayMap();

        // variables for current player position
        int player_row = m.getPlayerRow();
        int player_col = m.getPlayerCol();

        if (m.isFreeSpace(player_row, player_col)) // displays normal space action menu
        {
            cout << "Select an action:" << endl;
            cout << "| w move up | a: move left | s: move down | d: move right | e: investigate space | c: cook and eat | f: pick a fight | g: give up |" << endl;
            cin >> action;

            // executing actions
            if (action == 'w' || action == 'a' || action == 's' || action == 'd')
            {
                m.move(action);
                g.decFullness();
                if (!m.isExplored(player_row - 1, player_col) && m.isOnMap(player_row - 1, player_col) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row + 1, player_col) && m.isOnMap(player_row + 1, player_col) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row, player_col - 1) && m.isOnMap(player_row, player_col - 1) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row, player_col + 1) && m.isOnMap(player_row, player_col + 1) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
            }
            else if (action == 'e')
            {
                if (m.isExplored(player_row, player_col))
                {
                    cout << "This space has already been explored." << endl;
                }
                else
                {
                    bool fight = false;                            // boolean to see if a player fought, use to avoid applying hunger loss twice
                    m.exploreSpace(player_row, player_col);        // mark space as explored
                    int investigate_return = g.investigateSpace(); // investigate the space
                    if (investigate_return == 3)                   // see if the player must fight, display fight options
                    {
                        // pick a monster from the monsters vector
                        Monster opponent = g.pickMonster(g.getRoomsCleared() + 1);
                        cout << "Look out! A " << opponent.getName() << " (challenge rating " << opponent.getRating() << ") is approaching!" << endl;
                        cout << endl;
                        do
                        {
                            cout << "Would you like to fight (f) or surrender (s)?" << endl;
                            cin >> action;

                            if (action == 'f')
                            {
                                g.fight(opponent);
                            }
                            else if (action == 's')
                            {
                                g.surrender();
                            }
                            else
                            {
                                cout << "Invalid input. Please enter a valid action." << endl;
                                cout << endl;
                            }
                        } while (action != 'f' && action != 's');
                    }
                }
            }
            else if (action == 'c')
            {
                g.cook();
            }
            else if (action == 'f')
            {
                Monster opponent = g.pickMonster(g.getRoomsCleared() + 1);
                cout << "You picked a fight with a " << opponent.getName() << " (challenge rating " << opponent.getRating() << ")!" << endl;
                g.fight(opponent);
            }
            else if (action == 'g')
            {
                do
                {
                    cout << "Are you sure you want to give up? Your progress will not be saved. (y/n)" << endl;
                    cin >> confirmation;

                    if (confirmation == 'y')
                    {
                        cout << "Quitting..." << endl;
                        g.setGameOver(true);
                    }
                    else if (confirmation == 'n')
                    {
                        cout << "Good luck!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter a choose a different option." << endl;
                    }
                } while (confirmation != 'y' && confirmation != 'n');
            }
            else
            {
                cout << "Invalid input. Please enter a valid action." << endl;
            }
        }
        else if (m.isNPCLocation(player_row, player_col)) // display the action options if on an NPC space
        {
            cout << "You encountered a stranger in the dungeon!" << endl;
            cout << endl;
            cout << "Select an action:" << endl;
            cout << "| w move up | a: move left | s: move down | d: move right | t: talk to NPC | g: give up |" << endl;
            cin >> action;

            if (action == 'w' || action == 'a' || action == 's' || action == 'd')
            {
                m.move(action);
                g.decFullness();
                if (!m.isExplored(player_row - 1, player_col) && m.isOnMap(player_row - 1, player_col) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row + 1, player_col) && m.isOnMap(player_row + 1, player_col) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row, player_col - 1) && m.isOnMap(player_row, player_col - 1) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row, player_col + 1) && m.isOnMap(player_row, player_col + 1) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
            }
            else if (action == 't')
            {
                cout << "You approach the stranger and speak with them." << endl;
                g.displayNPCMenu();
                m.removeNPC(player_row, player_col);
            }
            else if (action == 'g')
            {
                do
                {
                    cout << "Are you sure you want to give up? Your progress will not be saved. (y/n)" << endl;
                    cin >> confirmation;

                    if (confirmation == 'y')
                    {
                        cout << "Quitting..." << endl;
                        g.setGameOver(true);
                    }
                    else if (confirmation == 'n')
                    {
                        cout << "Good luck!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter a choose a different option." << endl;
                    }
                } while (confirmation != 'y' && confirmation != 'n');
            }
        }
        else if (m.isRoomLocation(player_row, player_col))
        {
            cout << "You found a room entrance!" << endl;
            cout << "Select an action:" << endl;
            cout << "| w move up | a: move left | s: move down | d: move right | r: open room door | g: give up |" << endl;
            cin >> action;

            if (action == 'w' || action == 'a' || action == 's' || action == 'd')
            {
                m.move(action);
                g.decFullness();
                if (!m.isExplored(player_row - 1, player_col) && m.isOnMap(player_row - 1, player_col) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row + 1, player_col) && m.isOnMap(player_row + 1, player_col) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row, player_col - 1) && m.isOnMap(player_row, player_col - 1) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
                else if (!m.isExplored(player_row, player_col + 1) && m.isOnMap(player_row, player_col + 1) && g.getRoomsCleared() < 5)
                {
                    g.increaseAnger();
                }
            }
            else if (action == 'r')
            {
                if (g.getKeysFound() > 0)
                {
                    g.useKey();
                    cout << "You used a key to open the door." << endl;
                    int monster_level = g.getRoomsCleared() + 2;
                    Monster opponent = g.pickMonster(monster_level);
                    cout << "There was a " << opponent.getName() << " (challenge rating " << opponent.getRating() << ")" << endl;
                    double fight_return = g.fight(opponent);

                    /*
                        there are two different outcomes depending on the fight result
                        1. player loses, they fail to unlock the door, lose a key, and there is a 40% chance of a misfortune happening
                        2. player wins, they clear the room ( and space is explored), and there is a 60% chance of a misfortune occuring
                    */
                    if (fight_return <= 0)
                    {
                        cout << "You failed to unlock the room." << endl;
                        g.useKey();
                        g.misfortune(40);
                    }
                    else
                    {
                        cout << "You cleared the room!" << endl;
                        g.clearRoom();
                        m.removeRoom(player_row, player_col);
                        g.misfortune(60);
                    }
                }
                else
                {
                    cout << "You must solve a puzzle to open this door." << endl;
                    g.displayDoorPuzzle();
                    
                }
            }
            else if (action == 'g')
            {
                do
                {
                    cout << "Are you sure you want to give up? Your progress will not be saved. (y/n)" << endl;
                    cin >> confirmation;

                    if (confirmation == 'y')
                    {
                        cout << "Quitting..." << endl;
                        g.setGameOver(true);
                    }
                    else if (confirmation == 'n')
                    {
                        cout << "Good luck!" << endl;
                    }
                    else
                    {
                        cout << "Invalid input. Please enter a choose a different option." << endl;
                    }
                } while (confirmation != 'y' && confirmation != 'n');
            }
        }
        else if (m.isDungeonExit(player_row, player_col))
        {
            if (!is_exit_unlocked)
            {
                cout << "The exit is locked. Clear all of the rooms to unlock it." << endl;
                cout << "Select an action:" << endl;
                cout << "| w move up | a: move left | s: move down | d: move right | g: give up |" << endl;
                cin >> action;

                if (action == 'w' || action == 'a' || action == 's' || action == 'd')
                {
                    m.move(action);
                    /*
                        checks if the space that is being moved to is explored or not, if it isn't increase the sorcerer anger level
                    */
                    if (!m.isExplored(player_row - 1, player_col) && m.isOnMap(player_row - 1, player_col) && g.getRoomsCleared() < 5)
                    {
                        g.increaseAnger();
                    }
                    else if (!m.isExplored(player_row + 1, player_col) && m.isOnMap(player_row + 1, player_col) && g.getRoomsCleared() < 5)
                    {
                        g.increaseAnger();
                    }
                    else if (!m.isExplored(player_row, player_col - 1) && m.isOnMap(player_row, player_col - 1) && g.getRoomsCleared() < 5)
                    {
                        g.increaseAnger();
                    }
                    else if (!m.isExplored(player_row, player_col + 1) && m.isOnMap(player_row, player_col + 1) && g.getRoomsCleared() < 5)
                    {
                        g.increaseAnger();
                    }

                    g.decFullness();
                }
                else if (action == 'g')
                {
                    do
                    {
                        cout << "Are you sure you want to give up? Your progress will not be saved. (y/n)" << endl;
                        cin >> confirmation;

                        if (confirmation == 'y')
                        {
                            cout << "Quitting..." << endl;
                            g.setGameOver(true);
                        }
                        else if (confirmation == 'n')
                        {
                            cout << "Good luck!" << endl;
                        }
                        else
                        {
                            cout << "Invalid input. Please enter a choose a different option." << endl;
                        }
                    } while (confirmation != 'y' && confirmation != 'n');
                }
            }
            else if (is_exit_unlocked)
            {
                cout << "The exit is unlocked!" << endl;
                cout << "Select an action:" << endl;
                cout << "| w move up | a: move left | s: move down | d: move right | g: give up | r: exit the dungeon |" << endl;
                cin >> action;
                if (action == 'w' || action == 'a' || action == 's' || action == 'd')
                {
                    m.move(action);
                    g.decFullness();
                }
                else if (action == 'r')
                {
                    cout << "Congratulations! You have escaped the dungeon!" << endl;
                    g.setGameOver(true);
                }
                else if (action == 'g')
                {
                    do
                    {
                        cout << "Are you sure you want to give up? Your progress will not be saved. (y/n)" << endl;
                        cin >> confirmation;

                        if (confirmation == 'y')
                        {
                            cout << "Quitting..." << endl;
                            g.setGameOver(true);
                        }
                        else if (confirmation == 'n')
                        {
                            cout << "Good luck!" << endl;
                        }
                        else
                        {
                            cout << "Invalid input. Please enter a choose a different option." << endl;
                        }
                    } while (confirmation != 'y' && confirmation != 'n');
                }
            }
        }

        // check conditions for game end and party starvation
        g.checkFullness();
        string game_result = g.gameResult();
        if (game_result == "won")
        {
            is_exit_unlocked = true;
        }
    } while (!g.isGameOver());

    g.sortScores("scoreboard.txt");

    return 0;
}