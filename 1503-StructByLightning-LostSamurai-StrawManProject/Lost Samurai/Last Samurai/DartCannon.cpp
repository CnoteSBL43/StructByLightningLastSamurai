#include "DartCannon.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "CreateArrowMessage.h"
#include "../SGD Wrappers/SGD_MessageManager.h"
#include "Game.h"

DartCannon::DartCannon()
{
}


DartCannon::~DartCannon()
{
}


void DartCannon::Render()
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
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 0, 0, 0 }, {}, 3);
	SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt, {}, {}, {}, SGD::Size{ -1, -1 });



}

void DartCannon::Update(float _elapsedtime)
{

	if (m_Timer <= 0)
	{

		CreateArrowMessage* m_Cannonball = new CreateArrowMessage(this);
		SGD::MessageManager::GetInstance()->QueueMessage(m_Cannonball);
		m_Cannonball = nullptr;
		m_Timer = 6.0;
	}

	if (m_Timer > 0)
	{
		m_Timer -= _elapsedtime;
	}






}

SGD::Rectangle DartCannon::GetRect(void) const
{

	//render rect
	SGD::Rectangle draw;

	draw.left = GetPosition().x;
	draw.right = draw.left + 32;
	draw.top = GetPosition().y;
	draw.bottom = draw.top + 32;

	return draw;

}