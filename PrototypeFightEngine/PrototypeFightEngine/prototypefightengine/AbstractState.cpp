#include "stdafx.h"
#include "AbstractState.h"


AbstractState::AbstractState(std::string name)
{
	mName = name;
}


AbstractState::~AbstractState()
{
}

//Getters
std::string AbstractState::getName()
{
	return mName;
}
float AbstractState::getTimeDuration()
{
	return mTimeDuration;
}

//Setters
void AbstractState::setTimeDuration(float timeDuration)
{
	mTimeDuration = timeDuration;
}