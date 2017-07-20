//
//  orcs.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef orcs_h
#define orcs_h

#include "enemy.h"
#include "character.h"

class Orcs: public Enemy{
public:
    Orcs();
    string attack(Character *pc) override;
    ~Orcs();
};

#endif /* orcs_hpp */
