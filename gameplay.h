//
//  gameplay.hpp
//  item
//
//  Created by 姚博伦 on 2017/7/19.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#ifndef gameplay_h
#define gameplay_h

#include <stdio.h>
#include "floor.h"

class Gameplay{
    Floor f;
    vector<Floor*> v;
    Cell *newcord(string dir, int x, int y);
    string attackplayer(Character *nc, Character *player);
public:
    Gameplay();
    Gameplay(string file, int x);
    int create_game();
    int kk();
    string move(string direction);
    string usepotion(string direction);
    string attackenemy(string direction);
    string attackplayer();
    string setplayer(char pc);
    string restart();
    string stop_moving();
    string quit();
};
#endif /* gameplay_h */
