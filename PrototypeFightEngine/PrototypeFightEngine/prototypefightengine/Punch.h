#ifndef __PUNCH__
#define __PUNCH__

#include "AbstractAttack.h"

class Punch : public AbstractAttack
{
public:
	Punch(int damage, float coolDown, float range);
	~Punch();
};

#endif