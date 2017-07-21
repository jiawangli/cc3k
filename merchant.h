//
//  merchant.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef merchant_h
#define merchant_h

#include "enemy.h"
#include "character.h"

class Merchant: public Enemy{
public:
    Merchant();
    string attack(Character *pc) override;
    ~Merchant();
};

#endif /* merchant_hpp */
