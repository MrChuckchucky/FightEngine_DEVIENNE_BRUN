#ifndef __ARENAMANAGER__
#define __ARENAMANAGER__

#include "AbstractManager.h"
#include "AbstractCharacter.h"
#include "AbstractArena.h"
#include "MenuManager.h"
#include <vector>

class ArenaManager : public AbstractManager
{
private:
	static ArenaManager* instance;
	std::vector<AbstractCharacter*>* mPlayersFighting;
	std::vector<AbstractArena*>* mAllArena;
	std::string* mNameSelectedArena;
public:
	ArenaManager();
	~ArenaManager();

	static ArenaManager* getInstance();

	void initializeVariable(MenuManager* menuInstance);
};

#endif