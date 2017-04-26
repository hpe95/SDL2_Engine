#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
class Player : public SDLGameObject{

	public:
		Player(const LoaderParams *pParams);
		virtual void draw();
		virtual void update();
		virtual void clean();

	private:
		void handleInput();
};

#endif