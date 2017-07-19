//
//  drow.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef drow_h
#define drow_h

#include "player.h"
#include "character.h"

class Drow: public Player{
public:
    Drow();
    string attack(Character *ec) override;
    void reset() override;
    ~Drow();
};

#endif /* drow_hpp */
