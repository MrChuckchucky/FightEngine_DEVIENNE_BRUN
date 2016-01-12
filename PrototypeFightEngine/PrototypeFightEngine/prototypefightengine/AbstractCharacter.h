#ifndef __ABSTRACTCHARACTER__
#define __ABSTRACTCHARACTER__

#include <string>
#include <vector>
#include "Combo.h"
#include "AbstractObservable.h"
#include "AbstractObservateur.h"
#include "AbstractState.h"
#include "AbstractAttack.h"
#include "Idle.h"

class AbstractCharacter : public AbstractObservable
{
protected:
	std::string mName;
	int mLife;
	float mAttackSpeed;
	int mMultiplicatorDamage;
	std::vector<AbstractState*>* mStates;
	std::vector<Combo*>* mListCombos;
	AbstractState* currentState;
	std::vector<AbstractAttack*>* mListAttackPlayer;

public:
	AbstractCharacter(std::string name, std::vector<AbstractState*>* states);
	~AbstractCharacter();

	std::string getName();
	int getLife();
	float getAttackSpeed();
	std::vector<Combo*>* getCombos();
	std::vector<AbstractState*>* getStates();
	int getMultiplicatorDamage();
	void setLife(int life);
	void setAttackSpeed(float attackSpeed);
	void addCombo(Combo* combo);
	void delCombo(Combo* combo);
	void setMultiplicatorDamage(int multiplicatorDamage);
	AbstractState* getCurrentState();
	std::vector<AbstractAttack*>* getListAttackPlayer();

	void receiveDamage(int damages);
	void changeState(std::string name);
	void notify() override;
	void setListAttackPlayer(std::vector<AbstractAttack*>* listAttack);
	void addAttackPlayer(AbstractAttack* attack);
};
 
#endif