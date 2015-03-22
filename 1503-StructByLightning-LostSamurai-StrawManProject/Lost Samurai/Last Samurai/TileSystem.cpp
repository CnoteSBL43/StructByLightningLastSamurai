#include "TileSystem.h"
#include "../TinyXML/tinyxml.h"
#include <string>

TileSystem::TileSystem()
{
}


TileSystem::~TileSystem()
{
#pragma region
	for ( int i = 0; i < m_Grid->m_GridWidth; i++)
	{

		std::vector<Tile*>& Vec = Map[i];
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

void TileSystem::LoadTileXml()

{
	//TileSystem* Tileload = new TileSystem();
	m_Grid = new Grid();
	//Map = new Tile;
	const char* Test;
	// 
	TiXmlDocument Doc;
	// Did this work?
	if (Doc.LoadFile("../Kumar.xml") == false)
		return;
	// Root Element 
	TiXmlElement* Root = Doc.RootElement();
	Test = Root->Attribute("Image");
	Root->Attribute("MapHeight", &m_Grid->m_GridHeight);
	Root->Attribute("MapWidth", &m_Grid->m_GridWidth);

	// an Array of vectors 
	Map = new std::vector<Tile*>[m_Grid->m_GridWidth];

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
		m_Tile = new Tile();

		m_Tile->m_TileHeight = height;
		m_Tile->m_TileWidth = width;

		m_Tile->m_Image.height = (float)IHeight;
		m_Tile->m_Image.width = (float)IWidth;

		tile->Attribute("PositionX", &m_Tile->PositionX);
		tile->Attribute("PositionY", &m_Tile->PositionY);
		tile->Attribute("TileID", &m_Tile->m_TileID);
		Map[m_Tile->PositionX][m_Tile->PositionY] = m_Tile;

		if (tile->NextSiblingElement() == nullptr)
			break;

		tile = tile->NextSiblingElement();
	}



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

}