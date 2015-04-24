#include "Arrow.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"
#include "DestroyActorMessage.h"
#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_Event.h"

Arrow::Arrow()
{
	m_Timestamp.SetCurrAnim("Arrow");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
}


Arrow::~Arrow()
{
}


void Arrow::SetDartCannon(Actor* _Cannon)
{
	m_DartCannon = _Cannon;
}
void Arrow::Render()
{


	//camera offest
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { (GetPosition().x - PositionOffset.x) - 10, (GetPosition().y - PositionOffset.y) };

	SGD::Rectangle re = GetRect();
	re.left -= Game::GetInstance()->GetCameraPosition().x;
	re.right -= Game::GetInstance()->GetCameraPosition().x;
	re.top -= Game::GetInstance()->GetCameraPosition().y;
	re.bottom -= Game::GetInstance()->GetCameraPosition().y;
	SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	//draw rect
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 0, 0, 0 }, {}, 3);
	//SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt, {}, {}, {}, SGD::Size{ 0.7f, 0.7f });
	AnimationSystem::GetInstance()->Render(m_Timestamp, pt.x, pt.y, SGD::Size{ .3f, .3f });
	/*if (Debug)
	{*/


}
void Arrow::Update(float elapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false)
		Debug = true;

	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true)
		Debug = false;

	Actor::Update(elapsedTime);

}
int	Arrow::GetType(void) const
{

	return ENT_ARROW;
}
//SGD::Rectangle GetRect(void) const;
void Arrow::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_TILES)
	{

		DestroyActorMessage* destroy = new DestroyActorMessage{ this };
		destroy->QueueMessage();
		destroy = nullptr;


	}

	if (pOther->GetType() == ENT_FATHER)
	{
		SGD::Event* CannonBallHit = new SGD::Event("Death1", nullptr, this);
		CannonBallHit->QueueEvent(pOther);
		DestroyActorMessage* destroy = new DestroyActorMessage{ this };
		destroy->QueueMessage();
		destroy = nullptr;

	}


}
SGD::Rectangle Arrow::GetRect() const
{

	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, m_ptPosition.x, m_ptPosition.y, SGD::Size{ 1, 1 });
}