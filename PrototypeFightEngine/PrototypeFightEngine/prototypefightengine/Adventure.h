#ifndef __ADVENTURE__
#define __ADVENTURE__

#include "ModeDeJeu.h"

class Adventure : public ModeDeJeu
{
public:
	Adventure(int numberOfFights);
	~Adventure();
};

#endif