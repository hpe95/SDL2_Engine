#ifndef __GAMESTATEMACHINE__
#define __GAMESTATEMACHINE__

#include "GameState.h"
#include <vector>
class GameStateMachine{
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();

	void render();
	void update();

private:
	std::vector<GameState*> m_gameStates;
};

#endif