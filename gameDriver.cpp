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
    /*
    {

        // TESTS FOR PLAYER CLASS
        Player p("Player");
        assert(p.getName() == "Player");
        assert(p.getFullness() == 50);
        p.changeFullness(-1);
        assert(p.getFullness() == 49);
        assert(p.isArmored() == false);
        p.equipArmor();
        assert(p.isArmored() == true);

        // TESTS FOR ITEM CLASS
        Item item1("item1", 50);
        assert(item1.getName() == "item1");
        assert(item1.getPrice() == 50);
        item1.setName("new name");
        assert(item1.getName() == "new name");
        item1.setPrice(100);
        assert(item1.getPrice() == 100);

        // TESTS FOR WEAPON CLASS
        Weapon w("new weapon", 2);
        assert(w.getDamageBonus() == 2);
        w.setDamageBonus(1);
        assert(w.getDamageBonus() == 1);

        // TESTS FOR COOKWARE CLASS
        Cookware c("cauldron", .02);
        assert(c.getBreakChance() == .02);
        assert(c.getName() == "cauldron");
        c.setBreakChance(.1);
        assert(c.getBreakChance() == .1);
        c.setName("frying pan");
        assert(c.getName() == "frying pan");

        // TESTS FOR MONSTER CLASS
        Monster m("monster", 3);
        assert(m.getName() == "monster");
        assert(m.getRating() == 3);

        // TESTS FOR GAME CLASS
        Game g;
        assert(g.getRoomsCleared() == 0);
        g.clearRoom();
        assert(g.getRoomsCleared() == 1);
        assert(g.getKeysFound() == 0);
        g.findKey();
        assert(g.getKeysFound() == 1);
        assert(g.getAvailableIngredients() == 0);
        g.setAvailableIngredients(25);
        assert(g.getAvailableIngredients() == 25);
        assert(g.getAvailableArmor() == 0);
        g.setAvailableArmor(5);
        assert(g.getAvailableArmor() == 5);
        assert(g.getAvailableGold() == 100);
        g.spendGold(30);
        assert(g.getAvailableGold() == 70);
        assert(g.getAngerLevel() == 0);
        g.increaseAnger();
        assert(g.getAngerLevel() == 1);
        assert(g.getNumClubs() == 0);
        g.setNumClubs(2);
        assert(g.getNumClubs() == 2);
        assert(g.getNumSpears() == 0);
        g.setNumSpears(2);
        assert(g.getNumSpears() == 2);
        assert(g.getNumRapiers() == 0);
        g.setNumRapiers(2);
        assert(g.getNumRapiers() == 2);
        assert(g.getNumAxes() == 0);
        g.setNumAxes(2);
        assert(g.getNumAxes() == 2);
        assert(g.getNumLongswords() == 0);
        g.setNumLongswords(2);
        assert(g.getNumLongswords() == 2);
        assert(g.getNumPots() == 0);
        g.setNumPots(3);
        assert(g.getNumPots() == 3);
        assert(g.getNumPans() == 0);
        g.setNumPans(1);
        assert(g.getNumPans() == 1);
        assert(g.getNumCauldrons() == 0);
        g.setNumCauldrons(4);
        assert(g.getNumCauldrons() == 4);
        assert(g.getNumRings() == 0);
        g.setNumRings(1);
        assert(g.getNumRings() == 1);
        assert(g.getNumNecklaces() == 0);
        g.setNumNecklaces(3);
        assert(g.getNumNecklaces() == 3);
        assert(g.getNumCirclets() == 0);
        g.setNumCirclets(3);
        assert(g.getNumCirclets() == 3);
        assert(g.getNumGoblets() == 0);
        g.setNumGoblets(3);
        assert(g.getNumGoblets() == 3);
    }
    */
    /*
    { // READMONSTERS, FIGHT() TESTS
        Game game1;

        game1.readMonsters("monsters.txt");

        // cout << "Name: " << m.getName() << endl;
        // cout << "Rating: " << m.getRating() << endl;

        game1.setAvailableArmor(2);
        cout << "Armor added" << endl;

        for (int i = 0; i < 5; i++)
        {
            Weapon temp("Weapon", 0);
            game1.addWeapon(temp);
        }

        int losses = 0;
        int wins = 0;
        cout << losses << endl;
        cout << wins << endl;
        for (int i = 0; i < 100; i++)
        {
            // cout << "Run: " << i << endl;
            Monster m = game1.pickMonster();
            // cout << "Monster picked" << endl;
            double fight_return = game1.fight(m);
            // cout << "Monster fought" << endl;
            if (fight_return <= 0)
            {
                losses++;
            }
            else
            {
                wins++;
            }
        }
        cout << "losses: " << losses << endl;
        cout << "wins: " << wins << endl;
        // cout << fight_return << endl;
    }
    */
    /*
     {
         // TEST MAP CLASS
         Game g;
         Map map1;
         vector<Player> party;
         srand(time(0));
         for (int i = 0; i < 5; i++)
         {
             Player player_new("Player " + i);
             cout << player_new.getName() << endl;
             g.addPlayer(player_new);

             // party.push_back(player_new);
             //  Weapon w("weapon", 0);
             //  g.addWeapon(w);
         }

         g.clearRoom();

         g.setAvailableArmor(1);
         srand(time(0));
         g.readMonsters("monsters.txt");
         map1.addRoom(2, 3);
         map1.addRoom(8, 2);
         map1.addRoom(8, 11);
         map1.addRoom(2, 7);
         map1.addNPC(4, 4);
         map1.addNPC(1, 2);
         map1.addNPC(7, 2);
         map1.addNPC(10, 4);
         map1.displayMap();

         char input;

         do
         {
             g.displayStatusUpdate();
             cout << "what do you want to do?" << endl;
             cin >> input;

             switch (input)
             {
             case 'w':
                 map1.move('w');
                 map1.displayMap();
                 break;
             case 'a':
                 map1.move('a');
                 map1.displayMap();
                 break;
             case 's':
                 map1.move('s');
                 map1.displayMap();
                 break;
             case 'd':
                 map1.move('d');
                 map1.displayMap();
                 break;
             case 'e':
             {
                 int investigate_result = g.investigateSpace();
                 map1.exploreSpace(map1.getPlayerRow(), map1.getPlayerCol());
                 bool fight = false;
                 if (investigate_result == 3)
                 {
                     Monster temp = g.pickMonster();
                     cout << "Look out! A " << temp.getName() << " is approaching!" << endl;
                     cout << "Fight (f) or surrender (s)?" << endl;
                     cin >> input;
                     switch (input)
                     {
                     case 'f':
                     {
                         double fight_return = g.fight(temp);
                         fight = true;
                         break;
                     }
                     case 's':
                         g.surrender();
                         break;
                     default:
                         cout << "Enter a valid input." << endl;
                         break;
                     }
                 }
                 if (!fight)
                 {
                     for (int i = 0; i < g.getNumPartyMembers(); i++)
                     {
                         int fullness_chance = rand() % 100 + 1;
                         if (fullness_chance >= 1 && fullness_chance <= 50)
                         {
                             g.getCurrentPartyMember(i).changeFullness(-1);
                             cout << "Party member's fullness decreased by 1." << endl;
                         }
                     }
                 }
                 break;
             }
             case 'f':
             {
                 Monster monst = g.pickMonster();
                 cout << "You picked a fight with a " << monst.getName() << "!" << endl;
                 double fight_return = g.fight(monst);
                 break;
             }
             case 'c':

                 break;
             default:
                 cout << "Not valid input" << endl;
                 map1.displayMap();
                 break;
             }

         } while (input != 'p');
     }
     {
         // MAP GENERATION
         Game game_1;
         Map map_1;
         game_1.readMonsters("monsters.txt");
         // populate party
         for (int i = 0; i < 5; i++)
         {
             Player p("Player " + i);
             game_1.addPlayer(p);
         }
         // seed the rand() function
         srand(time(0));

         int rand_row_room, rand_col_room, rand_row_npc, rand_col_npc;
         int num_npcs = 0;
         int num_rooms = 0;
         while (num_npcs < 5 || num_rooms < 5)
         {
             rand_row_room = rand() % 11;
             rand_col_room = rand() % 11;
             rand_row_npc = rand() % 11;
             rand_col_npc = rand() % 11;

             if (map_1.isFreeSpace(rand_row_room, rand_col_room) && num_rooms < 5)
             {
                 map_1.addRoom(rand_row_room, rand_col_room);
                 num_rooms++;
             }
             if (map_1.isFreeSpace(rand_row_npc, rand_col_npc) && num_npcs < 5)
             {
                 map_1.addNPC(rand_row_npc, rand_col_npc);
                 num_npcs++;
             }
         }

         // display initial merchant menu
         game_1.displayMerchantMenu(0);

         game_1.displayNPCMenu();
     }

 */

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

    return 0;
}