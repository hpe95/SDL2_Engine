#ifndef __MENUBUTTON__
#define __MENUBUTTON__

#include "SDLGameObject.h"

class MenuButton : public SDLGameObject{
public:
	MenuButton();
	virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(const LoaderParams* pParams);

	void setCallback(void(*callback)());
	int getCallbackID();
private:
	enum button_state{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};

	int m_callbackID;
	void (*m_callback)();
	bool m_bReleased;
};

#endif