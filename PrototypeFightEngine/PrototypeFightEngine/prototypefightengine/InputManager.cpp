#include "stdafx.h"
#include "InputManager.h"

InputManager* InputManager::instance = nullptr;

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

InputManager* InputManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new InputManager();
	}
	return instance;
}

void InputManager::Update()
{
}