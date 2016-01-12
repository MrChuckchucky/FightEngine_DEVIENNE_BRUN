#include "stdafx.h"
#include "Combo.h"


Combo::Combo(std::string name) : AbstractAttack(name)
{
	mAttacks = new std::vector<AbstractAttack*>;
}


Combo::~Combo()
{
	delete mAttacks;
}

std::vector<AbstractAttack*>* Combo::getAttacks()
{
	return mAttacks;
}
void Combo::addAttacks(AbstractAttack* attack)
{
	mAttacks->push_back(attack);
}
void Combo::delAttacks(AbstractAttack* attack)
{
	for (std::vector<AbstractAttack*>::iterator it = mAttacks->begin(); it != mAttacks->end(); ++it)
	{
		if (*it == attack)
		{
			mAttacks->erase(it);
			return;
		}
	}
}