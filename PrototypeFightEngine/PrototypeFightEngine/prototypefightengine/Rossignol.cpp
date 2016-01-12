#include "stdafx.h"
#include "Rossignol.h"
#include "OnePunch.h"
#include "OneKick.h"
#include <iostream>


Rossignol::Rossignol(std::vector<AbstractState*>* states) : AbstractCharacter("Rossignol", states)
{
	mListCombos->push_back(new OnePunch());
	mListCombos->push_back(new OneKick());
}


Rossignol::~Rossignol()
{

}