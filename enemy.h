#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"
#include "player.h"

class Enemy : public Character {
	bool hostile;
public:
	Enemy();
	Enemy(int hp, int atk, int def);
	bool getHostile() const override;
	void setHostile(bool hostile) override;
	~Enemy();
};

#endif
