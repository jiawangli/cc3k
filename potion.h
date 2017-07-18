//
//  potion.h
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#ifndef potion_h
#define potion_h

#include <iostream>
#include <string>
#include "item.h"

class Potion: public Item{
    bool is_drow;
public:
    Potion(string &type, int value, bool is_drow);
    void effect(Character *c);
    ~Potion();
};


#endif /* potion_h */
