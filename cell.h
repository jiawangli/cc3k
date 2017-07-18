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
#include "Character.h"
#include "item.h"

class Cell {
    int x=0;
    int y=0;
    char display=' ';
    Cell *neighbours[9];
    character *_content;
    item *__content;
    
public:
    bool is_occupied;
    bool is_enemy;
    bool is_item;
    bool is_player;
    int numberofneighbours;
    
    Cell(int x, int y, char type);
    void rmobject();
    void set_enemy();
    void set_player();
    void set_item();
    void set_Display(char);
    void addNeighbour(Cell* neighbour);
    Cell* getNeighbour(int);
    character* getCharacter();
    item* getItem();
    ~Cell();
};

#endif /* cell_hpp */
