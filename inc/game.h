#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "GameStateMachine.h"


class Game{

	public:
		//Empty Constructor and Destructor
		
		static Game* Instance();

		//~Game();
		//General functions of the game
		bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
		void update();
		void render();
		void clean();
		void handleEvents();
		void draw();
		SDL_Renderer* getRenderer();
		bool running();
		void quit();
		int getGameWidth() const{
			return m_gameWidth;
		}

		int getGameHeight() const{
			return m_gameHeight;
		}

		GameStateMachine* getStateMachine();
	private:
		

		Game(); //Has to be private, so it cannot be called
		static Game* s_gInstance;		
		//Variable that sets the main game loop
		bool gameLoop = true;
		int currentFrame = 0;


		vector<GameObject*> gameObjects;
		GameStateMachine* m_pGameStateMachine;
		int m_gameWidth;
		int m_gameHeight;
		//GameObject gameObject;
		//Player player;
		SDL_Window* mainWindow = 0;
		SDL_Renderer* renderer = 0;
};

#endif
