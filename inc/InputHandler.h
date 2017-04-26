#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__

#include "SDL2/SDL.h"
#include <vector>
#include <iostream>
#include "Vector.h"

enum mouse_button{

	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};


class InputHandler{

	public:
		static InputHandler* Instance();

		void clean();
		void update();

		void initialiseJoysticks();
		bool joysticksInitialised();

		bool isKeyDown(SDL_Scancode key);


		int xvalue(int joy, int stick);
		int yvalue(int joy, int stick);
		bool getMouseButtonState(mouse_button pButton)
		{
			return m_mouseButtonStates[pButton];
		}

		Vector2D getMousePosition(){
			return m_mousePosition;
		}
		void reset();

	private:
		InputHandler();
		~InputHandler(){}

		static InputHandler* s_pInstance;

		std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
		std::vector<SDL_Joystick*> m_joysticks;
		
		std::vector<bool> m_mouseButtonStates;
		
		bool m_bJoystickInitialised;
		const int m_joystickDeadZone = 10000;
		Vector2D m_mousePosition;
		const Uint8* m_keystates;

		void onMouseMove(SDL_Event&);
		void onMouseButtonUpDown(SDL_Event&);

};

#endif