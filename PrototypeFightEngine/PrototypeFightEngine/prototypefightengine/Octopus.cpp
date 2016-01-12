#include "stdafx.h"
#include "Octopus.h"
#include "OnePunch.h"
#include "OneKick.h"


Octopus::Octopus(std::vector<AbstractState*>* states) : AbstractCharacter("Octopus", states)
{
	mListCombos->push_back(new OnePunch());
	mListCombos->push_back(new OneKick());
}


Octopus::~Octopus()
{

}