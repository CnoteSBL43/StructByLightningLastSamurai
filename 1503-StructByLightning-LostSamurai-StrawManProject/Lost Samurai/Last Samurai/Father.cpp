#include "Father.h"
#include "Game.h"

Father::Father()
{
	CreateFrames();
}


Father::~Father()
{
}
void Father::CreateFrames()
{
	
	frames.push_back({ { 0, 22, 45, 95 }, { 22, 90 } });
	frames.push_back({ { 44, 22, 85, 95 }, { 22, 90 } });
	frames.push_back({ { 84, 22, 117, 95 }, { 22, 90 } });
	frames.push_back({ { 118, 22, 162, 95 }, { 22, 90 } });
	frames.push_back({ { 163, 22, 215, 95 }, { 22, 90 } });
}

void Father::BackPack()
{

}

void	 Father::Update(float elapsedTime)
{
	if (GetCurrCharacter() )
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
			Player::SetCurrCharacter(1);

		if (direction > 4)
			direction = 0;
		frameswitch += elapsedTime;
		Actor::Update(elapsedTime);
	}


}
void	 Father::Render(void)
{
	
	SGD::Rectangle frame = frames[direction].rFrame;

	if (m_FacingtoRight)
	{
		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		{ m_ptPosition.x- Game::GetInstance()->GetCameraPosition().x, m_ptPosition.y-Game::GetInstance()->GetCameraPosition().y },
		frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ GetSize().width, GetSize().height });
	}
	else
	{
		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x-64.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y },
		frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ -GetSize().width, GetSize().height });
	}
}

SGD::Rectangle  Father::GetRect(void)	const
{
	return SGD::Rectangle{ 10.0f, 0.0f, 0.0f, 0.0f };
}
void	 Father::HandleCollision(const IEntity* pOther)
{

}
