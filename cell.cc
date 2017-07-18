//
//  cell.cpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#include "cell.h"

using namespace std;

Cell::Cell(int x, int y, char display) {
    x = x;
    y = y;
    display = display;
    _content = nullptr;
    __content = nullptr;
    numberofneighbours = 0;
    if (display == '.') {
        is_occupied = false;
    }else {
        is_occupied = true;
    }
    is_enemy = false;
    is_item = false;
    is_player = false;
}

void Cell::rmobject() {
    type = '.';
    _content = nullptr;
    __content = nullptr;
    is_occupied = false;
    is_player = false;
    is_item = false;
    is_enemy = false;
}


void Cell::set_item(){
    is_occupied = true;
    is_player = false;
    is_item = true;
    is_enemy = false;
}

void Cell::set_enemy() {
    is_occupied = true;
    is_player = false;
    is_item = false;
    is_enemy = true;
}

void Cell::set_player(){
    is_occupied = true;
    is_player = true;
    is_item = false;
    is_enemy = false;
}


void Cell::set_Display(char type) {
    display = type;
}

void Cell::addNeighbour(Cell* neighbour){
    neighbours[numberofneighbours] = neighbour;
    numberofneighbours++;
}

Cell* Cell::getNeighbour(int pos){
    return neighbours[pos];
}

Character* Cell::getCharacter(){
    return _content;
}

item* Cell::getItem() {
    return __content;
}

Cell::~Cell() {

}