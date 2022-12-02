------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++17 Cookware.cpp, Game.cpp, gameDriver.cpp, Item.cpp, Map.cpp, mapDriver.cpp, Monster.cpp, Player.cpp, Weapon.cpp
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
Cookware.h, Game.h, Item.h, Map.h, Monster.h, Player.h, Treasure.h, Weapon.h must be in the same directory as the cpp files in order to compile.

------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Author: Jack Kriekels and Parker Secrest
Recitation: 302 - Michelle Ramsahoye
Date: Dec 1, 2022

------------------------
ABOUT THIS PROJECT
------------------------
This project is about creating a somewhat complicated text game that is both useable and fun to play.
Dungeon Escape has the premise of a party of people beimng stuck in a dungeon after being trapped by a sorcerer.
The main point of the game is to escape the dungeon, clear all rooms, find keys and treasures and keep as many team members alive in the proccess.
The game has more to it too as you clash with monsters and encounter interesting NPCs along your journey.
While there are endless complexities that can be added the game is already very fun to play as it tracks your progress along the way!



------------------------
HOW TO COMPILE AND RUN
------------------------
Compile: g++ -std=c++17 gameDriver.cpp Game.cpp Item.cpp Weapon.cpp Cookware.cpp Map.cpp Player.cpp Monster.cpp
Run: ./a.out
------------------------
DEPENDENCIES
------------------------
Game.h, Player.h, Monster.h, Item.h, Weapon.h, Cookware.h, and Map.h must be in the same directory as the cpp 
files in order to compile.
------------------------
SUBMISSION INFORMATION
------------------------
CSCI1300 Fall 2022 Project 3
Authors: Parker Secrest and Jack Kriekels
Recitation: 304 - Nikhith Sannidhi
Date: December 1, 2022
------------------------
ABOUT THIS PROJECT
------------------------
This project is developing a game based on the game Dungeons and Dragons. The game follows this general outline:
The party starts in a dungeon, trapped by an evil Sorcerer. They must navigate the dungeon, fighting monsters, unlocking rooms,
avoiding traps, and talking to NPCs. To escape the dungeon the player and his party must beat all five rooms in the dungeon.
The ultimate goal will be to have as many players left alive and materials at the end of the game as possible, which results in a higher score.
All of this must be done before the sorcerer's anger level reaches 100, in which case the sorcerer will destory the dungeon along with the player's party in it.
