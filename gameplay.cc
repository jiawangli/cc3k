//
//  gameplay.cpp
//  item
//
//  Created by 姚博伦 on 2017/7/19.
//  Copyright © 2017年 姚博伦. All rights reserved.
//

#include "gameplay.h"
#include <ctype.h>
#include <sstream>
#include <iostream>
using namespace std;
Gameplay::Gameplay(){
    Floor f1;
    Floor f2;
    Floor f3;
    Floor f4;
    Floor f5;
    vector<Floor*> v(5, nullptr);
    v[1] = &f1;
    v[2] = &f2;
    v[3] = &f3;
    v[4] = &f4;
    v[5] = &f5;
    
}

Gameplay::Gameplay(string file, int x){
}

Cell* Gameplay::newcord(string dir, int x, int y){
    Cell *c;
    if (dir == "no"){
        c = f.getcell(x - 1, y);
    } else if (dir == "so") {
        c= f.getcell(x + 1, y);
    } else if (dir == "ea") {
        c=f.getcell(x, y + 1);
    } else if (dir == "we") {
        c=f.getcell(x, y - 1);
    } else if (dir == "ne") {
        c=f.getcell(x - 1, y + 1);
    } else if (dir == "nw") {
        c=f.getcell(x - 1, y - 1);
    } else if (dir == "se") {
        c=f.getcell(x + 1, y + 1);
    } else if (dir == "sw"){
        c=f.getcell(x + 1, y - 1);
    }
    return c;
}

string Gameplay::move(string dir){
    f.move_player(dir);//pick up gold
    f.DisplayMap();
    return "player moves toward" + dir;
}

string Gameplay::usepotion(string dir){
    int row = f.playerX();
    int col = f.playerY();
    Cell *n = newcord(dir, row, col);
    Item *p;
    Character *player;
    
    if(n->display == 'P') {
        p = n->getItem();
        player = (f.getcell(row, col)).getCharacter;
    } else {
        throw "that is not a potion";
    }
    string potion = p->effect(player);
    if(player->getHp() == 0){//player die by using poison
        
    }
    f.DisplayMap();
    return "pc uses " + potion;
}

string Gameplay::attackenemy(string dir){
    int row = f.playerX();
    int col = f.playerY();
    Cell *c = newcord(dir, row, col);
    Character *nc;
    Character *player;
    string info;
    if(c->display == 'H'| c->display =='W'| c->display =='E' | c->display =='O'
       | c->display == 'M'| c->display == 'D' |c->display =='L') {
        nc = c->getCharacter();
        player = (f.getcell(row, col)).getCharacter;
    } else {
        throw "that is not an enemy";
    }
    if(nc->getType() == "elf"){
        if(player->getType() != "drow"){
            info = player->attack(nc);
            info += player->attack(nc);
        }
    } else {
        info = player->attack(nc);
    }
    f.move_enemy();//attacked enemy doesn't move!!!!!!!!!!!!!!!!;
    // what if player is slain
    if(nc->getHp() == 0){//enemy die;
        if(nc->getType() == "human"){
            c->set_item();//怎么设置成金币item
        } else {
            player->addGold(nc->getGold());
        }
        c->rmobject();
    }
    f.DisplayMap();
    return info;
}

string Gameplay::attackplayer(){
    string info;
    Cell *player = f.getCell(f.playerX, f.playerY);
    Character *pc = player->getCharacter();
    Cell **arr = player->getNeighbour();//get array of pointers
    int len = player->numberofneighbours;
    for (int i = 0; i < len; ++i){
        if(arr[i]->is_enemy){
            Character *nc =arr[i]->getCharacter();
            if(nc->getType() == "elf"){
                if(pc->getType() != "drow"){
                    info = nc->attack(pc);
                    info += nc->attack(pc);
                }
            } else {
                info = nc->attack(pc);
            }
        }
    }
    if(pc->getHp() == 0){
        return "die";
    } else {
        return info;
    }
}

string Gameplay::setplayer(char pc){
    if(pc == 's' || pc == 'd' || pc == 'v' || pc == 'g' || pc == 't'){
        f.spawn_player(toupper(pc));
    } else{
        string s = "bad enter";
        throw s;
    }
}

int Gameplay::create_game(){
    cout << "choose a champion" << endl;
    char c;
    while(true){
        if (cin >> c){
            try{
                setplayer(c);
            } catch(string s){
                cout << s << endl;
            }
            break;
        } else {
            cin.clear();
            cin.ignore();
        }
    }
    string s;
    string cmd;
    string mode = "normal";
    while(true){
        if(cin >> cmd){
            if( cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" || cmd == "ne" ||
               cmd == "nw" || cmd == "se" || cmd == "sw"){
                move(cmd);
                if(mode == "normal"){
                    f.move_enemy();
                    attackplayer();
                }else {
                    attackplayer();
                }
            } else{
                istringstream ss{cmd};
                if(!(ss >> c)){
                    cin.clear();
                    cin.ignore();
                    continue;
                };
                switch (cmd[0]) {
                    case 'u':
                        cin >> cmd;
                        usepotion(cmd);
                        if(mode == "normal"){
                            f.move_enemy();
                            attackplayer();
                        }else {
                            attackplayer();
                        }
                        break;
                    case 'a':
                        cin >> cmd;
                        attackenemy(cmd);
                        if(mode == "normal"){
                            f.move_enemy();
                            s = attackplayer();
                        }else {
                            s = attackplayer();
                        }
                        if(s == "die"){
                            cout << "1-playagain"<< endl << "2-quit" << endl;
                            int i = 0;
                            cin >> i;
                            return i;
                        }
                        break;
                    case 'f':
                        if(mode == "normal"){
                            mode = "stop";
                        } else {
                            mode = "normal";
                        }
                    case 'r':
                        return 1;
                    case 'q':
                        return 2;
                    default:
                        cin.clear();
                        cin.ignore();
                }
            }
        } else{
            cin.clear();
            cin.ignore();
            continue;
        }
    }
}


//consider player enemy movement after every round

















