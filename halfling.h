//
//  halfling.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef halfling_h
#define halfling_h

#include "enemy.h"
#include "character.h"

class Halfling: public Enemy{
public:
    Halfling();
    string attack(Character *pc) override;
    ~Halfling();
};


#endif /* halfling_hpp */
