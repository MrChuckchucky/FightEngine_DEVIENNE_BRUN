#ifndef __STUN__
#define __STUN__

#include "AbstractState.h"

class Stun : public AbstractState
{
public:
	Stun(float timeDuration);
	~Stun();
};

#endif