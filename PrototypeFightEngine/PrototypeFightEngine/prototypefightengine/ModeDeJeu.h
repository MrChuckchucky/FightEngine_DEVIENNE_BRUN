#ifndef __MODEDEJEU__
#define __MODEDEJEU__

#include <string>
#include <vector>

class ModeDeJeu
{
protected:
	std::string mName;
	int mNumberOfFights;
	int mNumberPlayer;
public:
	ModeDeJeu(std::string name, int numberOfFights, int numberPlayer);
	~ModeDeJeu();

	//virtual void launch();

	int getNumberPlayer();
	void setNumberPlayer(int numberPlayer);
};

#endif