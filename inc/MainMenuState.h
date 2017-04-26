#ifndef __MAINMENUSTATE__
#define __MAINMENUSTATE__

#include "MenuState.h"
#include "GameObject.h"
#include <vector>
class MainMenuState : public MenuState{
	
public:

	MainMenuState(){};
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const {return s_menuID;}

private:
	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;

	virtual void setCallbacks(const std::vector<Callback>& callbacks);

		// call back functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();
};

#endif