#include "PlayState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "game.h"
#include "Player.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "StateParser.h"
#include "LevelParser.h"
#include <iostream>
using namespace std;

const string PlayState::s_playID = "PLAY";

/*bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if( bottomA <= topB ){return false ;}
	if( topA >= bottomB ){return false ;}
	if( rightA <= leftB ){return false ;}
	if( leftA >= rightB ){return false ;}

	return true;
}*/

void PlayState::update(){
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
		Game::Instance()->getStateMachine()->pushState(new PauseState());

	for(unsigned i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	/*if(checkCollision(dynamic_cast<SDLGameObject*> (m_gameObjects[0]), dynamic_cast<SDLGameObject*> (m_gameObjects[1])))
	{
		Game::Instance()->getStateMachine()->pushState(new GameOverState());
	}*/
}

void PlayState::render(){
	/*for(unsigned i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/

	pLevel->render();
}

bool PlayState::onEnter(){
	
	//StateParser stateParser;
	//stateParser.parseState("xml/test.xml", s_playID, &m_gameObjects, &m_textureIDList);

	LevelParser levelParser;
	pLevel = levelParser.parseLevel("xml/map1.tmx");

	//m_callbacks.push_back(0); //pushback 0 callbackID start from 1
	//m_callbacks.push_back(s_menuToPlay);
	//m_callbacks.push_back(s_exitFromMenu);
	// set the callbacks for menu items
	//setCallbacks(m_callbacks);

	
	cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit(){
	/*for(unsigned i = 0; i < m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for(unsigned i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::Instance()->clearFromTextureMap(m_textureIDList[i]);
	}*/
	cout << "exiting PlayState\n";
	return true;
}