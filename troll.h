//
//  troll.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef troll_h
#define troll_h

#include "player.h"
#include "character.h"

class Troll: public Player{
public:
    Troll();
    string attack(Character *ec) override;
    void trollAddHp() override; // add 5 hp to troll(will not exceed max hp)
    void reset() override;
    ~Troll();
};

#endif /* troll_hpp */
