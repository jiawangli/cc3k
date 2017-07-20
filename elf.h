//
//  elf.hpp
//  cc3k
//
//  Created by w43wei on 2017-07-19.
//  Copyright © 2017 w43wei. All rights reserved.
//

#ifndef elf_h
#define elf_h

#include "enemy.h"
#include "character.h"

class Elf: public Enemy{
public:
    Elf();
    string attack(Character *pc) override;
    ~Elf();
};


#endif /* elf_hpp */
