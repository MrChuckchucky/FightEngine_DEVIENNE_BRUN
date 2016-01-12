#include "stdafx.h"
#include "PlayerManager.h"
#include <iostream>
#include "Windows.h"

PlayerManager* PlayerManager::instance = nullptr;

PlayerManager::PlayerManager()
{
	mPlayersFighting = new std::vector<AbstractCharacter*>;
}


PlayerManager::~PlayerManager()
{
	delete mPlayersFighting;
}

PlayerManager * PlayerManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new PlayerManager();
	}
	return instance;
}

void PlayerManager::setPlayersFighting(std::vector<std::string> playersSelected)
{
	std::vector<AbstractState*>* states = new std::vector<AbstractState*>;
	std::vector<AbstractAttack*>* attacks = new std::vector<AbstractAttack*>;

	states->push_back(new InAttack(1));
	states->push_back(new Idle());
	states->push_back(new Guard());
	states->push_back(new InMovement());
	states->push_back(new Stun(2));

	attacks->push_back(new Punch(1, 1, 1));

	mPlayersFighting->push_back(new Rossignol(states));
	mPlayersFighting->push_back(new Octopus(states));
}

std::vector<AbstractCharacter*>* PlayerManager::getPlayersFighting()
{
	return mPlayersFighting;
}

void PlayerManager::initializeVariable(MenuManager* menuInstance)
{
	std::vector<AbstractState*>* states = new std::vector<AbstractState*>;
	states->push_back(new Idle());
	states->push_back(new InAttack(1));
	states->push_back(new Guard());
	states->push_back(new Stun(1));
	states->push_back(new InMovement());
	std::vector<std::string>::iterator it = menuInstance->getPlayerSelected()->begin();

	if ( (*it).compare("Rossignol") != 0 )
	{
		mPlayersFighting->push_back(new Octopus(states));
		mPlayersFighting->push_back(new Rossignol(states));
	}
	else
	{
		mPlayersFighting->push_back(new Rossignol(states));
		mPlayersFighting->push_back(new Octopus(states));
	}
}

void PlayerManager::attack(int number, int multiplicator)
{
	int n = (1 - number);
	std::vector<AbstractCharacter*>::iterator it = mPlayersFighting->begin() + n;
	(*it)->receiveDamage(multiplicator);
}

void PlayerManager::printWinner(char* name)
{
	std::cout << "And the winner is";
	for (int i = 0; i < 10; i++)
	{
		std::cout << ".";
		Sleep(500);
	}
	std::cout << "." << std::endl;

	std::vector<AbstractCharacter*>::iterator it = mPlayersFighting->begin();
	
	if ((*it)->getName().compare(name) == 0)
	{
		std::cout << "YOU !!! Bravo !!!" << std::endl;
	}
	else
	{
		std::cout << "Pas You !! You are nul !!" << std::endl;
	}
	system("pause");
	exit(0);
}
