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
	for (int i = 0; i < m_Grid->m_GridWidth; i++)
	{

		std::vector<tile1*>& Vec = Map[i];
		int m_catch = Vec.size();

		for (int j = 0; j < m_Grid->m_GridHeight; j++)
		{

			delete Map[i][j];

		}


	}

	delete[] Map;

	for (unsigned int j = 0; j < m_CollisionRect.size(); j++)
	{
		delete m_CollisionRect[j];
		m_CollisionRect[j] = nullptr;
	}

	for (unsigned int j = 0; j < m_CheckPoints.size(); j++)
	{
		delete m_CheckPoints[j];
		m_CheckPoints[j] = nullptr;
	}





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
	if (Doc.LoadFile("../DemoAlphaLevel.xml") == false)
		return;
	// Root Element 
	TiXmlElement* Root = Doc.RootElement();
	Test = Root->Attribute("Image");
	Root->Attribute("MapHeight", &m_Grid->m_GridHeight);
	Root->Attribute("MapWidth", &m_Grid->m_GridWidth);

	// an Array of vectors 
	Map = new std::vector<tile1*>[m_Grid->m_GridWidth];

	for (int i = 0; i < m_Grid->m_GridWidth; i++)
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
		tile->Attribute("TileCollision", &m_Tile->m_Collision);
		tile->Attribute("Spawn", &m_Tile->m_Spawn);
		tile->Attribute("CheckPoint", &m_Tile->m_Checkpoint);
		tile->Attribute("Trigger", &m_Tile->m_Trigger);
		if (m_Tile->m_Trigger == 1)
		{
			m_Tile->m_EventString = tile->Attribute("TriggerEvents");
		}
		tile->Attribute("Traps", &m_Tile->Traps);
		if (m_Tile->Traps == 1 )
		{
			m_Tile->TrapNames = tile->Attribute("TrapNames");
		}

		Map[m_Tile->PositionX][m_Tile->PositionY] = m_Tile;


