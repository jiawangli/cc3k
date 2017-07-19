//
//  gameplay.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/19.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include "gameplay.h"
Gameplay::Gameplay(){
    f = Floor();
}

void Gameplay::move(string direction){
    f.move_player();
    f.DisplayMap();
}
void Gameplay::usepotion(string direction){
    
}
void Gameplay::attackenemy(string direction){
    
}
void Gameplay::attackplayer(){
    
}
void Gameplay::setplayer(char pc){
    
}
void Gameplay::restart(){
    
}
void Gameplay::quit(){
    
}



















