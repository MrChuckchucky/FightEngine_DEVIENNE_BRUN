#include "stdafx.h"
#include "AbstractArena.h"


AbstractArena::AbstractArena(std::string name, float size)
{
	mName = name;
	mSize = size;
}


AbstractArena::~AbstractArena()
{
}

std::string AbstractArena::getName()
{
	return mName;
}
