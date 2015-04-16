#include "Swordsman.h"
#include "Game.h"
#include "Son.h"
#include <sstream>
//#include "AnimationSystem.h"
Swordsman::Swordsman()
{
	m_Timestamp.SetCurrAnim("SwordsmanIdle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
	//CreateFrames();
}


Swordsman::~Swordsman()
{
}




void	 Swordsman::Update(float elapsedTime)
{
	if (toRight)
	{
		SetDestination(m_ptPosition.x + 256.0f);
		toRight = false;
	}
	if (m_ptPosition.x >= destination && !toLeft)
	{
		m_facingRight = false;
		m_vtVelocity.x = -64.0f;
		SetDestination(GetDestination() - 256.0f);
		toLeft = true;
	}
	if (toRight == false && toLeft && m_ptPosition.x <= destination)
	{
		m_facingRight = true;
		toRight = true;
		toLeft = false;
		m_vtVelocity.x = 64.0f;
	}
	//SGD::GraphicsManager::GetInstance()->DrawLine(SGD::Point{m_ptPosition.x,destination},)
	frameswitch += elapsedTime;
	Actor::Update(elapsedTime);
}

void	 Swordsman::Render(void)
{
	//SGD::Rectangle frame = frames[direction].rFrame;
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false)
		Debug = true;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true)
		Debug = false;
	if (Debug)
	{
		SGD::Rectangle re = GetRect();
		re.left -= Game::GetInstance()->GetCameraPosition().x;
		re.right -= Game::GetInstance()->GetCameraPosition().x;
		re.top -= Game::GetInstance()->GetCameraPosition().y;
		re.bottom -= Game::GetInstance()->GetCameraPosition().y;
		SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	}

	SGD::Point p = m_ptPosition;
	p.x -= Game::GetInstance()->GetCameraPosition().x;
	p.y -= Game::GetInstance()->GetCameraPosition().y;
	if (m_facingRight)
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, { -1, 1 });
	else
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, { 1, 1 });
}

SGD::Rectangle  Swordsman::GetRect(void)	const
{
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, (int)m_ptPosition.x, (int)m_ptPosition.y, { 1, 1 });//SGD::Rectangle(SGD::Point{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x - 54.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y + 6.0f }, SGD::Size{ 45, 99 });
}
void Swordsman::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_SON || pOther->GetType() == ENT_FATHER)
	{

	}
}
