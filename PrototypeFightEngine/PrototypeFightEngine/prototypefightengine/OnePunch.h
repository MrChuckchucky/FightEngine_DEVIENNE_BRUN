#ifndef __ONEPUNCH__
#define __ONEPUNCH__

#include "Combo.h"
#include "Punch.h"
#include "AbstractAttack.h"
#include <vector>

class OnePunch : public Combo
{
private:
	std::vector<AbstractAttack*>* mOnePunch;
public:
	OnePunch();
	~OnePunch();
};
#endif