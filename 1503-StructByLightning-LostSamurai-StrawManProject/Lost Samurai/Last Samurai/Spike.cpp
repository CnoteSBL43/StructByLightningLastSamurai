#include "Spike.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"

Spike::Spike()
{
}


Spike::~Spike()
{
}

void Spike::Render()
{
	


		//camera offest
		SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
		SGD::Size screen = Game::GetInstance()->GetScreenSize();
		//the render rect after the offest
		SGD::Point pt = { (GetPosition().x - screen.width / 2) - PositionOffset.x
			, GetPosition().y - PositionOffset.y };

		//render rect
		SGD::Rectangle draw = rect;

		draw.left = pt.x;
		draw.right = draw.left + rect.ComputeWidth();
		draw.top = pt.y;
		draw.bottom = draw.top + rect.ComputeHeight();

		//draw rect
		//SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 0, 0, 0 }, {}, 3);
		SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt, {}, {}, {}, SGD::Size{ 0.7f, 0.7f});
		//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 0, 255, 255, 255 }, { 255, 255, 255, 255 }, 3);
	
}


