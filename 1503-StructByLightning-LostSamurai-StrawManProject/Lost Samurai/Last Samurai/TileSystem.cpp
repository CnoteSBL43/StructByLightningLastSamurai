#include "TileSystem.h"
#include "../TinyXML/tinyxml.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <string>
#include "Game.h"
#include "Father.h"
#include "Son.h"

TileSystem::TileSystem()
{
}


TileSystem::~TileSystem()
{
#pragma region
	for ( int i = 0; i < m_Grid->m_GridWidth; i++)
	{

		std::vector<tile1*>& Vec = Map[i];
		int m_catch = Vec.size();

		for ( int j = 0; j < m_Grid->m_GridHeight; j++)
		{

			delete Map[i][j];

		}


	}

	delete[] Map;

#pragma endregion
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_TileImage);
	delete m_Grid;
	m_Grid = NULL;
}

void TileSystem::LoadTileXml(Father* _father, Son* _Son)

{
	//TileSystem* Tileload = new TileSystem();
	m_Grid = new Grid();
	//Map = new Tile;
	const char* Test;
	// 
	TiXmlDocument Doc;
	// Did this work?
	if (Doc.LoadFile("../desa.xml") == false)
		return;
	// Root Element 
	TiXmlElement* Root = Doc.RootElement();
	Test = Root->Attribute("Image");
	Root->Attribute("MapHeight", &m_Grid->m_GridHeight);
	Root->Attribute("MapWidth", &m_Grid->m_GridWidth);

	// an Array of vectors 
	Map = new std::vector<tile1*>[m_Grid->m_GridWidth];

	for ( int i = 0; i < m_Grid->m_GridWidth; i++)
	{

		Map[i].resize(m_Grid->m_GridHeight);
	}


	int width, height;
	int IWidth, IHeight;
	Root->Attribute("TileHeight", &width);
	Root->Attribute("TileWidth", &height);
	Root->Attribute("ImageHeight", &IHeight);
	Root->Attribute("ImageWidth", &IWidth);
	TiXmlElement* tile = Root->FirstChildElement();

	while (tile != nullptr)
	{
		m_Tile = new tile1();

		m_Tile->m_TileHeight = height;
		m_Tile->m_TileWidth = width;

		m_Tile->m_Image.height = (float)IHeight;
		m_Tile->m_Image.width = (float)IWidth;

		tile->Attribute("PositionX", &m_Tile->PositionX);
		tile->Attribute("PositionY", &m_Tile->PositionY);
		tile->Attribute("TileID", &m_Tile->m_TileID);
		  tile->Attribute("TileCollision",&m_Tile->m_Collision);
		tile->Attribute("SpawnX", &m_Tile->SpawnX);
		tile->Attribute("SpawnY", &m_Tile->SpawnY);
		
		Map[m_Tile->PositionX][m_Tile->PositionY] = m_Tile;

#pragma region This Will Decide where the 2 Characters will spawn 
		if (Map[m_Tile->PositionX][m_Tile->PositionY]->SpawnX != 0 && Map[m_Tile->PositionX][m_Tile->PositionY]->SpawnY != 0)
		{
			_father->SetPosition(SGD::Point{ (float)Map[m_Tile->PositionX][m_Tile->PositionY]->SpawnX - (Game::GetInstance()->GetScreenSize().width / 2), (float)Map[m_Tile->PositionX][m_Tile->PositionY]->SpawnY - (Game::GetInstance()->GetScreenSize().height / 100) });
			_Son->SetPosition(SGD::Point{ (float)Map[m_Tile->PositionX][m_Tile->PositionY]->SpawnX + 50, (float)Map[m_Tile->PositionX][m_Tile->PositionY]->SpawnY * 1.95f });
			
		}
#pragma endregion

#pragma region This Will check if there are collision rectangles
		if (Map[m_Tile->PositionX][m_Tile->PositionY]->m_Collision == 1)
		{
			Tile* TileClass = new Tile();
			SGD::Rectangle* Rect = new SGD::Rectangle();
			Rect->left = ((float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth/* - Game::GetInstance()->GetCameraPosition().x / 2*/);
			Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight /*- Game::GetInstance()->GetCameraPosition().y / 2*/;
			//TileClass->CollisionRectangle->PositionY = Rect->top;
			Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
			//TileClass->CollisionRectangle->SizeWidth = Rect->right;
			Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
			//TileClass->CollisionRectangle->SizeHeight = Rect->bottom;
			TileClass->SetRect(*Rect);
			TileClass->SetPosition(SGD::Point{ (float)Rect->left, (float)Rect->top });
			//TileClass->SetSize(SGD::Size{ Rect->right, Rect->bottom });
			TileClass->SetSize(Rect->ComputeSize());
			m_CollisionRect.push_back(TileClass);
		}
#pragma endregion



		if (tile->NextSiblingElement() == nullptr)
			break;

		tile = tile->NextSiblingElement();
	}


#pragma region Concatination for the string
	std::string Attach;
	Attach = "../";
	for (unsigned int i = 0; i < Attach.size(); i++)
	{
		if (i != 2)
		{
			i++;
		}
		else
		{
			Attach.append(Test);
		}

	}
	m_TileImage = SGD::GraphicsManager::GetInstance()->LoadTexture(Attach.c_str());
#pragma endregion


}