#pragma region This Will Decide where the 2 Characters will spawn 
		if (Map[m_Tile->PositionX][m_Tile->PositionY]->m_Spawn == 1)
		{
			SGD::Rectangle* Rect = new SGD::Rectangle();

			Rect->left = (((float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth) -
				Game::GetInstance()->GetScreenSize().width / 2);/*- Game::GetInstance()->GetCameraPosition().x;/* - Game::GetInstance()->GetCameraPosition().x / 2*/


			Rect->top = (((float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight) -
				Game::GetInstance()->GetScreenSize().height / 500);/* -Game::GetInstance()->GetCameraPosition().y); /*- Game::GetInstance()->GetCameraPosition().y / 2*/;

			Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;

			Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;

			_father->SetPosition(SGD::Point{ (float)Rect->left + 15, Rect->top - 200 });
			//TileClass = nullptr;
			_Son->SetPosition(SGD::Point{ (float)Rect->left + 75, Rect->top });


			delete Rect;
			Rect = nullptr;
		}
#pragma endregion

#pragma region This Will check if there are collision rectangles
		//if (Map[m_Tile->PositionX][m_Tile->PositionY]->m_Collision == 1)
		//{
		//	Tile* TileClass = new Tile();
		//	SGD::Rectangle* Rect = new SGD::Rectangle();
		//	Rect->left = ((float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth/* - Game::GetInstance()->GetCameraPosition().x / 2*/);
		//	Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight /*- Game::GetInstance()->GetCameraPosition().y / 2*/;
		//	//TileClass->CollisionRectangle->PositionY = Rect->top;
		//	Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
		//	//TileClass->CollisionRectangle->SizeWidth = Rect->right;
		//	Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
		//	//TileClass->CollisionRectangle->SizeHeight = Rect->bottom;
		//	TileClass->SetRect(*Rect);
		//	TileClass->SetPosition(SGD::Point{ (float)Rect->left, (float)Rect->top });
		//	//TileClass->SetSize(SGD::Size{ Rect->right, Rect->bottom });
		//	TileClass->SetSize(Rect->ComputeSize());
		//	m_CollisionRect.push_back(TileClass);
		//	delete Rect;
		//	Rect = nullptr;
		//}
#pragma endregion

#pragma region  This Will Get the CheckPoints In the Level

		if (Map[m_Tile->PositionX][m_Tile->PositionY]->m_Checkpoint == 1)
		{
			Tile* TileClass = new Tile();
			SGD::Rectangle* Rect = new SGD::Rectangle();
			Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
				Game::GetInstance()->GetScreenSize().width / 2;


			Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
				Game::GetInstance()->GetScreenSize().height / 2;
			Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
			Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
			TileClass->SetRect(*Rect);
			TileClass->SetPosition(SGD::Point{ (float)Rect->left, (float)Rect->top });
			TileClass->SetSize(Rect->ComputeSize());
			m_CheckPoints.push_back(TileClass);
			delete Rect;
			Rect = nullptr;

		}




#pragma endregion

#pragma region This Will Get the Trigger events


		if (Map[m_Tile->PositionX][m_Tile->PositionY]->m_Trigger == 1)
		{
			Tile* TileClass = new Tile();
			SGD::Rectangle* Rect = new SGD::Rectangle();
			Rect->left = (((float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth) -
				Game::GetInstance()->GetScreenSize().width / 350);// -Game::GetInstance()->GetCameraPosition().x;/* - Game::GetInstance()->GetCameraPosition().x / 2*/


			Rect->top = (((float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight) -
				Game::GetInstance()->GetScreenSize().height / 350);// -Game::GetInstance()->GetCameraPosition().y);
			//TileClass->CollisionRectangle->PositionY = Rect->top;
			Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
			//TileClass->CollisionRectangle->SizeWidth = Rect->right;
			Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
			TileClass->SetRect(*Rect);
			TileClass->SetPosition(SGD::Point{ (float)Rect->left, (float)Rect->top });
			//TileClass->SetSize(SGD::Size{ Rect->right, Rect->bottom });
			TileClass->SetSize(Rect->ComputeSize());
			TileClass->SetString(Map[m_Tile->PositionX][m_Tile->PositionY]->m_EventString);
			TileClass->SetType(Actor::ENT_TRIGGER);
			m_Deathcollision.push_back(TileClass);
			//delete TileClass;
			//TileClass = nullptr;
			//TileClass = nullptr;
			delete Rect;
			Rect = nullptr;

		}





#pragma endregion

		if (Map[m_Tile->PositionX][m_Tile->PositionY]->Traps == 1)
		{

			//Tile* TileClass = new Tile();
			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Spikes")
			{

				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Spikes"].push_back(Rect);
			}
			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Smashing")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Smashing"].push_back(Rect);



			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Rocks")
			{

				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Rocks"].push_back(Rect);

			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "darts")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["darts"].push_back(Rect);


			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Cannon")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Cannon"].push_back(Rect);
			}


			
			
		

		}


		if (tile->NextSiblingElement() == nullptr)
			break;

		tile = tile->NextSiblingElement();
	}
	tile = Root->FirstChildElement("RectEelemnt");
	while (tile != nullptr)
	{
		Tile* m_Tile = new Tile();
		SGD::Rectangle* rect = new SGD::Rectangle();
		int Left;
		int Top;
		int Right;
		int Bottom;
		tile->Attribute("CollisionRectleft", &Left);
		tile->Attribute("CollisionRectTop", &Top);
		tile->Attribute("CollisionRectRight", &Right);
		tile->Attribute("CollisionRectBottom", &Bottom);
		SGD::Rectangle rect1;
		rect1.left = Left;
		rect1.top = Top;
		rect1.bottom = Bottom;
		rect1.right = Right;
		rect->left = rect1.left;// -Game::GetInstance()->GetCameraPosition().x / 2;
		rect->top = rect1.top;// -Game::GetInstance()->GetCameraPosition().y / 2;
		rect->right = rect1.left + rect1.ComputeWidth();// -Game::GetInstance()->GetCameraPosition().x / 2;
		rect->bottom = rect1.top + rect1.ComputeHeight();// -Game::GetInstance()->GetCameraPosition().y / 2;
		m_Tile->SetRect(*rect);
		m_Tile->SetPosition(SGD::Point{ (float)rect->left, (float)rect->top });
		m_CollisionRect.push_back(m_Tile);


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