//
//  human.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef human_h
#define human_h

#include "enemy.h"
#include "character.h"

class Human: public Enemy{
public:
    Human();
    string attack(Character *pc) override;
    ~Human();
};

#endif /* human_hpp */
