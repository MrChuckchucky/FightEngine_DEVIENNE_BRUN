#include "stdafx.h"
#include "AbstractCharacter.h"
#include "GameManager.h"
#include <iostream>

AbstractCharacter::AbstractCharacter(std::string name, std::vector<AbstractState*>* states) : AbstractObservable()
{
	mName = name;
	mLife = 10;
	mStates = states;
	mListCombos = new std::vector<Combo*>();
	addObservateur(GameManager::getInstance());
	currentState = new Idle();
	mListAttackPlayer = new std::vector<AbstractAttack*>();
}


AbstractCharacter::~AbstractCharacter()
{
	delete mStates;
	delete mListCombos;
	currentState = nullptr;
	delete mListAttackPlayer;
}

//Getters
std::string AbstractCharacter::getName()
{
	return mName;
}
int AbstractCharacter::getLife()
{
	return mLife;
}
float AbstractCharacter::getAttackSpeed()
{
	return mAttackSpeed;
}
std::vector<Combo*>* AbstractCharacter::getCombos()
{
	return mListCombos;
}
std::vector<AbstractState*>* AbstractCharacter::getStates()
{
	return mStates;
}
int AbstractCharacter::getMultiplicatorDamage()
{
	return mMultiplicatorDamage;
}

//Setters
void AbstractCharacter::setLife(int life)
{
	mLife = life;
}
void AbstractCharacter::setAttackSpeed(float attackSpeed)
{
	mAttackSpeed = attackSpeed;
}
void AbstractCharacter::addCombo(Combo* combo)
{
	mListCombos->push_back(combo);
}
void AbstractCharacter::delCombo(Combo* combo)
{
	for (std::vector<Combo*>::iterator it = mListCombos->begin(); it != mListCombos->end(); ++it)
	{
		if (*it == combo)
		{
			mListCombos->erase(it);
			return;
		}
	}
}
void AbstractCharacter::setMultiplicatorDamage(int multiplicatorDamage)
{
	mMultiplicatorDamage = multiplicatorDamage;
}

AbstractState * AbstractCharacter::getCurrentState()
{
	return currentState;
}

std::vector<AbstractAttack*>* AbstractCharacter::getListAttackPlayer()
{
	return mListAttackPlayer;
}

void AbstractCharacter::receiveDamage(int damages)
{
	mLife -= damages;
	notify();
}

void AbstractCharacter::changeState(std::string name)
{
	for (std::vector<AbstractState*>::iterator it = mStates->begin(); it != mStates->end(); ++it)
	{
		AbstractState* state = *it;
		if (state->getName() == name)
		{
			currentState = state;
			return;
		}
	}
}

void AbstractCharacter::notify()
{
	for (std::vector<AbstractObservateur*>::iterator it = mObservateurs->begin(); it != mObservateurs->end(); ++it)
	{
		AbstractObservateur* obs = *it;
		obs->updateObservable(this);
	}
}

void AbstractCharacter::setListAttackPlayer(std::vector<AbstractAttack*>* listAttack)
{
	mListAttackPlayer = listAttack;
}

void AbstractCharacter::addAttackPlayer(AbstractAttack * attack)
{
	mListAttackPlayer->push_back(attack);
}
