#include "GameplayState.h"
#include"../Last Samurai/TileSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Geometry.h"
GameplayState* GameplayState::GetInstance()
{
	static GameplayState m_Instance;
	return &m_Instance;
}

void GameplayState::Enter()
{
	Load = new TileSystem();
	Load->LoadTileXml();
}

void GameplayState::Exit()
{
	delete Load;
}

bool GameplayState::Update(float _ElapsedTime)
{
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

}