#include "Enemy.h"

Enemy::Enemy() : SDLGameObject(){

}

void Enemy::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::update(){

	m_velocity.setY(1);
	m_currentFrame = int(((SDL_GetTicks() / 50) % 5));
	SDLGameObject::update();
}

void Enemy::clean(){
	
}
