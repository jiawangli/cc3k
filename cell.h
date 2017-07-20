//
//  cell.hpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#ifndef cell_hpp
#define cell_hpp

#include <iostream>
#include <string>
#include <vector>
#include "character.h"
#include "item.h"

class Cell {
    int x=0;
    int y=0;
    
    Cell *neighbours[9];
    Character *_content;
    Item *__content;
    
public:
    bool is_occupied;
    bool is_enemy;
    bool is_item;
    bool is_player;
    int numberofneighbours;
    char display='.';
    
    Cell();
    void setCell(int x, int y, char type);
    void rmobject();
    void set_enemy();
    void set_player();
    void set_item();
    //void Display();
    void addNeighbour(Cell* neighbour);
    Cell* getNeighbour(int);
    Character* getCharacter();
    Item* getItem();
    ~Cell();
};

#endif /* cell_hpp */
