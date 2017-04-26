#ifndef __MENUBUTTONCREATOR__
#define __MENUBUTTONCREATOR__

#include "BaseCreator.h"
#include "MenuButton.h"

class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		
		return new MenuButton();
	}
};

#endif