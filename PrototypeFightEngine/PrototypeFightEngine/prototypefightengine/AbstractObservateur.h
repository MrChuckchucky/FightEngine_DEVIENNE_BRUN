#ifndef __ABSTRACTOBSERVATEUR__
#define __ABSTRACTOBSERVATEUR__

#include <vector>
#include "AbstractObservable.h"

class AbstractObservateur
{
protected:
	std::vector<AbstractObservable*> * mObservables;
public:
	AbstractObservateur();
	~AbstractObservateur();

	virtual void updateObservable(AbstractObservable* observable) = 0;
	void addObservable(AbstractObservable* observable);
	void delObservable(AbstractObservable* observable);
};

#endif