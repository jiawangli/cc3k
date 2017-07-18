//
//  dwarf.cpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#include "dwarf.h"
#include "character.h"
#include <stdlib.h>

// default ability of dwarf: 100 HP, 20 Atk, 30 Def
Dwarf::Dwarf(): Enemy(100, 20, 30){
    setHostile(true);
    if(rand()<0.5){
        addGold(1);
    }else{
        addGold(2);
    }
}