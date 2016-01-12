#ifndef __ABSTRACTOBSERVABLE__
#define __ABSTRACTOBSERVABLE__

#include <vector>

class AbstractObservateur;

class AbstractObservable
{
protected:
	std::vector<AbstractObservateur*> * mObservateurs;
public:
	AbstractObservable();
	~AbstractObservable();

	void addObservateur(AbstractObservateur* observateur);
	void delObservateur(AbstractObservateur* observateur);
	virtual void notify() = 0;
};

#endif