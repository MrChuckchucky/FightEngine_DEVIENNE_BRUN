#ifndef __MENUMANAGER__
#define __MENUMANAGER__

#include "AbstractManager.h"
#include "AbstractArena.h"
#include <vector>
#include <string>

class MenuManager : public AbstractManager
{
private:
	static MenuManager* instance;
	std::vector<std::string>* mPlayerSelected;
	std::string mNameSelectedMode;
	int mTimer;
	std::string mSelectedArena;
public:
	MenuManager();
	~MenuManager();

	static MenuManager* getInstance();

	std::vector<std::string>* getPlayerSelected();
	std::string getNameSelectedMode();
	int getTimer();
	std::string getSelectedArena();
	void setPlayerSelected(std::vector<std::string>* playerSelected);
	void setNameSelectedMode(std::string nameSelectedMode);
	void setTimer(int timer);
	void setSelectedArena(AbstractArena* selectedArena);
};

#endif