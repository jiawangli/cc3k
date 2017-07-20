//
//  vampire.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef vampire_hpp
#define vampire_hpp

#include "player.h"
#include "character.h"

class Vampire: public Player{
public:
    Vampire();
    string attack(Character *ec) override;
    void reset() override;
    ~Vampire();
};


#endif /* vampire_hpp */
