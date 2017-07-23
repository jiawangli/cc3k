#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"

class Enemy : public Character {
    bool hostile=true;
public:
	Enemy();
	Enemy(int hp, int atk, int def);
	~Enemy();
};

#endif
