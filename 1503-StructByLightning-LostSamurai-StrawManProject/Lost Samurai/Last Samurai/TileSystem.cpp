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


	for (unsigned int j = 0; j < m_Deathcollision.size(); j++)
	{
		delete m_Deathcollision[j];
		m_Deathcollision[j] = nullptr;
	}

	for (unsigned int j = 0; j < Ledges.size(); j++)
	{
		delete Ledges[j];
		Ledges[j] = nullptr;
	}
	//Traps.clear();
	for (unsigned int i = 0; i < Traps["darts"].size(); i++)
	{
		delete Traps["darts"][i];
	}
	for (unsigned int i = 0; i < Traps["Rocks"].size(); i++)
	{
		delete Traps["Rocks"][i];
	}
	for (unsigned int i = 0; i < Traps["Smashing"].size(); i++)
	{
		delete Traps["Smashing"][i];
	}
	for (unsigned int i = 0; i < Traps["PopSpikes"].size(); i++)
	{
		delete Traps["PopSpikes"][i];
	}
	for (unsigned int i = 0; i < Traps["Cannon"].size(); i++)
	{
		delete Traps["Cannon"][i];
	}
	for (unsigned int i = 0; i < Traps["Spikes"].size(); i++)
	{
		delete Traps["Spikes"][i];
	}
	for (unsigned int i = 0; i < Traps["Doors"].size(); i++)
	{
		delete Traps["Doors"][i];
	}
	for (unsigned int i = 0; i < Traps["Ledges"].size(); i++)
	{
		delete Traps["Ledges"][i];
	}
	for (unsigned int i = 0; i < Traps["Ladder"].size(); i++)
	{
		delete Traps["Ladder"][i];
	}
	for (unsigned int i = 0; i < Traps["Plates"].size(); i++)
	{
		delete Traps["Plates"][i];
	}

	for (unsigned int i = 0; i < Traps["Box"].size(); i++)
	{
		delete Traps["Box"][i];
	}

	for (unsigned int i = 0; i < Traps["Levers"].size(); i++)
	{
		delete Traps["Levers"][i];
	}

	for (unsigned int i = 0; i < Traps["WayPoint"].size(); i++)
	{
		delete Traps["WayPoint"][i];
	}

	for (unsigned int i = 0; i < Traps["AI"].size(); i++)
	{
		delete Traps["AI"][i];
	}
	for (unsigned int i = 0; i < Traps["FinalDoor"].size(); i++)
	{
		delete Traps["FinalDoor"][i];
	}
#pragma endregion
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_TileImage);
	delete m_Grid;
	m_Grid = NULL;
}

void TileSystem::LoadTileXml(Father* _father, Son* _Son, const char* _level)

