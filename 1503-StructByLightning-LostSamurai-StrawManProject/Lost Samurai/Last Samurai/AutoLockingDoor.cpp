#include "AutoLockingDoor.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"
#include "DestroyActorMessage.h"
#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "Actor.h"
#include "AnimationTimestamp.h"

AutoLockingDoor::AutoLockingDoor()
{
	m_Timestamp.SetCurrAnim("ClosedAutoLockingDoor");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
	SGD::IListener::RegisterForEvent("P");
}



AutoLockingDoor::~AutoLockingDoor()
{
}


void AutoLockingDoor::Update(float _elspasedtime)
{
	if (isOpen == false)
		m_Timestamp.SetCurrAnim("ClosedAutoLockingDoor");
	else
		m_Timestamp.SetCurrAnim("OpenAutoLockingDoor");
}
void AutoLockingDoor::Render()
{
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { (GetPosition().x - PositionOffset.x), (GetPosition().y - PositionOffset.y) };

	SGD::Rectangle re = GetRect();
	re.left -= Game::GetInstance()->GetCameraPosition().x;
	re.right -= Game::GetInstance()->GetCameraPosition().x;
	re.top -= Game::GetInstance()->GetCameraPosition().y;
	re.bottom -= Game::GetInstance()->GetCameraPosition().y;
	//draw rect
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 0, 0, 0 }, {}, 3);
	//SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt, {}, {}, {}, SGD::Size{ 0.7f, 0.7f });
	SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	AnimationSystem::GetInstance()->Render(m_Timestamp, (int)pt.x, (int)pt.y, SGD::Size{ 1.0f, 1.0f });
	/*if (Debug)
	{*/
}
int	AutoLockingDoor::GetType(void)	const
{
	return ENT_AUTO_LOCK_DOOR;

}
SGD::Rectangle AutoLockingDoor::GetRect(void) const
{
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, (int)m_ptPosition.x, (int)m_ptPosition.y, SGD::Size{ 1.0f, 1.0f });
}


void AutoLockingDoor::HandleCollision(IEntity* pOther)
{

}

void AutoLockingDoor::HandleEvent(const SGD::Event* pEvent)
{
	if (pEvent->GetEventID() == "P")
	{
		isOpen = true;
	}




}