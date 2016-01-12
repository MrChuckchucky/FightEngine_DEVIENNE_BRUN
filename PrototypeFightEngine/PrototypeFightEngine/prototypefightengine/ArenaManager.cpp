#include "stdafx.h"
#include "ArenaManager.h"

ArenaManager* ArenaManager::instance = nullptr;

ArenaManager::ArenaManager()
{
	mPlayersFighting = new std::vector<AbstractCharacter*>;
	mAllArena = new	std::vector<AbstractArena*>;
}


ArenaManager::~ArenaManager()
{
	delete mPlayersFighting;
	delete mAllArena;
}

ArenaManager* ArenaManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ArenaManager();
	}
	return instance;
}

void ArenaManager::initializeVariable(MenuManager* menuInstance)
{
	std::string nameArena = menuInstance->getSelectedArena();
	for (std::vector<AbstractArena*>::iterator it = mAllArena->begin(); it != mAllArena->end(); ++it)
	{
		if ((*it)->getName() == nameArena)
		{

		}
	}
}