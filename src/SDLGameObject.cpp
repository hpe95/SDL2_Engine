#include "SDLGameObject.h"
#include "game.h"

SDLGameObject::SDLGameObject(const LoaderParams* pParams) : GameObject(pParams), m_position(pParams->getX(), pParams->getY()), m_velocity(0,0), m_aceleration(0,0){
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextureID();

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
	//m_position += m_velocity;

}

void SDLGameObject::clean(){
	
}

