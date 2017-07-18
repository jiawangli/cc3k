#include "cell.h"
#include "character.h"
#include <iostream>

Cell::Cell() {
    is_occupied = false;
    is_enemy = false;
    is_item = false;
    is_player = false;
    numNeighbours = 0;
    _contents = NULL;
}

void Cell::setCell(int x, int y, char display) {
    _x = x;
    _y = y;
    _display = display;
    numNeighbours = 0;
    _contents = NULL;
}

int Cell::x() const {
    return _x;
}

int Cell::y() const {
    return _y;
}

char Cell::display() const {
    return _display;
}

GameObject* Cell::getObject() const {
    return _contents;
}


void Cell::addObject(GameObject *object) {
    _contents = object;
}

void Cell::rmObject() {
    _contents = NULL;
}

void Cell::setDisplay(char c) {
    _display = c;
}

void Cell::addNeighbour(Cell *neighbour) {
    neighbours[numNeighbours] = neighbour;
    numNeighbours += 1;
}

Cell* Cell::getNeighbour(int pos) {
    return neighbours[pos];
}

void Cell::reset() {
    is_occupied = false;
    is_enemy = false;
    is_item = false;
    is_player = false;
    _contents = NULL;
    _display = _original;
}

void Cell::set_potion() {
    _display = '!';
    is_occupied = true;
    is_item = true;
    is_enemy = false;
    is_player = false;
}

void Cell::set_gold() {
    _display = '$';
    is_occupied = true;
    is_item = true;
    is_enemy = false;
    is_player = false;
}