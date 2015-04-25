#include "PopUpSpikes.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "DestroyActorMessage.h"
#include "Game.h"
PopUpSpikes::PopUpSpikes()
{
	m_Timestamp.SetCurrAnim("PopupSpikes");
	m_Timestamp.SetCurrFrame(currframe);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);

}


PopUpSpikes::~PopUpSpikes()
{
}


void PopUpSpikes::Render()
{
	//SGD::Rectangle re = GetRect();
	//re.left -= Game::GetInstance()->GetCameraPosition().x;
	//re.right -= Game::GetInstance()->GetCameraPosition().x;
	//re.top -= Game::GetInstance()->GetCameraPosition().y;
	//re.bottom -= Game::GetInstance()->GetCameraPosition().y;
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	SGD::Point pt = { GetPosition().x - PositionOffset.x, GetPosition().y - PositionOffset.y };
	AnimationSystem::GetInstance()->Render(m_Timestamp, pt.x, pt.y);
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect())
	//Spike::Render();
}

SGD::Rectangle PopUpSpikes::GetRect() const
{
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, m_ptPosition.x, m_ptPosition.y);
}

void PopUpSpikes::Update(float _elapsedtime)
{

	if (AnimationSystem::GetInstance()->GetLoaded()[m_Timestamp.GetCurrAnim()].GetFrames()[currframe].GetTimer() <= frametimer)
	{
		if (currframe < AnimationSystem::GetInstance()->GetLoaded()[m_Timestamp.GetCurrAnim()].GetFrames().size() - 1)
		{
			currframe++;
			m_Timestamp.SetCurrFrame(currframe);
		}
		else
		{
			currframe = 0;
			m_Timestamp.SetCurrFrame(currframe);
		}
		frametimer = 0.0f;
	}
	frametimer += _elapsedtime;
	//	Actor::Update(_elapsedtime);
}

void	PopUpSpikes::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == Actor::ENT_FATHER || pOther->GetType() == Actor::ENT_SON)
	{
		SGD::Event* CannonBallHit = new SGD::Event("Death", nullptr, this);
		CannonBallHit->QueueEvent(pOther);
		//delete CannonBallHit;
	}
}
