#include "stdafx.h"
#include "InAttack.h"

InAttack::InAttack(float timeDuration) : AbstractState("InAttack")
{
	mTimeDuration = timeDuration;
}


InAttack::~InAttack()
{
}
