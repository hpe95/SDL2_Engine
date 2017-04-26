#include "game.h"
#include <iostream>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 640;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int agrc, char* argv[]){

	Uint32 frameStart, frameTime;

	if(Game::Instance()->init("Jogo teste", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0)){
		cout << "game init success" << endl;

		while(Game::Instance()->running()){
			frameStart = SDL_GetTicks();
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;

			if(frameTime < DELAY_TIME)	
				SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}
	return 0;
}
