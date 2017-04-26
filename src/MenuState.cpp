#include "MenuState.h"
#include "TextureManager.h"
#include "game.h"
#include "MenuButton.h"
#include "PlayState.h"
#include <stdio.h>
using namespace std;

const string MenuState::s_menuID = "MENU";

void MenuState::update(){
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render(){
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter(){
	if(!TextureManager::Instance()->load("src/assets/playButton.png", "playButton", Game::Instance()->getRenderer())){
		return false;
	}
	if(!TextureManager::Instance()->load("src/assets/exitButton.png", "exitButton", Game::Instance()->getRenderer())){
		return false;
	}
	GameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playButton"), s_menuToPlay);
	GameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitButton"), s_exitFromMenu);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	printf("entering MenuState\n");
	return true;
}

bool MenuState::onExit(){
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
	m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("playButton");
	TextureManager::Instance()->clearFromTextureMap("exitButton");

	printf("exiting MenuState\n");

	return true;
}

void MenuState::s_menuToPlay(){
	Game::Instance()->getStateMachine()->changeState(new PlayState());
	printf("Play button clicked\n");
}
void MenuState::s_exitFromMenu(){
	printf("Exit button clicked\n");
	Game::Instance()->quit();
}