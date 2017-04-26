/*#include "GameObject.h"

void GameObject::load(int x, int y, int width, int height, string textureID){

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->textureID = textureID;

	this->currentRow = 1;
	this->currentFrame = 1;

}

void GameObject::draw(){

	TextureManager::Instance()->drawFrame(textureID, x, y, width, height, currentRow, currentFrame, TheGame::Instance()->getRenderer());
}

void GameObject::update(){
	x += 1;
}*/