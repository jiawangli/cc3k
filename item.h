//
//  item.hpp
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#ifndef item_h
#define item_h

#include <iostream>
#include <string>
#include "character.h"
using namespace std;

class Item {
protected:
    string type;
    int value;
public:
    Item(string type, int value);
    virtual void effect(Character &c) = 0;
    virtual ~Item() = 0;
};





#endif /* item_hpp */
