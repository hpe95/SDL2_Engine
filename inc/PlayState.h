#ifndef __PLAYSTATE__
#define __PLAYSTATE__

#include "GameState.h"
#include "SDLGameObject.h"
#include "Level.h"
#include <vector>
class GameObject;

class PlayState : public GameState{
	
public:
	PlayState(){}
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const {return s_playID;}

private:
	static const std::string s_playID;
	std::vector<GameObject*> m_gameObjects;
	Level* pLevel;
	bool checkCollision(SDLGameObject *p1, SDLGameObject *p2);
};

#endif