#ifndef __OCTOPUS__
#define __OCTOPUS__

#include "AbstractCharacter.h"

class Octopus : public AbstractCharacter
{
public:
	Octopus(std::vector<AbstractState*>* states);
	~Octopus();
};

#endif
