#include "Son.h"
#include "Game.h"

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
		if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::J))
			Player::SetCurrCharacter(0);

		if (direction > 4)
			direction = 0;
		frameswitch += elapsedTime;
		Actor::Update(elapsedTime);
	}


}
void	 Son::Render(void)
{
	SGD::Rectangle frame = frames[direction].rFrame;

	if (m_FacingtoRight)
	{
		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y },
		frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ GetSize().width, GetSize().height });
	}
	else
	{
		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x-16.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y },
		frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ -GetSize().width, GetSize().height });
	}
}

SGD::Rectangle  Son::GetRect(void)	const
{
	return SGD::Rectangle{ 10.0f, 0.0f, 0.0f, 0.0f };
}
void	 Son::HandleCollision(const IEntity* pOther)
{

}
