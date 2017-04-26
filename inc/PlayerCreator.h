#ifndef __PLAYERCREATOR__
#define __PLAYERCREATOR__

#include "BaseCreator.h"
#include "Player.h"

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};

#endif