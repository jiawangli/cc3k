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
Gameplay::Gameplay(): is_hostile{false}, champion{' '}, curr{0}{
    Floor f1;
    Floor f2;
    Floor f3;
    Floor f4;
    Floor f5;
    vector<Floor> v;
    v.push_back(f1);
    v.push_back(f2);
    v.push_back(f3);
    v.push_back(f4);
    v.push_back(f5);
    
}

Gameplay::Gameplay(string file): is_hostile{false}, champion{' '}, curr{0}{
    Floor f1(file,1);
    Floor f2(file,2);
    Floor f3(file,3);
    Floor f4(file,4);
    Floor f5(file,5);
    vector<Floor> v;
    v.push_back(f1);
    v.push_back(f2);
    v.push_back(f3);
    v.push_back(f4);
    v.push_back(f5);
}

Cell* Gameplay::newcord(string dir, int x, int y){
    Cell *c;
    if (dir == "no"){
        c = f.getCell(x - 1, y);
    } else if (dir == "so") {
        c= f.getCell(x + 1, y);
    } else if (dir == "ea") {
        c= f.getCell(x, y + 1);
    } else if (dir == "we") {
        c= f.getCell(x, y - 1);
    } else if (dir == "ne") {
        c= f.getCell(x - 1, y + 1);
    } else if (dir == "nw") {
        c= f.getCell(x - 1, y - 1);
    } else if (dir == "se") {
        c= f.getCell(x + 1, y + 1);
    } else if (dir == "sw"){
        c= f.getCell(x + 1, y - 1);
    }
    return c;
}

string Gameplay::move(string dir){
    v[curr].move_player(dir);//pick up gold
    return "player moves toward" + dir;
}

string Gameplay::usepotion(string dir){
    int row = f.playerX;
    int col = f.playerY;
    Cell *n = newcord(dir, row, col);
    Item *p;
    Character *player;
    
    if(n->display == 'P') {
        p = n->getItem();
        player = (v[curr].getCell(row, col))->getCharacter();
    } else {
        throw "that is not a potion";
    }
    string potion = p->effect(player);
    if(player->getHp() == 0){//player die by using poison
        return "player die!";
    }
    v[curr].DisplayMap();
    return "PC uses " + potion;
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
        player = (v[curr].getCell(row, col)).getCharacter;
    } else {
        return "That is not an enemy";
    }
    if(nc->getType() == "merchant"){
        is_hostile = true;
        info = player->attack(nc);
    } else {
        info = player->attack(nc);
    }
    if(nc->getHp() == 0){//enemy die;
        if(nc->getType() == "human"){
            Treasure gold{"human_normal", nullptr};
            c->rmobject();
            c->set_item(&gold);
        } else if(nc->getType() == "dragon"){
            int len = c->numberofneighbours;
            for(int i = 0; i < len; ++i){
                if(c->getNeighbour(i)->is_item){
                    Item *item = c->getNeighbour(i)->getItem();
                    if(!(item->is_Potion())){
                        item->getdragon() = nullptr;
                    }
                }
            }
        } else if(nc->getType() == "merchant"){
            Treasure gold{"merchant_hoard", nullptr};
            c->rmobject();
            c->set_item(&gold);
        } else{
            player->addGold(nc->getGold());
            c->rmobject();
        }
    }
    return info;
}

string Gameplay::attackplayer(bool is_hostile){
    string info;
    Cell *player = f.getCell(f.playerX, f.playerY);
    Character *pc = player->getCharacter();
    int len = player->numberofneighbours;
    for (int i = 0; i < len; ++i){
        if(player->getNeighbour(i)->is_enemy){
            Character *nc = player->getNeighbour(i)->getCharacter();
            if(nc->getType() == "elf"){
                if(pc->getType() != "drow"){
                    info = nc->attack(pc);
                    info += nc->attack(pc);
                }
            } else if (nc->getType() == "merchant"){
                if(is_hostile){
                    info = nc->attack(pc);
                }
            } else{
                info = nc->attack(pc);
            }
        }else if(player->getNeighbour(i)->is_item){
            Item *item = player->getNeighbour(i)->getItem();
            if(!(item->is_Potion())){
                Character *nc = item->getdragon();
                if(nc->getType() == "dragon"){
                    info = nc->attack(pc);
                }
            }
        }
    }
    if(pc->getHp() == 0){
        return "player die!";
    } else {
        return info;
    }
}

void Gameplay::setplayer(){
    if(champion == 's' || champion == 'd' || champion == 'v'
       || champion == 'g' || champion == 't'){
        v[curr].spawn_player(toupper(champion));
    } else{
        string s = "bad enter";
        throw s;
    }
}

int Gameplay::create_game(){
    cout << "choose a champion" << endl;
    while(true){
        if (cin >> champion){
            try{
                setplayer();
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
    int i = 0;
    while(true){
        string info = "";
        if(cin >> cmd){
            if(cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" || cmd == "ne" ||
               cmd == "nw" || cmd == "se" || cmd == "sw"){
                info = attackplayer();
                if(info == "player die!"){
                    displayall(info);
                    cin >> i;
                    return i;
                } else {
                    info += "\n" + move_player(cmd);
                }
                if(mode == "normal"){
                    v[curr].move_enemy();
                }
                if(v[curr].move_player(cmd) == "true"){
                    if(curr == 4){
                        info = "game win!";
                        displayall(info);
                        cin >> i;
                        return i;
                    } else {
                        info += " and moves to the next floor!";
                        displayall(info);
                        ++curr;
                        set_player(pc, curr);
                    }
                }
                break;
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
                        info += attackplayer();
                        if(info == "player die!"){
                            displayall(info);
                            cin >> i;
                            return i;
                        }
                        s = usepotion(cmd);
                        if(s == "player die!"){
                            displayall(info);
                            cin >> i;
                            return i;
                        } else {
                            info += " and " + s;
                        }
                        if(mode == "normal"){
                            v[curr].move_enemy();
                        }
                        displayall(info);
                        break;
                    case 'a':
                        cin >> cmd;
                        info = attackenemy(cmd);
                        s = attackplayer();
                        if(s == "player die!"){
                            displayall(info);
                            cin >> i;
                            return i;
                        } else {
                            info += " and " + s;
                        }
                        if(mode == "normal"){
                            f.move_enemy();
                        }
                        displayall(info);
                        break;
                    case 'f':
                        if(mode == "normal"){
                            mode = "static";
                            info = "change to normal mode"
                        } else {
                            mode = "normal";
                            info = "change to static mode"
                        }
                        displayall(info);
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

void Gameplay::displayall(string info){
    v[curr].DisplayMap;
    string fullinfo;
    string pc;
    switch(champion){
        case 's':
            pc = "Shade";
        case 'd':
            pc = "Drow";
        case 'v':
            pc = "Vampire";
        case 'g':
            pc = "Goblin";
        case 't':
            pc = "Troll";
    }
    Character * player = (v[curr].getPlayer())->getCharacter();
    cout << "Race: " << pc << " Gold: " << player->getGold() << endl;
    cout << "Hp: " << player->getHp() <<endl;
    cout << "Atk: " << player->getAtk() <<endl;
    cout << "Def: " << player->getDef() <<endl;
    if(info == "player die!" || info == "game win!"){
        fullinfo = info + "1-playagain \n2-quit";
    }
    cout <<"Action: " << info<< endl;
}

//consider player enemy movement after every round

















