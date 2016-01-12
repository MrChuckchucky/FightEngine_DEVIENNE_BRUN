// PrototypeFightEngine.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "MenuManager.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "ArenaManager.h"
#include "InputManager.h"
#include "Punch.h"
#include "Kick.h"
#include <iostream>
#include <cstdlib>
#include "Windows.h"
#include <ctime> 

void boucleMenu(MenuManager* instance);
void boucleFight();
void printStartMenu();
void selectMode();
void selectCharacters();
void selectArena();
void combat();
void afficheCoups();
void afficheDefenses();

int main()
{
	MenuManager* menuInstance = MenuManager::getInstance();
	InputManager* inputInstance = InputManager::getInstance();
	GameManager* gameInstance = GameManager::getInstance();
	PlayerManager* playerInstance = PlayerManager::getInstance();
	ArenaManager* arenaInstance = ArenaManager::getInstance();
	printStartMenu();
	while (true)
	{
		boucleMenu(menuInstance);

		gameInstance->initializeVariable(menuInstance);
		playerInstance->initializeVariable(menuInstance);
		arenaInstance->initializeVariable(menuInstance);

		boucleFight();
		// Code
	}
	return 0;
}

void boucleMenu(MenuManager* instance)
{
	selectMode();
}
void boucleFight()
{
	std::cout << "3" << std::endl;
	Sleep(1000);
	std::cout << "2" << std::endl;
	Sleep(1000);
	std::cout << "1" << std::endl;
	Sleep(1000);
	std::cout << "FIGHT !" << std::endl;
	int tour = 1;
	while (true)
	{
		std::cout << "Preparez-vous tour n " << tour << " de ce combat !" << std::endl;
		combat();
		tour++;
	}
}
void printStartMenu()
{
	std::cout << "Bonjour, bienvenue sur tatati tatata" << std::endl;
}
void selectMode()
{
	char* answer = new char();

	do
	{
		std::cout << "============SELECT MODE==============" << std::endl;
		std::cout << "= Quel mode de jeu preferez-vous ?  =" << std::endl;
		std::cout << "= 1. QuickMatch : Tape 1            =" << std::endl;
		std::cout << "= 2. Tournament : Tape 2            =" << std::endl;
		std::cout << "= 3. Adventure : Tape 3             =" << std::endl;
		std::cout << "= Sinon, pour fermer le jeu : Tape 4=" << std::endl;
		std::cout << "=====================================" << std::endl;
		std::cin >> answer;
		system("cls");
		if (strcmp(answer, "2") == 0 || strcmp(answer, "3") == 0)
		{
			std::cout << "Vous devez acheter la licence Premium pour ce mode de jeu." << std::endl;
		}
	} while (strcmp(answer, "1") != 0 && strcmp(answer, "4") != 0);

	if (strcmp(answer, "4") == 0)
	{
		exit(0);
	}

	do
	{
		system("cls");
		std::cout << "Voulez-vous passer a la selection des perso ?" << std::endl;
		std::cout << "Oui : Tape 1" << std::endl;
		std::cout << "Non : Tape 2" << std::endl;
		std::cin >> answer;
		system("cls");
	} while (strcmp(answer, "1") != 0 && strcmp(answer, "2") != 0);

	if (strcmp(answer, "1") == 0)
	{
		selectCharacters();
	}
	else
	{
		selectMode();
	}
}
void selectCharacters()
{
	char* answer = new char();

	do
	{
		std::cout << "==============SELECT CHARACTERS===============" << std::endl;
		std::cout << "= Quel personnage voulez-vous ?              =" << std::endl;
		std::cout << "= 1. Rossignol : Tape 1                      =" << std::endl;
		std::cout << "= 2. Octopus : Tape 2                        =" << std::endl;
		std::cout << "= Sinon, pour changer de mode de jeu : Tape 3=" << std::endl;
		std::cout << "==============================================" << std::endl;
		std::cin >> answer;
		system("cls");
	} while (strcmp(answer, "1") != 0 && strcmp(answer, "2") != 0 && strcmp(answer, "3") != 0);

	if (strcmp(answer, "3") == 0)
	{
		selectMode();
	}

	do
	{
		system("cls");
		std::cout << "Voulez-vous passer a la selection de l'arene ?" << std::endl;
		std::cout << "Oui : Tape 1" << std::endl;
		std::cout << "Non : Tape 2" << std::endl;
		std::cin >> answer;
		system("cls");
	} while (strcmp(answer, "1") != 0 && strcmp(answer, "2") != 0);

	if (strcmp(answer, "1") == 0)
	{
		selectArena();
	}
	else
	{
		selectCharacters();
	}
}
void selectArena()
{
	char* answer = new char();

	do
	{
		std::cout << "================SELECT ARENA=================" << std::endl;
		std::cout << "= Quel arene voulez-vous ?                  =" << std::endl;
		std::cout << "= 1. arene1 : Tape 1                        =" << std::endl;
		std::cout << "= Sinon, pour changer de personnage : Tape 2=" << std::endl;
		std::cout << "=============================================" << std::endl;
		std::cin >> answer;
		system("cls");
	} while (strcmp(answer, "1") != 0 && strcmp(answer, "2") != 0);

	if (strcmp(answer, "2") == 0)
	{
		selectCharacters();
	}

	do
	{
		system("cls");
		std::cout << "Voulez-vous passer au combat?" << std::endl;
		std::cout << "Oui : Tape 1" << std::endl;
		std::cout << "Non : Tape 2" << std::endl;
		std::cin >> answer;
		system("cls");
	} while (strcmp(answer, "1") != 0 && strcmp(answer, "2") != 0);

	if (strcmp(answer, "1") != 0)
	{
		selectArena();
	}
}

