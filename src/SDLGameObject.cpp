#include "SDLGameObject.h"
#include "game.h"

SDLGameObject::SDLGameObject() : GameObject(){

}

void SDLGameObject::load(const LoaderParams* pParams){
	m_position = Vector2D(pParams->getX(), pParams->getY());
	m_velocity = Vector2D(0,0);
	m_aceleration = Vector2D(0,0);
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();
	m_numFrames = pParams->getNumFrames();
	m_currentRow = 1;
	m_currentFrame = 1;
}

void SDLGameObject::draw(){
	if(m_velocity.getX() >= 0)
		TextureManager::Instance()->drawFrame(this->m_textureID, (int)m_position.getX(), (int)m_position.getY(), this->m_width, this->m_height, this->m_currentRow, this->m_currentFrame, Game::Instance()->getRenderer());
	else
		TextureManager::Instance()->drawFrame(this->m_textureID, (int)m_position.getX(), (int)m_position.getY(), this->m_width, this->m_height, this->m_currentRow, this->m_currentFrame, Game::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);		
}

void SDLGameObject::update(){
	
	m_velocity += m_aceleration;
	m_position += m_velocity;

}

void SDLGameObject::clean(){
	
}

Vector2D& SDLGameObject::getPosition(){
	return m_position;
}

int SDLGameObject::getWidth(){
	return m_width;
}

int SDLGameObject::getHeight(){
	return m_height;
}

