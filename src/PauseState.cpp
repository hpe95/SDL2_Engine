#include "PauseState.h"
#include "GameObject.h"
#include "game.h"
#include "MainMenuState.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuButton.h"
#include "StateParser.h"
const string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain(){
	Game::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay(){
	Game::Instance()->getStateMachine()->popState();
}

bool PauseState::onEnter(){
	
	StateParser stateParser;
	stateParser.parseState("xml/test.xml", s_pauseID, &m_gameObjects, &m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);
	setCallbacks(m_callbacks);
	printf("entering PauseState\n");
	return true;
}

bool PauseState::onExit(){
	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}
	InputHandler::Instance()->reset();
	printf("exiting PauseState\n");
	return true;
}


void PauseState::update(){
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PauseState::render(){
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

void PauseState::setCallbacks(const std::vector<Callback>& callbacks)
{
// go through the game objects
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
// if they are of type MenuButton then assign a callback based on the id passed in from the file
		if(dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton =
			dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}