{
	//Game::GetInstance()->GetFont().Draw("Loading", { Game::GetInstance()->GetScreenSize().width / 2, Game::GetInstance()->GetScreenSize().height / 2 }, 1, { 255, 255, 255, 255 });

	//TileSystem* Tileload = new TileSystem();
	m_Grid = new Grid();
	//Map = new Tile;
	const char* Test;
	// 
	TiXmlDocument Doc;
	// Did this work?
	if (Doc.LoadFile(_level) == false)
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
	TiXmlElement* tilecollison = Root->FirstChildElement("Collision");
	TiXmlElement* tile = tilecollison->FirstChildElement();
#pragma region First Child

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
		if (m_Tile->Traps == 1)
		{
			m_Tile->TrapNames = tile->Attribute("TrapNames");

			tile->Attribute("DoorID", &m_Tile->Door);
		}

		tile->Attribute("Border", &m_Tile->Border);
		if (m_Tile->TrapNames == "Box")
		{
			tile->Attribute("Weight", &m_Tile->Weight);
		}
		if (m_Tile->TrapNames == "Plates")
		{
			tile->Attribute("PlateWeight", &m_Tile->PlateWeight);
		}

		Map[m_Tile->PositionX][m_Tile->PositionY] = m_Tile;

		//tile->Attribute("Door", &m_Tile->Door);


#pragma region This Will Decide where the 2 Characters will spawn 

		if (Map[m_Tile->PositionX][m_Tile->PositionY]->Weight > 0)
		{
			if (Map[m_Tile->PositionX][m_Tile->PositionY]->Weight == 1)
				BoxWeight[temp2] = false;
			else
				BoxWeight[temp2] = true;
			temp2++;
		}
		if (Map[m_Tile->PositionX][m_Tile->PositionY]->PlateWeight > 0)
		{
			if (Map[m_Tile->PositionX][m_Tile->PositionY]->PlateWeight == 1)
				PlateisHeavy[temp3] = false;
			else
				PlateisHeavy[temp3] = true;
			temp3++;
		}
		if (Map[m_Tile->PositionX][m_Tile->PositionY]->Door > 0)
		{
			DoorID[temp] = Map[m_Tile->PositionX][m_Tile->PositionY]->Door;
			temp++;
		}
		if (Map[m_Tile->PositionX][m_Tile->PositionY]->m_Spawn == 1)
		{
			SGD::Rectangle* Rect = new SGD::Rectangle();

			Rect->left = (((float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth) -
				Game::GetInstance()->GetScreenSize().width / 2);/*- Game::GetInstance()->GetCameraPosition().x;/* - Game::GetInstance()->GetCameraPosition().x / 2*/


			Rect->top = (((float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight) -
				Game::GetInstance()->GetScreenSize().height / 500);/* -Game::GetInstance()->GetCameraPosition().y); /*- Game::GetInstance()->GetCameraPosition().y / 2*/;

			Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;

			Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;

			_father->SetPosition(SGD::Point{ Rect->left, Rect->top });//2400 500 
			_father->SetCheckPoint({ Rect->left + 75, Rect->top - 100 });

			//TileClass = nullptr;
			_Son->SetPosition(SGD::Point{ Rect->left + 25, Rect->top });
			_Son->SetCheckPoint({ Rect->left + 25, Rect->top });
			//_father->SetPosition(SGD::Point{ 3800,200});
			//	_Son->SetPosition(SGD::Point{ 2350,500 });
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

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "PopSpikes")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["PopSpikes"].push_back(Rect);

			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Doors")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Doors"].push_back(Rect);

			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Ladder")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Ladder"].push_back(Rect);
			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Plates")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Plates"].push_back(Rect);

			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Levers")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Levers"].push_back(Rect);

			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Box")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Box"].push_back(Rect);

			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Rope")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Rope"].push_back(Rect);

			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "FinalDoor")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["FinalDoor"].push_back(Rect);

			}
			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "Boulder")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["Boulder"].push_back(Rect);
			}

			if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "AI")
			{
				SGD::Rectangle* Rect = new SGD::Rectangle();
				Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
					Game::GetInstance()->GetScreenSize().width / 2;


				Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
					Game::GetInstance()->GetScreenSize().height / 2;
				Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
				Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
				Traps["AI"].push_back(Rect);

			}



		}

		if (Map[m_Tile->PositionX][m_Tile->PositionY]->TrapNames == "WayPoint")
		{
			SGD::Rectangle* Rect = new SGD::Rectangle();
			Rect->left = (float)m_Tile->PositionX * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth +
				Game::GetInstance()->GetScreenSize().width / 2;
			Rect->top = (float)m_Tile->PositionY * Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight +
				Game::GetInstance()->GetScreenSize().height / 2;
			Rect->right = Rect->left + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileWidth;
			Rect->bottom = Rect->top + Map[m_Tile->PositionX][m_Tile->PositionY]->m_TileHeight;
			Traps["WayPoint"].push_back(Rect);

		}

		if (tile->NextSiblingElement() == nullptr)
			break;

		tile = tile->NextSiblingElement();
		if (tile->GetText() == "RectElement")
		{
			int x = 0;
		}
	}
#pragma endregion
	tilecollison = tilecollison->NextSiblingElement("Rect");
	//tile = rect->FirstChildElement();
	tile = tilecollison->FirstChildElement();
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
		rect1.left = (float)Left;
		rect1.top = (float)Top;
		rect1.bottom = (float)Bottom;
		rect1.right = (float)Right;
		rect->left = (float)rect1.left;// -Game::GetInstance()->GetCameraPosition().x / 2;
		rect->top = (float)rect1.top;// -Game::GetInstance()->GetCameraPosition().y / 2;
		rect->right = (float)rect1.left + rect1.ComputeWidth();// -Game::GetInstance()->GetCameraPosition().x / 2;
		rect->bottom = (float)rect1.top + rect1.ComputeHeight();// -Game::GetInstance()->GetCameraPosition().y / 2;
		m_Tile->SetRect(*rect);
		m_Tile->SetPosition(SGD::Point{ (float)rect->left, (float)rect->top });
		m_CollisionRect.push_back(m_Tile);
		delete rect;

		tile = tile->NextSiblingElement();
	}


	tilecollison = tilecollison->NextSiblingElement("Ledge");
	tile = tilecollison->FirstChildElement();
	while (tile != nullptr)
	{

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
		rect1.left = (float)Left;
		rect1.top = (float)Top;
		rect1.bottom = (float)Bottom;
		rect1.right = (float)Right;
		rect->left = rect1.left;// -Game::GetInstance()->GetCameraPosition().x / 2;
		rect->top = rect1.top;// -Game::GetInstance()->GetCameraPosition().y / 2;
		rect->right = rect1.left + rect1.ComputeWidth();// -Game::GetInstance()->GetCameraPosition().x / 2;
		rect->bottom = rect1.top + rect1.ComputeHeight();// -Game::GetInstance()->GetCameraPosition().y / 2;
		Traps["Ledges"].push_back(rect);
		//delete m_Tile;


		tile = tile->NextSiblingElement();
	}



#pragma region Concatination for the string
	std::string Attach;
	Attach = "../resource/graphics/";
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