#include "SmashingColumns.h"
#include "Game.h"
#include "GameplayState.h"
SmashingColumns::SmashingColumns()
{
	m_timestamp.SetCurrAnim("Smashing");
	m_timestamp.SetCurrFrame(0);
	m_timestamp.SetElapsedTime(0);
	m_timestamp.SetOwner(this);

	m_currentpos = { m_ptPosition.x, 38 };
	bottom = { m_ptPosition.x, m_ptPosition.y + (150.0f) };
}


SmashingColumns::~SmashingColumns()
{
}


void SmashingColumns::Render()
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
	//SGD::GraphicsManager::GetInstance()->DrawTextureSection(GetImage(), pt, { 11, 71, 218, 200 }, {}, {}, {}, SGD::Size{ 0.7f, 0.7f });
	AnimationSystem::GetInstance()->Render(m_timestamp, (int)pt.x, (int)pt.y, { 1, 1 });


}

void SmashingColumns::Update(float _elapsedtime)
{
	if (isActive == true)
	{
		if (m_ptPosition.y <= m_currentpos.y)
			m_vtVelocity.y = 220;
		isActive = false;
	}
	else
	{
		if (m_ptPosition.y >= bottom.y)
			m_vtVelocity.y = -20;
		isActive = true;
	}
	Actor::Update(_elapsedtime);
}

SGD::Rectangle SmashingColumns::GetRect(void) const
{
	SGD::Point p = m_ptPosition;
	return AnimationSystem::GetInstance()->GetRect(m_timestamp, (int)p.x, (int)p.y);

}

void SmashingColumns::HandleCollision(IEntity* pOther)
{

	if (pOther->GetType() == Actor::ENT_FATHER || pOther->GetType() == Actor::ENT_SON)
	{
		SGD::Event* CannonBallHit = new SGD::Event("Death1", nullptr, this);
		CannonBallHit->QueueEvent(pOther);
		//delete CannonBallHit;
	}
}

