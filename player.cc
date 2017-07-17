#include "enemy.h"
#include "character.h"

Player::Player() {}

Player::Player(int hp, int atk, int def) : Character(hp, atk, def), gold(0) {}

void Player::addGold(int gold) {
	this->gold += gold;
}

int Player::getGold() const{
	return gold;
}

Player::~Player() {};