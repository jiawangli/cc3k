#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"
#include "enemy.h"

class Player : public Character {
	int gold=0;
public:
	Player();
	Player(int hp, int atk, int def);
	void addGold(int gold);
	int getGold() const;
	~Player();

};

#endif