void combat()
{
	std::vector<AbstractCharacter*>::iterator itPlayer = (PlayerManager::getInstance())->getPlayersFighting()->begin();
	std::vector<AbstractCharacter*>::iterator itBot = (PlayerManager::getInstance())->getPlayersFighting()->begin()+1;
	if (((*itPlayer)->getCurrentState())->getName().compare("Stun") != 0)
	{
		std::cout << "Preparez-vous pour votre attaque." << std::endl << "Que faites-vous ?" << std::endl;
		afficheCoups();
	}
	else
	{
		std::cout << "Vous etes stun !!" << std::endl;
		(*itPlayer)->changeState("Idle");
	}
	if (((*itBot)->getCurrentState())->getName().compare("Stun") != 0)
	{
		std::cout << "Preparez-vous a vous defendre." << std::endl;
		afficheDefenses();
	}
	else
	{
		std::cout << "Votre adversaire est stun !!" << std::endl;
		(*itBot)->changeState("Idle");
	}
	int hp = (*itPlayer)->getLife();
	std::cout << "Il vous reste " << hp << " points de vie" << std::endl;
	hp = (*itBot)->getLife();
	std::cout << "Il reste a votre adversaire " << hp << " points de vie" << std::endl;
}

void afficheCoups()
{
	std::vector<AbstractCharacter*>::iterator itBot = (PlayerManager::getInstance())->getPlayersFighting()->begin() + 1;
	std::vector<AbstractCharacter*>::iterator itPlayer = (PlayerManager::getInstance())->getPlayersFighting()->begin();
	AbstractAttack* currentAttack = new AbstractAttack("");
	char* coup = new char();
	char* position = new char();
	int alea = rand() % (4 - 1) + 1;
	int stun = rand() % (11 - 1) + 1;
	do
	{
		std::cout << "===LISTE DES COUPS==" << std::endl;
		std::cout << "= 1. Coup de poing =" << std::endl;
		std::cout << "= 2. Coup de pied  =" << std::endl;
		std::cout << "====================" << std::endl;
		std::cin >> coup;
		system("cls");
	} while (strcmp(coup, "1") != 0 && strcmp(coup, "2") != 0);

	do
	{
		std::cout << "=LISTE DES EMPLACEMENTS=" << std::endl;
		std::cout << "= 1. Tete              =" << std::endl;
		std::cout << "= 2. Buste             =" << std::endl;
		std::cout << "= 3. Jambes            =" << std::endl;
		std::cout << "========================" << std::endl;
		std::cin >> position;
		system("cls");
	} while (strcmp(position, "1") != 0 && strcmp(position, "2") != 0 && strcmp(position, "3") != 0);

	switch (*coup)
	{
	case '1':
		std::cout << "Vous portez un coup de poing ";
		currentAttack = new Punch(1,1,1);
		break;
	case '2':
		std::cout << "Vous portez un coup de pied ";
		currentAttack = new Kick(1, 1, 1);
		break;
	}
	switch (*position)
	{
	case '1':
		std::cout << "a la tete" << std::endl;
		break;
	case '2':
		std::cout << "au buste" << std::endl;
		break;
	case '3':
		std::cout << "aux jambes" << std::endl;
		break;
	}

	if (alea + 48 == int(*position))
	{
		std::cout << "Coup bloque !" << std::endl;
		std::vector<AbstractAttack*>* listAttack = new std::vector<AbstractAttack*>();
		(*itPlayer)->setListAttackPlayer(listAttack);
	}
	else
	{
		std::cout << "Touche !" << std::endl;
		(*itPlayer)->addAttackPlayer(currentAttack);
		bool comboFind = false;
		Combo* combo;
		int multiplicator = 0;
		for (std::vector<Combo*>::iterator it = (*itPlayer)->getCombos()->begin(); it != (*itPlayer)->getCombos()->end(); it++)
		{
			int size = ((*it)->getAttacks()->end() - (*it)->getAttacks()->begin()) - ((*itPlayer)->getListAttackPlayer()->end() - (*itPlayer)->getListAttackPlayer()->begin());
			if (size != 0)
			{
				continue;
			}
			for (std::vector<AbstractAttack*>::iterator itt = (*it)->getAttacks()->begin(); itt != (*it)->getAttacks()->end(); itt++)
			{
				for (std::vector<AbstractAttack*>::iterator itt2 = (*itPlayer)->getListAttackPlayer()->begin(); itt2 != (*itPlayer)->getListAttackPlayer()->end(); itt2++)
				{
					if (itt == (*itPlayer)->getListAttackPlayer()->end() - 1 && (*itt)->getName().compare((*it)->getName()))
					{
						combo = *it;
						comboFind = true;
					}
					else if ((*itt)->getName().compare((*it)->getName()))
					{
						continue;
					}
					break;
				}
				if (comboFind)
				{
					break;
				}
			}
			if (comboFind)
			{
				break;
			}
		}
		if (comboFind)
		{
			multiplicator = (*itPlayer)->getListAttackPlayer()->end() - (*itPlayer)->getListAttackPlayer()->begin();
		}
		else
		{
			multiplicator = 1;
		}
		PlayerManager::getInstance()->attack(0, multiplicator);
		if (stun == 1)
		{
			(*itBot)->changeState("Stun");
		}
	}
}
void afficheDefenses()
{
	std::vector<AbstractCharacter*>::iterator itPlayer = (PlayerManager::getInstance())->getPlayersFighting()->begin();
	std::vector<AbstractCharacter*>::iterator itBot = (PlayerManager::getInstance())->getPlayersFighting()->begin() + 1;
	AbstractAttack* currentAttack = new AbstractAttack("");
	int coup = rand() % (3 - 1) + 1;
	int position = rand() % (4 - 1) + 1;
	int stun = rand() % (11 - 1) + 1;
	char* block = new char();
	do
	{
		std::cout << "===LISTE DES POSITIONS==" << std::endl;
		std::cout << "= 1. Tete              =" << std::endl;
		std::cout << "= 2. Buste             =" << std::endl;
		std::cout << "= 3. Jambes            =" << std::endl;
		std::cout << "========================" << std::endl;
		std::cin >> block;
		system("cls");
	} while (strcmp(block, "1") != 0 && strcmp(block, "2") != 0 && strcmp(block, "3") != 0);

	switch (coup)
	{
		case 1:
			std::cout << "Vous etes attaque par un coup de poing ";
			currentAttack = new Punch(1, 1, 1);
			break;
		case 2:
			std::cout << "Vous etes attaque par un coup de pied ";
			currentAttack = new Kick(1, 1, 1);
			break;
	}

	switch (position)
	{
	case 1:
		std::cout << "a la tete" << std::endl;
		break;
	case 2:
		std::cout << "au buste" << std::endl;
		break;
	case 3:
		std::cout << "aux jambes" << std::endl;
		break;
	}

	if (position + 48 == int(*block))
	{
		std::cout << "Coup bloque !" << std::endl;
		std::vector<AbstractAttack*>* listAttack = new std::vector<AbstractAttack*>();
		(*itBot)->setListAttackPlayer(listAttack);
	}
	else
	{
		std::cout << "Touche !" << std::endl;
		(*itBot)->addAttackPlayer(currentAttack);
		bool comboFind = false;
		Combo* combo;
		int multiplicator = 0;
		for (std::vector<Combo*>::iterator it = (*itBot)->getCombos()->begin(); it != (*itBot)->getCombos()->end(); it++)
		{
			int size = ((*it)->getAttacks()->end() - (*it)->getAttacks()->begin()) - ((*itBot)->getListAttackPlayer()->end() - (*itBot)->getListAttackPlayer()->begin());
			if (size != 0)
			{
				continue;
			}
			for (std::vector<AbstractAttack*>::iterator itt = (*it)->getAttacks()->begin(); itt != (*it)->getAttacks()->end(); itt++)
			{
				for (std::vector<AbstractAttack*>::iterator itt2 = (*itBot)->getListAttackPlayer()->begin(); itt2 != (*itBot)->getListAttackPlayer()->end(); itt2++)
				{
					if (itt == (*itBot)->getListAttackPlayer()->end() - 1 && (*itt)->getName().compare((*it)->getName()))
					{
						combo = *it;
						comboFind = true;
					}
					else if ((*itt)->getName().compare((*it)->getName()))
					{
						continue;
					}
					break;
				}
				if (comboFind)
				{
					break;
				}
			}
			if (comboFind)
			{
				break;
			}
		}
		if (comboFind)
		{
			multiplicator = (*itBot)->getListAttackPlayer()->end() - (*itBot)->getListAttackPlayer()->begin();
		}
		else
		{
			multiplicator = 1;
		}
		PlayerManager::getInstance()->attack(1, multiplicator);
		if (stun == 1)
		{
			(*itPlayer)->changeState("Stun");
		}
	}
}