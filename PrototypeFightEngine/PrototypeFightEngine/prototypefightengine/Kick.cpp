#include "stdafx.h"
#include "Kick.h"


Kick::Kick(int damage, float coolDown, float range) : AbstractAttack("Kick")
{
	mDamage = damage;
	mCoolDown = coolDown;
	mRange = range;
}


Kick::~Kick()
{
}