#include "game.h"
//#include "TextureManager.h"
#include <stdio.h>
#include "PlayState.h"
#include "MenuState.h"

int i = 0;

Game* Game::s_gInstance = 0;

Game* Game::Instance(){

	if(s_gInstance == 0) //Allow one instance of the class to be created
		s_gInstance = new Game();
	
	return s_gInstance;

}

Game::Game(){

}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags){

	
	gameLoop = true;
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		mainWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if(mainWindow != 0){
			renderer = SDL_CreateRenderer(mainWindow, -1, 0);
			if(renderer != 0){
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				//TextureManager::Instance()->load("src/assets/Walk/HLD.png", "walk", renderer);
				//gameObjects.push_back(new Player(new LoaderParams(400, 330, 32, 60, "walk")));
				//gameObjects.push_back(new Enemy(new LoaderParams(400, 330, 32, 60, "walk")));
				//InputHandler::Instance()->initialiseJoysticks();
				m_pGameStateMachine = new GameStateMachine();
				m_pGameStateMachine->changeState(new MenuState());
			}
			else{
				printf("Render draw failed! %s", SDL_GetError());
				gameLoop = false;
			}
		}
		else{
			printf("Main Window could not be created! %s", SDL_GetError());
			gameLoop = false;
		}
	}else{
		printf("SDL COULT NOT BE INITIALIZED! %s", SDL_GetError());
		gameLoop = false;
	}

	return gameLoop;
}

bool Game::running(){
	return this->gameLoop;
}

SDL_Renderer* Game::getRenderer(){
	return this->renderer;
}

GameStateMachine* Game::getStateMachine(){
	return m_pGameStateMachine;
}

void Game::render(){
	
	SDL_RenderClear(renderer);

	//TextureManager::Instance()->draw("walk", 0,0, 22, 27, renderer);
	//TextureManager::Instance()->drawFrame("walk", 100, 100, 22, 27, 1, currentFrame, renderer);
	m_pGameStateMachine->render();

	SDL_RenderPresent(renderer);

}

void Game::clean(){
	
	printf("Closing the game... %d",i);
	i++;
	InputHandler::Instance()->clean();
	SDL_DestroyWindow(mainWindow);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	IMG_Quit();
}

void Game::quit(){
	gameLoop = false;
	clean();
}

void Game::handleEvents(){
	
	InputHandler::Instance()->update();
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)){
		m_pGameStateMachine->changeState(new PlayState());
	}
	//gameLoop = false;
}

void Game::update(){

	currentFrame = int(((SDL_GetTicks() / 50) % 12));
	m_pGameStateMachine->update();
	for(vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++){
		gameObjects[i]->update();
	}
}

/*void Game::draw(){

	for(vector<GameObject*>::size_type i = 0; i != gameObjects.size(); i++){
		gameObjects[i]->draw();
	}
}*/
