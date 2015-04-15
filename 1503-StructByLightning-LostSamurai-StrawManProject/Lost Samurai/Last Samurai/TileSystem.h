#pragma once
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include <vector>
#include "Father.h"
#include "Son.h"
#include "IEntity.h"
#include "Tile.h"
#include <string.h>
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
		int m_Collision;
		int m_Spawn;
		int m_Checkpoint;
		int m_Trigger;
		int CheckPointX;
		int CheckPointY;

		std::string m_EventString;

		std::string TrapNames;
		int TriggerPositionX;
		int TrigerPositionY;

		int Traps;

	};

	struct Grid
	{
		int m_GridWidth;
		int m_GridHeight;

	};

public:
	TileSystem();
	~TileSystem();
	void LoadTileXml(Father* _father, Son* _Son);
	tile1* m_Tile;
	Grid* m_Grid;
	//Tile* Map[][];
	//Grid* m_GridMap[10][10];
	SGD::HTexture GetTileImage() { return m_TileImage; }

	std::vector<tile1*>* Map;
	std::vector<Tile*> m_CollisionRect;
	std::vector<Tile*> m_Deathcollision;
	std::vector<Tile*> m_CheckPoints;
	std::vector<Tile*> m_AI;
	std::vector<Tile*> Ledges;

	std::map<std::string, std::vector<SGD::Rectangle*>> Traps;


};

