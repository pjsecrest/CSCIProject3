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


    { // TODO
        Game game1;

        game1.readMonsters("monsters.txt");
        Monster m = game1.pickMonster();

        double fight_return = game1.fight(m);
        cout << fight_return << endl;


    }


    return 0;
}