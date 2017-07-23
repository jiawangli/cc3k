//
//  cell.cpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#include "cell.h"

using namespace std;

void Cell::setCell(int x, int y, char type) {
    this->x = x;
    this->y = y;
    display = type;
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
    //cout << display;
}

Cell::Cell() {
    is_occupied = false;
    is_enemy = false;
    is_player = false;
    is_item = false;
    _content = nullptr;
    __content = nullptr;
}

void Cell::rmobject() {
    display = '.';
    _content = nullptr;
    __content = nullptr;
    is_occupied = false;
    is_player = false;
    is_item = false;
    is_enemy = false;
}


void Cell::set_item(Item* addr){
    display = 'P';
    is_occupied = true;
    is_player = false;
    is_item = true;
    is_enemy = false;
    __content = addr;
    
}

void Cell::set_enemy(Character* addr) {
    is_occupied = true;
    is_player = false;
    is_item = false;
    is_enemy = true;
    _content = addr;
}

void Cell::set_player(){
    is_occupied = true;
    is_player = true;
    is_item = false;
    is_enemy = false;
}

//
//void Cell::Display() {
//    cout << display;
//}

int Cell::getx() {
    return x;
}

int Cell::gety() {
    return y;
}

//void Cell::addNeighbour(Cell* neighbour){
//    neighbours.push_back(neighbour);
//    numberofneighbours++;
//}

Cell* Cell::getNeighbour(int pos){
    return neighbours[pos];
}

Character* Cell::getCharacter(){
    return _content;
}

Item* Cell::getItem() {
    return __content;
}


Cell::~Cell() {

}
