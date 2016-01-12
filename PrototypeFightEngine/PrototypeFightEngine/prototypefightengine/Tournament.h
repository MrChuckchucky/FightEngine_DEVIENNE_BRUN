#ifndef __TOURNAMENT__
#define __TOURNAMENT__

#include "ModeDeJeu.h"

class Tournament : public ModeDeJeu
{
public:
	Tournament(int numberOfFights, int numberPlayer);
	~Tournament();
};
#endif