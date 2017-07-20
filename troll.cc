//
//  troll.cpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#include "troll.h"
#include "character.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// default ability of troll: 120 HP, 25 Atk, 15 Def
Troll::Troll(): Player(120, 25, 15){
    this->type="troll";
}

string Troll::attack(Character *ec){
    int damage=(int)(atk*(100.0/(100.0+ec->getDef())));
    int newHp;
    if(ec->getHp()-damage<0){ // hp cannot be zero
        newHp=0;
    }else{
        newHp=ec->getHp()-damage;
    }
    ostringstream ss;
    if(rand()%100 < 50 && ec->getType()=="halfling"){ // 50% chance miss
        return "PC misses the attack on halfling.";
    }
    
    // other races
    ec->setHp(newHp);
    ss << "PC deals " << damage << " damage to " << ec->getType()
    << " (" << ec->getHp() << " HP).";
    return ss.str();
}

void Troll::trollAddHp(){
    hp+=5;
    if(hp>maxHp) hp=120;
}

void Troll::reset(){
    setAtk(25);
    setDef(15);
}

Troll::~Troll() {}

