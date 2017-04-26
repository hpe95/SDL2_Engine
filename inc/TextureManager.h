#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <map>
#include <string>
using namespace std;

class TextureManager{

	public:
		
		static TextureManager* Instance();

		bool load(const char* fileName, string id, SDL_Renderer* pRenderer);

		void draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

		void drawFrame(string id, int x, int y, int width, int height, int currentRow, int currentFrame,SDL_Renderer* pRenderer,  SDL_RendererFlip flip = SDL_FLIP_NONE);
		void clearFromTextureMap(std::string id);
	private:

		TextureManager(){} //Has to be private, so it cannot be called
		static TextureManager* s_tInstance;
		SDL_Texture* texture;
		map<string, SDL_Texture*> textureMap;
};

#endif