#pragma once
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include <vector>
class TileSystem
{

protected:

	SGD::HTexture m_TileImage;
	struct Tile
	{
	
		int m_TileWidth;
		int m_TileHeight;
		int m_TileID;
		int PositionX;
		int PositionY;
		SGD::Size m_Image;
	};

	struct Grid
	{
		int m_GridWidth;
		int m_GridHeight;
		
	};
	
public:
	TileSystem();
	~TileSystem();
	void LoadTileXml();
	Tile* m_Tile;
	Grid* m_Grid;
//Tile* Map[][];
	//Grid* m_GridMap[10][10];
	SGD::HTexture GetTileImage() { return m_TileImage; }

	std::vector<Tile*>* Map;
	// Tiles Width

	// Tiles Height



};

