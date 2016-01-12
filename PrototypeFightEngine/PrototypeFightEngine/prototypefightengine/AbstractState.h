#ifndef __ABSTRACTSTATE__
#define __ABSTRACTSTATE__

#include <string>

class AbstractState
{
protected:
	std::string mName;
	float mTimeDuration;

public:
	AbstractState(std::string name);
	~AbstractState();

	std::string AbstractState::getName();
	float AbstractState::getTimeDuration();

	void AbstractState::setTimeDuration(float timeDuration);
};

#endif