#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"
#include "player.h"

class Enemy : public Character {
	int gold;
	bool hostile;
public:
	Enemy();
	Enemy(int hp, int atk, int def);
	bool getHostile() const;
	void setHostile(bool hostile);
	int getGold() const;
	~Enemy();
};

#endif
