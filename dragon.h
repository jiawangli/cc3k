//
//  dragon.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef dragon_h
#define dragon_h

#include "enemy.h"
#include "character.h"

class Dragon: public Enemy{
public:
    Dragon();
    string attack(Character *pc) override;
    ~Dragon();
};

#endif /* dragon_hpp */
