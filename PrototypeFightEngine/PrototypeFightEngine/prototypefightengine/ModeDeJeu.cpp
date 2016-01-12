#include "stdafx.h"
#include "ModeDeJeu.h"


ModeDeJeu::ModeDeJeu(std::string name, int numberOfFights, int numberPlayer)
{
	mName = name;
	mNumberOfFights = numberOfFights;
	mNumberPlayer = numberPlayer;
}


ModeDeJeu::~ModeDeJeu()
{

}

int ModeDeJeu::getNumberPlayer()
{
	return mNumberPlayer;
}
void ModeDeJeu::setNumberPlayer(int numberPlayer)
{
	mNumberPlayer = numberPlayer;
}