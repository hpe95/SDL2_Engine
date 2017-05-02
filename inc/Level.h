#ifndef __LEVEL__
#define __LEVEL__

#include "Layer.h"
#include <vector>
#include <iostream>

using namespace std;
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	string name;
};

class Level{

public:
	~Level(){}

	void update();
	void render();

	vector<Tileset>* getTilesets(){
		return &m_tilesets;
	}

	vector<Layer*>* getLayers(){
		return &m_layers;
	}

private:
	Level(){}
	friend class LevelParser;
	vector<Tileset> m_tilesets;
	vector<Layer*> m_layers;
};

#endif