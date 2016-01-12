#ifndef __ABSTRACTARENA__
#define __ABSTRACTARENA__

#include <string>

class AbstractArena
{
protected:
	std::string mName;
	float mSize;
public:
	AbstractArena(std::string name, float size);
	~AbstractArena();

	std::string getName();
};

#endif