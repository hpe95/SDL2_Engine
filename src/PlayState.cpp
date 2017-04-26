#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "game.h"
#include "Player.h"
#include <iostream>
using namespace std;

const string PlayState::s_playID = "PLAY";

void PlayState::update(){
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render(){
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter(){
	if(!TextureManager::Instance()->load("src/assets/Walk/HLD.png", "walk", Game::Instance()->getRenderer())){
		return false;
	}

	GameObject* player = new Player(new LoaderParams(400, 330, 32, 60, "walk"));
	m_gameObjects.push_back(player);
	cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit(){
	for(int i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::Instance()->clearFromTextureMap("walk");
	cout << "exiting PlayState\n";
	return true;
}