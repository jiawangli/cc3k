//
//  treasure.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include <iostream>
#include "treasure.h"

Treasure::Treasure(string type, int value, Character *dragon): Item{type, value}, dragon{dragon}{}

void Treasure::effect(Character *c) {
    int Gold = c->getGold();
    if(type == "small"){
        c->addGold(Gold + 1);
    } else if(type == "normal") {
        c->addGold(Gold + 2);
    } else if(type == "merchant_hoard") {
        c->addGold(Gold + 4);
    } else if(type == "dragon_hoard") {
        c->addGold(Gold + 6);
    } else {
        cout << "Gold type doesn't exist" << endl;
    }
}
