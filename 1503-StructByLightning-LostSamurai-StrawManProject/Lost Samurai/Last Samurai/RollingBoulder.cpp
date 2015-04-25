#include "RollingBoulder.h"
#include "Game.h"
#include "DestroyActorMessage.h"
RollingBoulder::RollingBoulder()
{
	m_Timestamp.SetCurrAnim("Rolling");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
}


RollingBoulder::~RollingBoulder()
{
}

void RollingBoulder::Update(float _elapsedtime)
{
	Actor::Update(_elapsedtime);
}

void RollingBoulder::Render()
{

	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { (GetPosition().x - PositionOffset.x), (GetPosition().y - PositionOffset.y) };

	//SGD::Rectangle re = GetRect();
	//re.left -= Game::GetInstance()->GetCameraPosition().x;
	//re.right -= Game::GetInstance()->GetCameraPosition().x;
	//re.top -= Game::GetInstance()->GetCameraPosition().y;
	//re.bottom -= Game::GetInstance()->GetCameraPosition().y;
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	//draw rect

	AnimationSystem::GetInstance()->Render(m_Timestamp, pt.x, pt.y, SGD::Size{ 1.0f, 1.0f });
}

void RollingBoulder::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_TRIGGER)
	{
		DestroyActorMessage* destroy = new DestroyActorMessage{ this };
		destroy->QueueMessage();
		destroy = nullptr;
	}
	if (pOther->GetType() == ENT_FATHER || pOther->GetType() == ENT_SON)
	{
		SGD::Event* CannonBallHit = new SGD::Event("Death", nullptr, this);
		CannonBallHit->QueueEvent(pOther);
		DestroyActorMessage* destroy = new DestroyActorMessage{ this };
		destroy->QueueMessage();
		destroy = nullptr;

	}
}
