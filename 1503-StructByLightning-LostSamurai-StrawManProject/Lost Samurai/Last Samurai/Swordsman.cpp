#include "Swordsman.h"
#include "Game.h"
#include "Son.h"
#include <sstream>
Swordsman::Swordsman()
{
	CreateFrames();
}


Swordsman::~Swordsman()
{
}
void Swordsman::CreateFrames()
{

	frames.push_back({ { 0, 22, 45, 95 }, { 22, 90 } });
	frames.push_back({ { 44, 22, 85, 95 }, { 22, 90 } });
	frames.push_back({ { 84, 22, 117, 95 }, { 22, 90 } });
	frames.push_back({ { 118, 22, 162, 95 }, { 22, 90 } });
	frames.push_back({ { 163, 22, 215, 95 }, { 22, 90 } });
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
	frameswitch += elapsedTime;
	Actor::Update(elapsedTime);
}

void	 Swordsman::Render(void)
{
	SGD::Rectangle frame = frames[direction].rFrame;
	SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });

	if (m_facingRight)
	{
		SGD::Point p = m_ptPosition;
		p.x -= Game::GetInstance()->GetCameraPosition().x;
		p.y -= Game::GetInstance()->GetCameraPosition().y;
		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage, p,
			frame, 0.0f, {}, { 255, 100, 0 }, SGD::Size{ GetSize().width, GetSize().height });
	}
	else

		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x - 64.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y },
		frame, 0.0f, {}, { 255, 100, 0 }, SGD::Size{ -GetSize().width, GetSize().height });
	
}

SGD::Rectangle  Swordsman::GetRect(void)	const
{
	return SGD::Rectangle(SGD::Point{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x - 54.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y + 6.0f }, SGD::Size{ 45, 99 });
}
void Swordsman::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_SON || pOther->GetType() == ENT_FATHER)
	{
		
	}
}
