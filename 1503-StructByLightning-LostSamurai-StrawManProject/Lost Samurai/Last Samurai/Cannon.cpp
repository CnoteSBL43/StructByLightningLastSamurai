#include "Cannon.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"
#include "CreateCannonBallMessage.h"
#include "../SGD Wrappers/SGD_MessageManager.h"

Cannon::Cannon()
{
}


Cannon::~Cannon()
{
}


void Cannon::Render()
{
	//camera offest
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { (GetPosition().x - PositionOffset.x), (GetPosition().y - PositionOffset.y) };

	//render rect
	SGD::Rectangle draw = GetRect();

	draw.left -= PositionOffset.x;
	draw.right -= PositionOffset.x;
	draw.top -= PositionOffset.y;
	draw.bottom -= PositionOffset.y;


	//draw rect
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 255, 0, 0 }, {}, 3);
	SGD::GraphicsManager::GetInstance()->DrawTextureSection(GetImage(), pt, { 11, 71, 218, 200 }, {}, {}, {}, SGD::Size{ 0.7f, 0.7f });



}

void Cannon::Update(float _elapsedtime)
{


	if (m_Timer <= 0)
	{

		CreateCannonBallMessage* m_Cannonball = new CreateCannonBallMessage(this);
		SGD::MessageManager::GetInstance()->QueueMessage(m_Cannonball);
		m_Cannonball = nullptr;
		m_Timer = 6.0;
	}

	if (m_Timer > 0)
	{
		m_Timer -= _elapsedtime;
	}


}

SGD::Rectangle Cannon::GetRect(void) const
{

	//render rect
	SGD::Rectangle draw;

	draw.left = GetPosition().x;
	draw.right = draw.left + 256;
	draw.top = GetPosition().y;
	draw.bottom = draw.top + 256;

	return draw;

}