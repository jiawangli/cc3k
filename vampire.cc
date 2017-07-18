//
//  vampire.cpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#include "vampire.h"
#include "character.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

// default ability of vampire: 50 HP, 25 Atk, 25 Def
Vampire::Vampire(): Player(50, 25, 25){
    this->type="vampire";
}

string Vampire::attack(Character *ec){
    int damage=(int)(atk*(100.0/(100.0+ec->getDef())));
    int newHp;
    if(ec->getHp()-damage<0){ // hp cannot be negative
        newHp=0;
    }else{
        newHp=ec->getHp()-damage;
    }
    ostringstream ss;
    if(rand()<0.5 && ec->getType()=="halfling"){ // 50% chance miss
        return "PC misses the attack on halfling.";
    }
    
    // other races
    if(ec->getType()=="dwarf"){ // vampire are allergic to dwarf
        setHp(getHp()-5);       // and lose 5 hp
    }else{
        setHp(getHp()+5);       // gain 5 hp every successful attack
    }
    ec->setHp(newHp);
    ss << "PC deals " << damage << " damage to " << ec->getType()
    << " (" << ec->getHp() << " HP).";
    return ss.str();
}

void Vampire::reset(){
    setAtk(25);
    setDef(25);
}
