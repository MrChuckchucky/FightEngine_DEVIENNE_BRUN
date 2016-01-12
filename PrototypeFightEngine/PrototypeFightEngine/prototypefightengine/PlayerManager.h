#ifndef __PLAYERMANAGER__
#define __PLAYERMANAGER__

#include "AbstractManager.h"
#include "AbstractCharacter.h"
#include "AbstractState.h"
#include "MenuManager.h"
#include "Rossignol.h"
#include "Octopus.h"
#include "InAttack.h"
#include "Idle.h"
#include "Guard.h"
#include "InMovement.h"
#include "Stun.h"
#include "Punch.h"
#include <vector>
#include <string>

class PlayerManager : public AbstractManager
{
private:
	static PlayerManager* instance;
	std::vector<AbstractCharacter*>* mPlayersFighting;
public:
	PlayerManager();
	~PlayerManager();

	static PlayerManager* getInstance();

	void setPlayersFighting(std::vector<std::string> playersSelected);
	std::vector<AbstractCharacter*>* getPlayersFighting();

	void initializeVariable(MenuManager* menuInstance);
	void attack(int number, int multiplicator);
	void printWinner(char* name);
};

#endif