#include "stdafx.h"
#include "AbstractObservable.h"
#include "AbstractObservateur.h"


AbstractObservable::AbstractObservable()
{
	mObservateurs = new std::vector<AbstractObservateur*>();
}


AbstractObservable::~AbstractObservable()
{

}

void AbstractObservable::addObservateur(AbstractObservateur * observable)
{
	mObservateurs->push_back(observable);
}

void AbstractObservable::delObservateur(AbstractObservateur * observable)
{
	for (std::vector<AbstractObservateur*>::iterator it = mObservateurs->begin(); it != mObservateurs->end(); ++it)
	{
		if (*it == observable)
		{
			mObservateurs->erase(it);
			return;
		}
	}
}