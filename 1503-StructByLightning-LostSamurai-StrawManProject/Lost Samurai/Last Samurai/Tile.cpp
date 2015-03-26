#include "Tile.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "Game.h"
Tile::Tile()
{
}


Tile::~Tile()
{
}


void Tile::Render()
{

	//camera offest
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition() ;
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { GetPosition().x - PositionOffset.x - screen.width/2
		, GetPosition().y - PositionOffset.y };

	//render rect
	SGD::Rectangle draw = rect;

	draw.left = pt.x;
	draw.right = draw.left + rect.ComputeWidth();
	draw.top = pt.y;
	draw.bottom = draw.top + rect.ComputeHeight();

	//draw rect
	SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 0, 0, 0 }, {}, 3);
	SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255,255,255 }, {}, 3);

}

void Tile::HandleCollision(IEntity* pOther)
{
	
	if (pOther->GetType() == ENT_FATHER)
	{

		


	}


}

int Tile::GetType(void)	const
{

	return ENT_TILES;

}

SGD::Rectangle Tile::GetRect() const
{
	//camera offest
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { GetPosition().x - PositionOffset.x - screen.width / 2
		, GetPosition().y - PositionOffset.y };

	//render rect
	SGD::Rectangle draw = rect;

	draw.left = pt.x;
	draw.right = draw.left + rect.ComputeWidth();
	draw.top = pt.y;
	draw.bottom = draw.top + rect.ComputeHeight();

	return draw;
}
