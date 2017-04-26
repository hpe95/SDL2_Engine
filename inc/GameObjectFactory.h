#ifndef __GAMEOBJECTFACTORY__
#define __GAMEOBJECTFACTORY__

#include "BaseCreator.h"

class GameObjectFactory{

public:
	static GameObjectFactory* Instance();
	bool registerType(std::string typeID, BaseCreator* pCreator);
	GameObject* create(std::string typeID);

private:
	GameObjectFactory(){} //Has to be private, so it cannot be called
	static GameObjectFactory* s_tInstance;
	std::map<std::string, BaseCreator*> m_creators;

};

#endif