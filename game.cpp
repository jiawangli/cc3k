#include "game.h"
#include "global.h"
#include "treasure.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

Game::Game() {
    grid = new Cell*[ROW];
    ifstream map("map.txt");
    char ch = 'z';
    for (int r = 0; r < ROW; r++) {
        grid[r] = new Cell[COL];
        for (int c = 0; c < COL; c++) {
            map.read(&ch, 1);
            grid[r][c].setCell(r, c, ch);
            grid[r][c]._original = ch;
            if (ch != '.' && ch != '+' && ch != '#'){
                grid[r][c].is_occupied = true;
            }
        }
    }
    
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            for (int k = 0; k < 8; ++k) {
                if (is_legal(r + DIRS[k][0], c + DIRS[k][1])) {
                    grid[r][c].addNeighbour(&(grid[r + DIRS[k][0]][c + DIRS[k][1]]));
                } else {
                    grid[r][c].addNeighbour(NULL);
                }
            }
        }
    }
}

void Game::print() {
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            cout << grid[r][c].display();
        }
    }
    cout << "\t\t";
    cout << "Class: " << player->getname() << "\t\t";
    cout << "GP: " << player->getgold() << "\t\t\t";
    cout << "Floor: " << FLOOR;
    cout << endl;
    cout << "\t\t";
    cout << "HP: " << player->getHP() << "/" << player->getMax_HP() << "\t\t\t";
    cout << "Atk: " << player->getATK() << "\t\t\t";
    cout << "Def: " << player->getDEF() << "%" << "\t\t";
    cout << "Turn: " << TURN;
    cout << endl;
}

void Game::spawn_potions() {
    for (int i = 0; i < 10; ++i) {
        int _i, _j;
        for (;;) {
            _i = prng(ROW);
            _j = prng(COL);
            if (is_legal(_i, _j) && grid[_i][_j].display() == '.') {
                break;
            }
        }
        grid[_i][_j].set_potion();
    }
}

void Game::spawn_enemy() {
    for (int i = 0; i < 20; ++i) {
        int _i, _j;
        for (;;) {
            _i = prng(ROW);
            _j = prng(COL);
            if (is_legal(_i, _j) && grid[_i][_j].display() == '.') {
                break;
            }
        }
        int enemy_type = prng(5);
        Enemy *enemy;
        if (enemy_type < 2) {
            enemy = new GridBug(_i, _j);
        } else if (enemy_type < 4) {
            enemy = new Goblin(_i, _j);
        } else if (enemy_type < 5) {
            enemy = new Orc(_i, _j);
        } else {
            enemy = new Merchant(_i, _j);
        }
        enemy->grid = &grid;
        grid[_i][_j].setCell(_i, _j, enemy->getsymbol());
        grid[_i][_j].addObject(enemy);
        grid[_i][_j].is_occupied = true;
        grid[_i][_j].is_enemy = true;
        grid[_i][_j].is_item = false;
        grid[_i][_j].is_player = false;
    }
}

void Game::spawn_player(string race) {
    int i, j;
    for (;;) {
        i = prng(ROW);
        j = prng(COL);
        if (grid[i][j].display() == '.') {
            break;
        }
    }
    switch (race[0]) {
        case 'k':
            player = new Knight(i, j);
            break;
        case 'w':
            player = new Wizard(i, j);
            break;
        case 's':
            player = new Samurai(i, j);
            break;
    }
    grid[i][j].is_occupied = true;
    grid[i][j].is_player = true;
    grid[i][j].setDisplay(player->getsymbol());
    grid[i][j].addObject(player);
    Player* temp = (Player*)grid[i][j].getObject();
    cout << temp->getname();
    player->grid = &grid;
    
}

void Game::spawn_gold() {
    for (int i = 0; i < 10; ++i) {
        int _i, _j;
        for (;;) {
            _i = prng(ROW);
            _j = prng(COL);
            if (is_legal(_i, _j) && grid[_i][_j].display() == '.') {
                break;
            }
        }
        Treasure *gold = new Treasure(_i, _j);
        int gold_type = prng(7);
        if (gold_type == 6) {
            gold->is_dragon_hoard = true;
            gold->setname("Dragon Hoard");
        }
        grid[_i][_j].set_gold();
        grid[_i][_j].addObject(gold);
    }
}

void Game::move_enemy() {
    vector< Cell* > enemies;
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (grid[i][j].is_enemy) {
                enemies.push_back(&(grid[i][j]));
            }
        }
    }
    for (int i = 0; i < enemies.size(); ++i) {
        cout << "hi";
        vector<Cell*> neighbours;
        for (int j = 0; j < 8; ++j) {
            
            Cell* neighbour = enemies[i]->getNeighbour(j);
            if (neighbour == NULL || neighbour->is_occupied) {
                continue;
            }
            neighbours.push_back(neighbour);
        }
        if (neighbours.size() == 0) {
            continue;
        }
        int move_to = prng((uint32_t)(neighbours.size() - 1));
        int x = neighbours[move_to]->x();
        int y = neighbours[move_to]->y();
        Enemy* enemy = (Enemy*) enemies[i]->getObject();
        if (enemy != NULL)
            enemy->move_to(x, y);
    }
    cout << "moved" << endl;
}

