//
//  cell.hpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#ifndef cell_h
#define cell_h

#include <iostream>
#include <string>
#include <vector>
#include "character.h"
#include "item.h"

class Cell {
    int x=0;
    int y=0;
    
    Cell *neighbours[9]; // gai ****

    
public:
    Character *_content;
    Item *__content;
    bool is_occupied;
    bool is_enemy;
    bool is_item;
    bool is_player;
    int numberofneighbours;
    char display='.';
    
    int getx();
    int gety();
    
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
