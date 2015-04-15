#include "CannonBall.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"
#include "DestroyActorMessage.h"
#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_Event.h"
CannonBall::CannonBall()
{
	m_Timestamp.SetCurrAnim("Cannonball");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
}


CannonBall::~CannonBall()
{
}


void CannonBall::SetCannon(Cannon* _Cannon)
{
	m_Cannon = _Cannon;
}
void CannonBall::Render()
{

	//camera offest
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { (GetPosition().x - PositionOffset.x), (GetPosition().y - PositionOffset.y) };


	//draw rect
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 0, 0, 0 }, {}, 3);
	//SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt, {}, {}, {}, SGD::Size{ 0.7f, 0.7f });
	AnimationSystem::GetInstance()->Render(m_Timestamp, (int)pt.x, (int)pt.y, SGD::Size{ 1.0f, 1.0f });
	/*if (Debug)
	{*/
	SGD::Rectangle re = GetRect();
	re.left -= Game::GetInstance()->GetCameraPosition().x;
	re.right -= Game::GetInstance()->GetCameraPosition().x;
	re.top -= Game::GetInstance()->GetCameraPosition().y;
	re.bottom -= Game::GetInstance()->GetCameraPosition().y;
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });


}
void CannonBall::Update(float elasped)
{

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false)
		Debug = true;

	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true)
		Debug = false;

	Actor::Update(elasped);
}
int	CannonBall::GetType(void) const
{
	return ENT_CANNONBALL;
}

void CannonBall::HandleCollision(IEntity* pOther)
{


	if (pOther->GetType() == ENT_TILES)
	{
		DestroyActorMessage* destroy = new DestroyActorMessage{ this };
		destroy->QueueMessage();
		destroy = nullptr;

	}

	if (pOther->GetType() == ENT_FATHER)
	{
		SGD::Event* CannonBallHit = new SGD::Event("Death", nullptr, this);
		CannonBallHit->QueueEvent(pOther);
		DestroyActorMessage* destroy = new DestroyActorMessage{ this };
		destroy->QueueMessage();
		destroy = nullptr;

	}


}

SGD::Rectangle CannonBall::GetRect() const
{
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, (int)m_ptPosition.x, (int)m_ptPosition.y, SGD::Size{ 1, 1 });
}