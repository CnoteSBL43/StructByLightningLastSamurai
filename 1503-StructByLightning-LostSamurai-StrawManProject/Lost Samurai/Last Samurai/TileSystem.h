#pragma once
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include <vector>
#include "Father.h"
#include "Son.h"
#include "IEntity.h"
#include "Tile.h"
class TileSystem
{

protected:

	SGD::HTexture m_TileImage;
	struct tile1
	{
	
		int m_TileWidth;
		int m_TileHeight;
		int m_TileID;
		int PositionX;
		int PositionY;
		SGD::Size m_Image;
		int SpawnX = 0;
		int SpawnY = 0;
		int m_Collision;
		SGD::Point CheckPoint;
		
	};

	struct Grid
	{
		int m_GridWidth;
		int m_GridHeight;
		
	};
	
public:
	TileSystem();
	~TileSystem();
	void LoadTileXml(Father* _father,Son* _Son);
	tile1* m_Tile;
	Grid* m_Grid;
//Tile* Map[][];
	//Grid* m_GridMap[10][10];
	SGD::HTexture GetTileImage() { return m_TileImage; }

	std::vector<tile1*>* Map;
	std::vector<Tile*> m_CollisionRect;
	// Tiles Width

	// Tiles Height

	
};

