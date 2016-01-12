#include "stdafx.h"
#include "MenuManager.h"

MenuManager* MenuManager::instance = nullptr;

MenuManager::MenuManager()
{
	mPlayerSelected = new std::vector<std::string>;

	mPlayerSelected->push_back("Rossignol");
	mPlayerSelected->push_back("Octopus");

	mNameSelectedMode = "QuickFight";
}


MenuManager::~MenuManager()
{
}

MenuManager * MenuManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new MenuManager();
	}
	return instance;
}

//Getters
std::vector<std::string>* MenuManager::getPlayerSelected()
{
	return mPlayerSelected;
}
std::string MenuManager::getNameSelectedMode()
{
	return mNameSelectedMode;
}
int MenuManager::getTimer()
{
	return mTimer;
}
std::string MenuManager::getSelectedArena()
{
	return mSelectedArena;
}
 //Setters
void MenuManager::setPlayerSelected(std::vector<std::string>* playerSelected)
{
	mPlayerSelected = playerSelected;
}
void MenuManager::setNameSelectedMode(std::string nameSelectedMode)
{
	mNameSelectedMode = nameSelectedMode;
}
void MenuManager::setTimer(int timer)
{
	mTimer = timer;
}
void MenuManager::setSelectedArena(AbstractArena* selectedArena)
{
	mSelectedArena = selectedArena->getName();
}