#include "Level.h"

void Level::update(){
	for (unsigned i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update();
	}
}

void Level::render(){
	for (unsigned i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render();
	}	
}