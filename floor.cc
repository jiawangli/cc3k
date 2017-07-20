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
//    if (map.is_open()) {
//        cout << "file is open" << endl;
//    }
    char ch = 'a';
    //grid[width][height];
    for (int i = 0; i < height; i++) {
        vector<Cell> temp;
        for (int j = 0; j < width; j++) {
            map.read(&ch,1);
            //grid[i][j].Cell();
            //grid[i][j].setCell(i,j,ch);
            Cell a = Cell();
            a.setCell(i,j,ch);
            temp.push_back(a);
            //cout << a.display;
        }
        //cout << endl;
        grid.push_back(temp);
    }
    vector<Cell*> temp1;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width;j++) {
            if (i > 2 && i < 7) {
                if (j < 29 && j > 2) {
                    Cell* a = &(grid[i][j]);
                    temp1.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp1);
    vector<Cell*> temp2;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width;j++) {
            if (i == 3 || i == 4) {
                if (j < 62 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i == 5) {
                if (j < 70 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i == 6) {
                if (j < 73 && j > 38) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if ( i > 6 && i < 13) {
                if (j > 60 && j < 78) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp2);
    vector<Cell*> temp3;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i < 13 && i > 9) {
                if (j > 37 && j < 50) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp3);
    vector<Cell*> temp4;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i < 22 && i > 14) {
                if (j > 3 && j < 25) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }
        }
    }
    chamber.push_back(temp4);
    vector<Cell*> temp5;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 16 || i == 17 || i == 18) {
                if (j > 64 && j < 76) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }else if (i < 22 && i > 18) {
                if (j > 36 && j < 76) {
                    Cell* a = &(grid[i][j]);
                    temp2.push_back(a);
                }
            }
        }
    }
    

//    for (int i = 0; i < width; i++) {
//        for (int j = 0; j <  height; j++) {
//            if (i == 0) {
//                if (j == 0) {
//                    grid[i][j].addNeighbour(&(grid[i+1][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                }else if(j == 24) {
//                    grid[i][j].addNeighbour(&(grid[i+1][j]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                }else{
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i+1][j+1]));
//                }
//            }else if (i == 79) {
//                if (j == 0) {
//                    grid[i][j].addNeighbour(&(grid[i-1][j]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                }else if(j == 24) {
//                    grid[i][j].addNeighbour(&(grid[i-1][j]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                }else{
//                    grid[i][j].addNeighbour(&(grid[i][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j-1]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j]));
//                    grid[i][j].addNeighbour(&(grid[i][j+1]));
//                    grid[i][j].addNeighbour(&(grid[i-1][j+1]));
//                }
//            }else{
//                grid[i][j].addNeighbour(&(grid[i-1][j-1]));
//                grid[i][j].addNeighbour(&(grid[i][j-1]));
//                grid[i][j].addNeighbour(&(grid[i+1][j-1]));
//                grid[i][j].addNeighbour(&(grid[i][j-1]));
//                grid[i][j].addNeighbour(&(grid[i][j+1]));
//                grid[i][j].addNeighbour(&(grid[i-1][j+1]));
//                grid[i][j].addNeighbour(&(grid[i][j+1]));
//                grid[i][j].addNeighbour(&(grid[i+1][j+1]));
//            }
//        }
//    }
}


Floor::Floor(string filename, int floorindex) {
    ifstream map("floor.txt");
    char ch = 'a';
    for (int i = 0; i < height; i++) {
        vector<Cell> temp;
        for (int j = 0; j < width; j++) {
            map.read(&ch,1);
            Cell a = Cell();
            a.setCell(i,j,ch);
            temp.push_back(a);
            //cout << a.display;
        }
        //cout << endl;
        grid.push_back(temp);
    }
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
    for(int i = 0; i < height; i ++) {
        for (int j = 0; j < width; j++) {
            cout << grid[i][j].display;
            //cout << "1";
        }
        //cout << endl;
    }
}

