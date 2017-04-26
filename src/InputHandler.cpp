#include "InputHandler.h"
#include "game.h"


InputHandler* InputHandler::s_pInstance = 0;

InputHandler* InputHandler::Instance(){
	
	if(s_pInstance == 0)
		s_pInstance = new InputHandler();

	return s_pInstance;
}

InputHandler::InputHandler(){
	for(int i=0; i<3; i++){
		m_mouseButtonStates.push_back(false);
	}
}

bool InputHandler::joysticksInitialised(){

	return m_bJoystickInitialised;
}


int InputHandler::xvalue(int joy, int stick){
	int axisValue = 0;
	if(m_joystickValues.size() > 0){
		if(stick == 1)
			axisValue = m_joystickValues[joy].first->getX();
		else if(stick == 2)
			axisValue = m_joystickValues[joy].second->getX();
	}

	return axisValue;
}

int InputHandler::yvalue(int joy, int stick){
	int axisValue = 0;
	if(m_joystickValues.size() > 0){
		if(stick == 1)
			axisValue = m_joystickValues[joy].first->getY();
		else if(stick == 2)
			axisValue = m_joystickValues[joy].second->getY();
	}

	return axisValue;
}

void InputHandler::initialiseJoysticks(){
	if(SDL_WasInit(SDL_INIT_JOYSTICK) == 0)
		SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	if(SDL_NumJoysticks() > 0){
		for(int i =0; i < SDL_NumJoysticks() ; i++){
			SDL_Joystick* joy = SDL_JoystickOpen(i);
			if(SDL_JoystickGetAttached(joy) == SDL_TRUE){
				m_joysticks.push_back(joy); // It will possibiliates to deattach the joysticks later...
				m_joystickValues.push_back(std::make_pair(new Vector2D(0,0), new Vector2D(0,0)));
			}
					else
				std::cout << SDL_GetError();
		}

		SDL_JoystickEventState(SDL_ENABLE);
		m_bJoystickInitialised = true;

		std::cout << "Initialised: " << m_joysticks.size() << " joystick(s)";
	}
	else
		m_bJoystickInitialised = false;
}

/*bool InputHandler::getMouseButtonState(int buttonNumber){
	return m_mouseButtonStates[buttonNumber];
}*/

bool InputHandler::isKeyDown(SDL_Scancode key){
	if(m_keystates != 0){
		if(m_keystates[key] == 1){
			return true;
		}
		else{
			return false;
		}
	}

	return false;
}

void InputHandler::clean(){

	if(m_bJoystickInitialised)
		for(int i = 0; i < SDL_NumJoysticks(); i++)
			SDL_JoystickClose(m_joysticks[i]);
}

void InputHandler::update(){
	SDL_Event event;
	m_keystates = SDL_GetKeyboardState(0);
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				Game::Instance()->quit();
			break;

			case SDL_MOUSEMOTION:
				onMouseMove(event);
			break;

			case SDL_MOUSEBUTTONDOWN:

			case SDL_MOUSEBUTTONUP:
				onMouseButtonUpDown(event);
			break;
		}
		/*if(event.type == SDL_MOUSEBUTTONDOWN){
			if(event.button.button == SDL_BUTTON_LEFT){
				m_mouseButtonStates[LEFT] = true;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE){
				m_mouseButtonStates[MIDDLE] = true;
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				m_mouseButtonStates[RIGHT] = true;
			}
		}

		if(event.type == SDL_MOUSEBUTTONUP){
			if(event.button.button == SDL_BUTTON_LEFT){
				m_mouseButtonStates[LEFT] = false;
			}
			if(event.button.button == SDL_BUTTON_MIDDLE){
				m_mouseButtonStates[MIDDLE] = false;
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
				m_mouseButtonStates[RIGHT] = false;
			}
		}
		
		if(event.type == SDL_MOUSEMOTION){
			m_mousePosition.setX(event.motion.x);
			m_mousePosition.setY(event.motion.y);
		}*/

		
		if(event.type == SDL_JOYAXISMOTION){
			int whichOne = event.jaxis.which; // get which joystick an event came from
			if(event.jaxis.axis == 0){ // left stick move left or right
				if(event.jaxis.value > m_joystickDeadZone)
					m_joystickValues[whichOne].first->setX(1);
				else if(event.jaxis.value < -m_joystickDeadZone)
					m_joystickValues[whichOne].first->setX(-1);
				else
					m_joystickValues[whichOne].first->setX(0);
			}

			if(event.jaxis.axis == 1){ // left stick move up ou down
				if(event.jaxis.value > m_joystickDeadZone)
					m_joystickValues[whichOne].first->setY(1);
				else if(event.jaxis.value < -m_joystickDeadZone)
					m_joystickValues[whichOne].first->setY(-1);
				else
					m_joystickValues[whichOne].first->setY(0);
			}

			if(event.jaxis.axis == 3){ // right stick move left or right
				if(event.jaxis.value > m_joystickDeadZone)
					m_joystickValues[whichOne].second->setX(1);
				else if(event.jaxis.value < -m_joystickDeadZone)
					m_joystickValues[whichOne].second->setX(-1);
				else
					m_joystickValues[whichOne].second->setX(0);
			}

			if(event.jaxis.axis == 4){ // right stick move up ou down
				if(event.jaxis.value > m_joystickDeadZone)
					m_joystickValues[whichOne].second->setY(1);
				else if(event.jaxis.value < -m_joystickDeadZone)
					m_joystickValues[whichOne].second->setY(-1);
				else
					m_joystickValues[whichOne].second->setY(0);
			}
		}
	}
}


void InputHandler::onMouseButtonUpDown(SDL_Event& event){
	int buttonTypes[] {SDL_BUTTON_LEFT, SDL_BUTTON_MIDDLE, SDL_BUTTON_RIGHT};

	for(int i=0; i<3; i++){
		if(event.button.button == buttonTypes[i]){
			m_mouseButtonStates[i] = event.type == SDL_MOUSEBUTTONDOWN;
		}
	}
}

void InputHandler::onMouseMove(SDL_Event& event){
	if(event.type == SDL_MOUSEMOTION){
		m_mousePosition.setX(event.motion.x);
		m_mousePosition.setY(event.motion.y);
	}
}

void InputHandler::reset(){
	for(auto mouseButton : m_mouseButtonStates){
		mouseButton = false;
	}
}