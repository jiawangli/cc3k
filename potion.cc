//
//  potion.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/17.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include <iostream>
#include "potion.h"

Potion::Potion(string &type, int value, bool is_drow): Item{type, value}, is_drow{is_drow}{}
void Potion::effect(Character *c){
    int MaxHp = c->getMaxHp();
    int Def = c->getDef();
    int Atk = c->getAtk();
    int Hp = c->getHp();
    if(type == "RH"){
        if((is_drow? Hp + 15: Hp + 10) > MaxHp) {
            c->setHp(MaxHp);
        } else{
            c->setHp(is_drow? Hp + 15: Hp + 10);
        }
    } else if(type == "BA") {
        c->setAtk(is_drow? (int)(Atk + 7.5): Atk + 5);
    } else if(type == "BD") {
        c->setDef(is_drow? (int)(Def + 7.5): Def + 5);
    } else if(type == "PH") {
        if((is_drow? Hp - 15: Hp - 10) <= 0){
            c->setHp(0);
        } else{
            c->setHp(is_drow? Hp - 15:Hp - 10);
        }
    } else if(type == "WA") {
        if((is_drow? (int)(Atk - 7.5): Atk - 5) <= 0){
            c->setAtk(0);
        } else{
            c->setAtk(is_drow? (int)(Atk - 7.5): Atk - 5);
        }
    } else if(type == "WD") {
        if((is_drow? (int)(Def - 7.5): Def - 5) <= 0){
            c->setDef(0);
        } else{
            c->setDef(is_drow? (int)(Def - 7.5): Def - 5);
        }
    } else {
        cout << "potion type doesn't exist" << endl;
    }
}

























