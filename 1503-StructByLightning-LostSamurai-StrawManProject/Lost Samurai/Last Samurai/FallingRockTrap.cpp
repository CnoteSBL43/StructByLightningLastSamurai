#include "FallingRockTrap.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "Game.h"
#include "../SGD Wrappers/SGD_Message.h"
#include "MessageID.h"
#include "../SGD Wrappers/SGD_MessageManager.h"
#include "CreateRockMessage.h"
FallingRockTrap::FallingRockTrap()
{
	m_timestamp.SetCurrAnim("FallingRock");
	m_timestamp.SetCurrFrame(0);
	m_timestamp.SetElapsedTime(0);
	m_timestamp.SetOwner(this);
}


FallingRockTrap::~FallingRockTrap()
{
}


void FallingRockTrap::Render()
{
	////camera offest
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
	SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 255, 0, 0 }, {}, 3);
	//SGD::GraphicsManager::GetInstance()->DrawTextureSection(GetImage(), pt, { 11, 71, 218, 200 }, {}, {}, {}, SGD::Size{ 0.7f, 0.7f });
	AnimationSystem::GetInstance()->Render(m_timestamp, (int)pt.x, (int)pt.y, { 1, 1 });
}

void FallingRockTrap::Update(float _elapsedtime)
{
	if (m_Timer <= 0)
	{

		CreateRockMessage* m_Cannonball = new CreateRockMessage(this);
		SGD::MessageManager::GetInstance()->QueueMessage(m_Cannonball);
		m_Cannonball = nullptr;
		m_Timer = 3.0;
	}

	if (m_Timer > 0)
	{
		m_Timer -= _elapsedtime;
	}
	//Actor::Update(_elapsedtime);
}

SGD::Rectangle FallingRockTrap::GetRect(void) const
{
	SGD::Point p = m_ptPosition;
	return AnimationSystem::GetInstance()->GetRect(m_timestamp, (int)p.x, (int)p.y);
}

void FallingRockTrap::HandleCollision(IEntity* pOther)
{

}
