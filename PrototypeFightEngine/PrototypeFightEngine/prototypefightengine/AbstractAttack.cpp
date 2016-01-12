#include "stdafx.h"
#include "AbstractAttack.h"


AbstractAttack::AbstractAttack(std::string name)
{
	mName = name;
}


AbstractAttack::~AbstractAttack()
{
}

//Getters
std::string AbstractAttack::getName()
{
	return mName;
}
int AbstractAttack::getDamage()
{
	return mDamage;
}
float AbstractAttack::getCoolDown()
{
	return mCoolDown;
}
float AbstractAttack::getRange()
{
	return mRange;
}

bool AbstractAttack::getIsActive()
{
	return mIsActive;
}

//Setters
void AbstractAttack::setDamage(int damage)
{
	mDamage = damage;
}
void AbstractAttack::setCooldDown(float coolDown)
{
	mCoolDown = coolDown;
}
void AbstractAttack::setRange(float range)
{
	mRange = range;
}

void AbstractAttack::getIsActive(bool isActive)
{
	mIsActive = isActive;
}
