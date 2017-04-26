#ifndef __SDLGAMEOBJECT__
#define __SDLGAMEOBJECT__

#include <string>
#include "GameObject.h"
#include "TextureManager.h"
//#include "LoaderParams.h"
#include "Vector.h"

using namespace std;
class SDLGameObject : public GameObject
{

	public:
		SDLGameObject();
		
		virtual void draw();
		virtual void update();
		virtual void clean();
		virtual void load(const LoaderParams* pParams);
		Vector2D& getPosition();

		int getWidth();

		int getHeight();

	protected:

		int m_width;
		int m_height;
		int m_currentRow;
		int m_currentFrame;
		int m_numFrames;
		string m_textureID;
		Vector2D m_position;
		Vector2D m_velocity;
		Vector2D m_aceleration;
		
};

#endif
