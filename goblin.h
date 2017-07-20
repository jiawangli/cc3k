//
//  goblin.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef goblin_h
#define goblin_h

#include "player.h"
#include "character.h"

class Goblin: public Player{
public:
    Goblin();
    string attack(Character *ec) override;
    void reset() override;
    ~Goblin();
};

#endif /* goblin_hpp */
