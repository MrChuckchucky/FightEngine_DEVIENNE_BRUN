#ifndef __COMBO__
#define __COMBO__

#include "AbstractAttack.h"
#include <vector>
#include <string>

class Combo : public AbstractAttack
{
private:
	std::vector<AbstractAttack*>* mAttacks;
public:
	Combo(std::string name);
	~Combo();

	std::vector<AbstractAttack*>* getAttacks();
	void addAttacks(AbstractAttack* attack);
	void delAttacks(AbstractAttack* attack);
};
#endif