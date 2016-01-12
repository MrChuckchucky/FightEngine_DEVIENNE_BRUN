#include "stdafx.h"
#include "OnePunch.h"


OnePunch::OnePunch() : Combo("OnePunch")
{
	mOnePunch = new std::vector<AbstractAttack*>();
	mOnePunch->push_back(new Punch(1, 1, 1));
}


OnePunch::~OnePunch()
{
	delete mOnePunch;
}