#include "Door.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"
#include "DestroyActorMessage.h"
#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "Actor.h"
#include "AnimationTimestamp.h"

Door::Door()
{
	m_Timestamp.SetCurrAnim("Doors");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
}


Door::~Door()
{
}


void Door::Update(float _elspasedtime)
{

}
void Door::Render()
{
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { (GetPosition().x - PositionOffset.x), (GetPosition().y - PositionOffset.y) };


	//draw rect
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 0, 0, 0 }, {}, 3);
	//SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt, {}, {}, {}, SGD::Size{ 0.7f, 0.7f });
	AnimationSystem::GetInstance()->Render(m_Timestamp, pt.x, pt.y, SGD::Size{ 1.0f, 1.0f });
	/*if (Debug)
	{*/
	SGD::Rectangle re = GetRect();
	re.left -= Game::GetInstance()->GetCameraPosition().x;
	re.right -= Game::GetInstance()->GetCameraPosition().x;
	re.top -= Game::GetInstance()->GetCameraPosition().y;
	re.bottom -= Game::GetInstance()->GetCameraPosition().y;

}
int	Door::GetType(void)	const
{
	return ENT_DOOR;

}

void Door::HandleCollision(IEntity* pOther)
{

}