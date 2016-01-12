#include "stdafx.h"
#include "OneKick.h"


OneKick::OneKick() : Combo("OneKick")
{
	mOneKick = new std::vector<AbstractAttack*>();
	mOneKick->push_back(new Kick(1, 1, 1));
}


OneKick::~OneKick()
{
	delete mOneKick;
}