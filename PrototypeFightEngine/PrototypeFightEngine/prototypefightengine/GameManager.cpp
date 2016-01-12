#include "stdafx.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "AbstractCharacter.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

GameManager * GameManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new GameManager();
	}
	return instance;
}

//Setter
void GameManager::setTimerRound(int timerRound)
{
	mTimerRound = timerRound;
}

void GameManager::updateObservable(AbstractObservable* observable)
{
	if (((AbstractCharacter*)observable)->getLife() <= 0)
	{
		endOfGame(observable);
	}
}

void GameManager::initializeVariable(MenuManager* menuInstance)
{
	mTimerRound = menuInstance->getTimer();
}

void GameManager::endOfGame(AbstractObservable* observable)
{
	if (  ( (AbstractCharacter*)observable )->getName().compare("Octopus") == 0  )
	{
		PlayerManager::getInstance()->printWinner("Rossignol");
	}
	else
	{
		PlayerManager::getInstance()->printWinner("Octopus");
	}
}