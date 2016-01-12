#ifndef __KICK__
#define __KICK__

#include "AbstractAttack.h"

class Kick : public AbstractAttack
{
public:
	Kick(int damage, float coolDown, float range);
	~Kick();
};

#endif