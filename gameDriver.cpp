#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>
#include "Game.h"
#include "Item.h"
#include "Monster.h"
#include "Player.h"
#include "Treasure.h"
#include "Weapon.h"
using namespace std;

int main()
{   
    Game new_game;
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Player p4("Player4");
    Player p5("Player5");

    new_game.readMonsters("monsters.txt");

    {
        // TESTS FOR PLAYER CLASS
        
    }

    return 0;
}