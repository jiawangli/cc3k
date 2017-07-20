//
//  floor.cpp
//  cc3k
//
//  Created by j539li on 2017-07-17.
//  Copyright © 2017 j539li. All rights reserved.
//

#include "floor.h"

//vector<vector<Cell>> grid;
//vector<vector<Cell>> chamber;
//vector<cell> availableCell;

using namespace std;

Floor::Floor() {
    ifstream map("floor.txt");
    char ch = 'a';
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            map.read(&ch,1);
            grid[i][j].Cell(i,j,ch);
        }
    }
    for (int i = 0; i < width; i++) {
        for (int j = 0; j <  height; j++) {
            if (i == 0 || i == 79) {
                if (j == 0 || j == 24) {
                    
                }
            }
        }
    }
    
}


Floor::Floor(string filename, int line) {
    
}


void Floor::set_chamber() {
    
}


void Floor::spawn_player(std::string) {
    
}


void Floor::spawn_potions() {

}


void Floor::spawn_enemies() {
    
}


void Floor::move_enemy() {
    
}


void Floor::move_player(){
    
}


void Floor::DisplayMap() {
    
}

