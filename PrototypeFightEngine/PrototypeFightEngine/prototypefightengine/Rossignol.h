#ifndef __ROSSIGNOL__
#define __ROSSIGNOL__

#include "AbstractCharacter.h"

class Rossignol : public AbstractCharacter
{
public:
	Rossignol(std::vector<AbstractState*>* states);
	~Rossignol();
};

#endif
