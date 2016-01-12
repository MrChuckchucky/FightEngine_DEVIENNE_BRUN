#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "AbstractManager.h"
#include "AbstractObservateur.h"
#include "MenuManager.h"
#include <vector>
#include <string>

class GameManager : public AbstractObservateur, public AbstractManager
{
private:
	static GameManager* instance;
	int mTimerRound;
public:
	GameManager();
	~GameManager();

	static GameManager* getInstance();

	void setTimerRound(int timerRound);
	void updateObservable(AbstractObservable* observable) override;
	void initializeVariable(MenuManager* menuInstance);
	void endOfGame(AbstractObservable* observable);
};

#endif