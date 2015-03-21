#include "GameplayState.h"
#include"Father.h"
#include "Game.h"
#include "Actor.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include"MainMenuState.h"
#include "EntityManager.h"
#include"../Last Samurai/TileSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Geometry.h"
GameplayState* GameplayState::GetInstance()
{
	static GameplayState m_Instance;
	return &m_Instance;
}

Actor* GameplayState::CreateFather(void)
{
	Player* father = new Father;
	father->SetPosition(SGD::Point{ 100.0f, 480.0f });
	father->SetAlive(true);
	father->SetImage(m_FatherImage);
	father->SetSize(SGD::Size{ -1.5f, 1.5f });
	father->SetVelocity({ 0.2f, 0.0f });
	return father;
}

void GameplayState::Enter()
{
	m_FatherImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Father.png");
	m_pEntities = new EntityManager;
	m_player = CreateFather();
	m_pEntities->AddEntity(m_player, 0);
	m_player->Release();
	Load = new TileSystem();
	Load->LoadTileXml();
}


void GameplayState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherImage);
	if (m_pEntities != nullptr)
	{
		m_pEntities->RemoveAll();
		delete m_pEntities;
		m_pEntities = nullptr;
		delete Load;
	}
}

bool GameplayState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	m_pEntities->UpdateAll(_ElapsedTime);
	return true;
}


void GameplayState::Render(float _ElapsedTime)
{


	for (int X = 0; X < Load->m_Grid->m_GridWidth; X++)
	{
		for (int Y = 0; Y < Load->m_Grid->m_GridHeight; Y++)
		{
			SGD::Rectangle DestinationRectangle;
			DestinationRectangle.top = X * Load->m_Tile->m_TileWidth;
			DestinationRectangle.left = Y * Load->m_Tile->m_TileHeight;
			DestinationRectangle.right = DestinationRectangle.left + Load->m_Grid->m_GridWidth;
			DestinationRectangle.bottom = DestinationRectangle.top + Load->m_Grid->m_GridHeight;
			//SGD::GraphicsManager::GetInstance()->DrawRectangle(DestinationRectangle, SGD::Color{ 255, 0, 255, 255 }, SGD::Color{ 255, 255, 0, 0 }, 5);

			SGD::Rectangle SourceRectangle;
			SourceRectangle.left = Load->Map[X][Y]->m_TileID % (int)(Load->Map[X][Y]->m_Image.width / Load->Map[X][Y]->m_TileWidth) * Load->Map[X][Y]->m_TileWidth;
			SourceRectangle.top = Load->Map[X][Y]->m_TileID / (int)(Load->Map[X][Y]->m_Image.height / Load->Map[X][Y]->m_TileHeight) * Load->Map[X][Y]->m_TileHeight;


			SourceRectangle.right = SourceRectangle.left + Load->Map[X][Y]->m_TileHeight;
			SourceRectangle.bottom = SourceRectangle.top + Load->Map[X][Y]->m_TileWidth;
			SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ (float)X * Load->Map[X][Y]->m_TileWidth, (float)Y * Load->Map[X][Y]->m_TileHeight }, SourceRectangle);
			//SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ 0, 0}, SGD::Rectangle(Load->Map[X][Y]->m_TileID % (512 / Load->m_Tile->m_TileWidth), Load->Map[X][Y]->m_TileID % (512 / Load->m_Tile->m_TileWidth), 32, 32));


		}
	}
	m_pEntities->RenderAll();
}