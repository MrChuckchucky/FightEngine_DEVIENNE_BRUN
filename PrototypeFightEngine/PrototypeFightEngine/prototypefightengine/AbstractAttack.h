#ifndef __ABSTRACTATTACK__
#define __ABSTRACTATTACK__

#include <string>
#include <vector>

class AbstractAttack
{
protected:
	std::string mName;
	int mDamage;
	float mCoolDown;
	float mRange;
	bool mIsActive;
public:
	AbstractAttack(std::string name);
	~AbstractAttack();

	std::string AbstractAttack::getName();
	int AbstractAttack::getDamage();
	float AbstractAttack::getCoolDown();
	float AbstractAttack::getRange();
	bool AbstractAttack::getIsActive();

	void AbstractAttack::setDamage(int damage);
	void AbstractAttack::setCooldDown(float coolDown);
	void AbstractAttack::setRange(float range);
	void AbstractAttack::getIsActive(bool isactive);
};

#endif