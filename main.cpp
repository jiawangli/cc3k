//
//  main.cpp
//  a5
//
//  Created by 姚博伦 on 2017/7/22.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include <stdio.h>
#include "gameplay.h"
#include <iostream>
int main(){
    Gameplay g;
    while(true){
        int i = g.create_game();
        if(i == 1){
            continue;
        } else if(i == 2){
            return 0;
        }
    }
}
