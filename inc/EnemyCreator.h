#ifndef __ENEMYCREATOR__
#define __ENEMYCREATOR__

#include "BaseCreator.h"
#include "Enemy.h"
class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};

#endif