#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams){
}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::update(){

	m_velocity.setY(-1);
	m_currentFrame = int(((SDL_GetTicks() / 50) % 12));
	SDLGameObject::update();
}

void Enemy::clean(){
	
}
