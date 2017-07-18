#include "character.h"
#include "player.h"

Enemy::Enemy() {}

Enemy::Enemy(int hp, int atk, int def) : Character(hp, atk, def) {};

bool Enemy::getHostile() const {
	return hostile;
}

void Enemy::setHostile(bool hostile) {
	this->hostile = hostile;
}

Enemy::~Enemy() {}