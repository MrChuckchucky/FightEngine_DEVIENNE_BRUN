#ifndef __INPUTMANAGER__
#define __INPUTMANAGER__

#include "AbstractManager.h"

class InputManager : public AbstractManager
{
private:
	static InputManager* instance;
public:
	InputManager();
	~InputManager();

	static InputManager* getInstance();
	void Update();
};

#endif
