//
//  main.cpp
//  cc3k
//
//  Created by j539li on 2017-07-18.
//  Copyright © 2017 j539li. All rights reserved.
//

#include <iostream>
#include "floor.h"
#include "cell.h"
#include "character.h"
#include "gameplay.h"


int main(int argc, const char * argv[]) {
//    Floor a;
//    a.DisplayMap();
//    a.move_player("ea");
//    a.move_enemy();
//    a.DisplayMap();
//    a.move_player("ea");
//    a.move_enemy();
//    a.DisplayMap();
    while (1) {
        Gameplay a;
        int i = a.create_game();
        if ( i == 1) {
            continue;
        }else if (i == 2){
            return 0;
        }
    }

}
