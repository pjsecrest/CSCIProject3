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

    {
        // TEST MAP CLASS
        Game g;
        Map map1;
        vector<Player> party;
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
    return 0;
}