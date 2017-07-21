//
//  floor.hpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#ifndef floor_h
#define floor_h

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "character.h"
#include "item.h"
#include "cell.h"
#include "enemy.h"
#include "player.h"
#include "treasure.h"
#include "potion.h"
#include "dragon.h"
#include "drow.h"
#include "dwarf.h"
#include "elf.h"
#include "goblin.h"
#include "halfling.h"
#include "merchant.h"
#include "orcs.h"
#include "shade.h"
#include "troll.h"
#include "vampire.h"
#include "human.h"

class Floor {
    int width = 80;
    int height = 25;
    //Cell grid[width][height];
    //Cell** grid;
    vector<vector<Cell>> grid;
    vector<vector<Cell*>> chamber;
    vector<Cell*> availableCell;
    vector<Enemy> listofenmey;
    vector<Potion> listofpotion;
    vector<Treasure> listoftreasure;
    int playerX;
    int playerY;
public:
    Floor();
    Floor(std::string,int);
    void set_chamber();
    void spawn_player(std::string);
    void spawn_potions();
    void spawn_enemies();
    void move_enemy();
    void move_player();
    void DisplayMap();
};

#endif /* floor_hpp */
