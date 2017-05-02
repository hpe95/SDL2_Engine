#include "TileLayer.h"
#include <stdio.h>
#include "game.h"
#include "TextureManager.h"

TileLayer::TileLayer(int tileSize, const std::vector<Tileset> &tilesets) : m_tileSize(tileSize), 
m_tilesets(tilesets), m_position(0,0), m_velocity(0,0)
{
	m_numColumns = (Game::Instance()->getGameWidth() / m_tileSize);
	m_numRows = (Game::Instance()->getGameHeight() / m_tileSize);
}

Tileset TileLayer::getTilesetByID(int tileID){
	for (unsigned i = 0; i < m_tilesets.size(); i++)
	{
		if(i + 1 <= m_tilesets.size() - 1){
			if(tileID >= m_tilesets[i].firstGridID && tileID < m_tilesets[i + 1].firstGridID)
				return m_tilesets[i];
		}
		else
			return m_tilesets[i];
	}

	printf("did not find tileset, returning empty tileset\n");
	Tileset t;
	return t;
}

void TileLayer::update(){
	m_position += m_velocity;
}

void TileLayer::render(){
	int x,y,x2,y2 = 0;

	x = m_position.getX() / m_tileSize;
	y = m_position.getY() / m_tileSize;

	x2 = int(m_position.getX()) % m_tileSize;
	y2 = int(m_position.getY()) % m_tileSize;

	for(int rows = 0; rows < m_numRows; rows++){
		for(int cols = 0; cols < m_numColumns; cols++){
			int id = m_tileIDs[rows][cols + rows];

			if(id == 0)
				continue;

			Tileset tileset = getTilesetByID(id);

			id--;

			TextureManager::Instance()->drawTile(tileset.name, 2, 2, (cols * m_tileSize) - x2, 
				(rows * m_tileSize) - y2, m_tileSize, m_tileSize, 
				(id - (tileset.firstGridID - 1)) / tileset.numColumns, 
				(id - (tileset.firstGridID - 1)) % tileset.numColumns, 
				Game::Instance()->getRenderer());
		}
	}
}