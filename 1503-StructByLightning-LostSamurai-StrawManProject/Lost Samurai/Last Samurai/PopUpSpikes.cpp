#include "PopUpSpikes.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "DestroyActorMessage.h"
#include "Game.h"
PopUpSpikes::PopUpSpikes()
{
}


PopUpSpikes::~PopUpSpikes()
{
}


void PopUpSpikes::Render()
{
	SGD::Rectangle re = GetRect();
	re.left -= Game::GetInstance()->GetCameraPosition().x;
	re.right -= Game::GetInstance()->GetCameraPosition().x;
	re.top -= Game::GetInstance()->GetCameraPosition().y;
	re.bottom -= Game::GetInstance()->GetCameraPosition().y;
	SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect())
	Spike::Render();
}

SGD::Rectangle PopUpSpikes::GetRect() const
{
	SGD::Size size = { 175, 128 };
	SGD::Rectangle rect = { { m_ptPosition.x - 400, m_ptPosition.y + 10 }, size };
	return rect;
}

void PopUpSpikes::Update(float _elapsedtime)
{
	if (isActive == true)
	{
		m_vtVelocity.y = 20;
		if (m_ptPosition.y >= bottom.y)
			isActive = false;
	}
	else
	{
		m_vtVelocity.y = -220;
		if (m_ptPosition.y <= m_currentpos.y)
			isActive = true;
	}
	Actor::Update(_elapsedtime);
}

void	PopUpSpikes::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == Actor::ENT_FATHER)
	{
		SGD::Event* CannonBallHit = new SGD::Event("Death1", nullptr, this);
		CannonBallHit->QueueEvent(pOther);
		//delete CannonBallHit;
	}
}
