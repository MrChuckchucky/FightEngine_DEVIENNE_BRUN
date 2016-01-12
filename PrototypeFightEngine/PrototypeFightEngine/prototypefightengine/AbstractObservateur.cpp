#include "stdafx.h"
#include "AbstractObservateur.h"


AbstractObservateur::AbstractObservateur()
{
}


AbstractObservateur::~AbstractObservateur()
{

}

void AbstractObservateur::addObservable(AbstractObservable * observable)
{
	mObservables->push_back(observable);
}

void AbstractObservateur::delObservable(AbstractObservable * observable)
{
	for (std::vector<AbstractObservable*>::iterator it = mObservables->begin(); it != mObservables->end(); ++it)
	{
		if (*it == observable)
		{
			mObservables->erase(it);
			return;
		}
	}
}
