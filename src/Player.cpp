#include "Player.h"

Player::Player() : SDLGameObject(){

}

void Player::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
}

void Player::draw(){

	SDLGameObject::draw();
}

void Player::handleInput(){
	if(InputHandler::Instance()->joysticksInitialised()){
		if(InputHandler::Instance()->xvalue(0,1) > 0 || 
			InputHandler::Instance()->xvalue(0,1) < 0){
			m_velocity.setX(1 * InputHandler::Instance()->xvalue(0,1));
		}

		if(InputHandler::Instance()->yvalue(0,1) > 0 || 
			InputHandler::Instance()->yvalue(0,1) < 0){
			m_velocity.setY(1 * InputHandler::Instance()->yvalue(0,1));
		}

		if(InputHandler::Instance()->xvalue(0,2) > 0 || 
			InputHandler::Instance()->xvalue(0,2) < 0){
			m_velocity.setX(1 * InputHandler::Instance()->xvalue(0,2));
		}

		if(InputHandler::Instance()->yvalue(0,2) > 0 || 
			InputHandler::Instance()->yvalue(0,2) < 0){
			m_velocity.setY(1 * InputHandler::Instance()->yvalue(0,2));
		}
	}

	//Vector2D target = InputHandler::Instance()->getMousePosition();
	//m_velocity = target - m_position;
	//m_velocity /= 50;

}

void Player::update(){

	
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)){
		m_position.setX(m_position.getX() + 20);
	}

	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)){
		m_position.setX(m_position.getX() + -20);
	}
	
	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)){
		m_velocity.setY(-2);
	}

	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)){
		m_velocity.setY(2);
	}

	if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)){
		m_velocity.setX(0);
		m_velocity.setY(0);
	}
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 50) % 6));
	
	SDLGameObject::update();
}

void Player::clean(){

}
