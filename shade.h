//
//  shade.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef shade_h
#define shade_h

#include "player.h"
#include "character.h"

class Shade: public Player{
public:
    Shade();
    string attack(Character *ec) override;
    void reset();
};

#endif /* shade_hpp */
