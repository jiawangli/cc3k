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
    bool is_hostile;
    char champion;
    vector<Floor> v;
    int curr;
    Cell *newcord(string dir, int x, int y);
    string attackplayer(Character *nc, Character *player);
public:
    Gameplay();
    Gameplay(string file);
    int create_game();
    string move(string direction);
    string usepotion(string direction);
    string attackenemy(string direction);
    string attackplayer();
    void setplayer();
    string restart();
    string stop_moving();
    string quit();
    void displayall(string info);
};
#endif /* gameplay_h */
