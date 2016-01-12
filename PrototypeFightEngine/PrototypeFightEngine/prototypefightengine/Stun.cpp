#include "stdafx.h"
#include "Stun.h"


Stun::Stun(float timeDuration) : AbstractState("Stun")
{
	mTimeDuration = timeDuration;
}


Stun::~Stun()
{
}
