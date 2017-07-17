#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

using namespace std;

class Character {
protected:
	int maxHp=0;
	int hp=0;
	int atk=0;
	int def=0;
	string type="unnamed";
public:
	Character();
	Character(int hp, int atk, int def);
	virtual void attack(Character *ec) = 0;
	string getType() const;
	int getHp() const;
	void setHp(int hp);
	int getMaxHP() const;
	int getAtk() const;
	int setAtk(int atk);
	int getDef() const;
	int setDef(int def);
	virtual ~Character() = 0;
};


#endif
