#include "TextureManager.h"
#include <stdio.h>
//Global static pointer used to ensure a single instance of the clas
TextureManager* TextureManager::s_tInstance = 0;

TextureManager* TextureManager::Instance(){

	if(s_tInstance == 0) //Allow one instance of the class to be created
		s_tInstance = new TextureManager();
	
	return s_tInstance;

}

void TextureManager::clearFromTextureMap(std::string id)
{
	textureMap.erase(id);
}

bool TextureManager::load(const char* fileName, string id, SDL_Renderer* pRenderer){

	bool returnValue = true;
	printf("%s\n", fileName);
	SDL_Surface* tempSurface = IMG_Load(fileName);
	if(tempSurface == NULL){
		printf("Image could not be loaded! %s", SDL_GetError());
		returnValue = false;
	}else{
		texture = SDL_CreateTextureFromSurface(pRenderer, tempSurface);
		SDL_FreeSurface(tempSurface);
		if(texture != 0)
			textureMap[id] = texture;
	}

	return returnValue;
}

void TextureManager::draw(string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip){

	SDL_Rect sourceRect;
	SDL_Rect destRect;

	sourceRect.x = 0;
	sourceRect.y = 0;
	sourceRect.w = destRect.w = width;
	sourceRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, textureMap[id], &sourceRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int width, int height, int currentRow, int CurrentFrame,SDL_Renderer* pRenderer, SDL_RendererFlip flip){

	SDL_Rect sourceRect;
	SDL_Rect destRect;

	sourceRect.x = width * CurrentFrame;
	sourceRect.y = height * (currentRow- 1);
	sourceRect.w = destRect.w = width;
	sourceRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(pRenderer, textureMap[id], &sourceRect, &destRect, 0, 0, flip);

}

