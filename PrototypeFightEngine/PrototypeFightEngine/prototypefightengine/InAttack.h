#ifndef __INATTACK__
#define __INATTACK__

#include "AbstractState.h"

class InAttack : public AbstractState
{
public:
	InAttack(float timeDuration);
	~InAttack();
};

#endif