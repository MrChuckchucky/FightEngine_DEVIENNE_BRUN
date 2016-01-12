#include "stdafx.h"
#include "Punch.h"


Punch::Punch(int damage, float coolDown, float range) : AbstractAttack("Punch")
{
	mDamage = damage;
	mCoolDown = coolDown;
	mRange = range;
}


Punch::~Punch()
{
}