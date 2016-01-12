#ifndef __ONEKICK__
#define __ONEKICK__

#include "Combo.h"
#include "Kick.h"
#include "AbstractAttack.h"
#include <vector>

class OneKick : public Combo
{
private:
	std::vector<AbstractAttack*>* mOneKick;
public:
	OneKick();
	~OneKick();
};
#endif