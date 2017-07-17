#include "character.h"

Character::Character() {}

Character::Character(int hp, int atk, int def) : maxHp(hp), hp(hp), atk(atk), def(def) {}


string Character::getType() const {
	return type; 
}
int Character::getHp() const {
	return hp;
}
void Character::setHp(int hp) {
	this->hp = hp;
}
int Character::getMaxHP() const {
	return maxHp;
}
int Character::getAtk() const {
	return atk;
}
int Character::setAtk(int atk) {
	this->atk = atk;
}
int Character::getDef() const {
	return def;
}
int Character::setDef(int def) {
	this->def = def;
}