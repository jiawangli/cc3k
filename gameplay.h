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
public:
    Gameplay();
    void move(string direction);
    void usepotion(string direction);
    void attackenemy(string direction);
    void attackplayer();
    void setplayer(char pc);
    void restart();
    void quit();
};
#endif /* gameplay_h */
