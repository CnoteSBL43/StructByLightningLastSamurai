#include "Son.h"
#include "Game.h"
#include "Father.h"
Son::Son()
{
	SetPosition(SGD::Point{ 100.0f, 200.0f });
	CreateFrames();
}


Son::~Son()
{
}
void Son::CreateFrames()
{

	frames.push_back({ { 0, 22, 45, 95 }, { 22, 90 } });
	frames.push_back({ { 44, 22, 85, 95 }, { 22, 90 } });
	frames.push_back({ { 84, 22, 117, 95 }, { 22, 90 } });
	frames.push_back({ { 118, 22, 162, 95 }, { 22, 90 } });
	frames.push_back({ { 163, 22, 215, 95 }, { 22, 90 } });
}



void	 Son::Update(float elapsedTime)
{
	if (GetCurrCharacter())
	{
		if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow))
		{
			m_FacingtoRight = true;
			SetVelocity(SGD::Vector(+64.0f, 0.0f));

			m_ptPosition.x += m_vtVelocity.x * elapsedTime;
			if (frameswitch >= 0.07f)
			{
				direction++;
				frameswitch = 0.0f;
			}
		}

		else if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::LeftArrow))
		{
			m_FacingtoRight = false;
			SetVelocity(SGD::Vector(-64.0f, 0.0f));
			m_ptPosition.x += m_vtVelocity.x * elapsedTime;

			if (frameswitch >= 0.07f)
			{
				direction++;
				frameswitch = 0.0f;
			}
		}
		else
			SetVelocity(SGD::Vector(0.0f, 0.0f));
	/*	if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::J))
			Player::SetCurrCharacter(0);*/

		if (direction > 4)
			direction = 0;
		frameswitch += elapsedTime;
		Actor::Update(elapsedTime);
	}


}
void	 Son::Render(void)
{
	SGD::Rectangle frame = frames[direction].rFrame;
	SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });

	if (m_FacingtoRight)
	{
		SGD::Point p = m_ptPosition;

		p.x -= Game::GetInstance()->GetCameraPosition().x;
		p.y -= Game::GetInstance()->GetCameraPosition().y;

		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,p,
		frame, 0.0f, {}, { 255, 255, 0 }, SGD::Size{ GetSize().width, GetSize().height });
	}
	else
	{
		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x - 32.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y },
		frame, 0.0f, {}, { 255, 255, 0 }, SGD::Size{ -GetSize().width, GetSize().height });
	}

}

SGD::Rectangle  Son::GetRect(void)	const
{
	return SGD::Rectangle(SGD::Point{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x -26.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y + 4.0f }, SGD::Size{ 45/2, 99/2 });
}
void	 Son::HandleCollision( IEntity* pOther)
{
	if (pOther->GetType() == ENT_FATHER && dynamic_cast<Son*>(this)->GetBackPack())
	{	
		dynamic_cast<Son*>(this)->SetCurrCharacter(false);
	}

}
