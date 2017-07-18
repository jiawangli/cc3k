//
//  dwarf.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-17.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef dwarf_h
#define dwarf_h

#include "enemy.h"

class Dwarf: public Enemy{
public:
    Dwarf();
    string attack(Character *pc) override;
};


#endif /* dwarf_hpp */
