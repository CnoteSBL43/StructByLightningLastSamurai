#include "Father.h"
#include "Game.h"
#include "Son.h"
#include <sstream>
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

		/*if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::J))
			Player::SetCurrCharacter(1);*/

		if (direction > 4)
			direction = 0;
		frameswitch += elapsedTime;
		Actor::Update(elapsedTime);
	}


}
void	 Father::Render(void)
{
	SGD::Rectangle frame = frames[direction].rFrame;
	SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });

	if (m_FacingtoRight)
	{
		SGD::Point p = m_ptPosition;
	
		p.x -= Game::GetInstance()->GetCameraPosition().x;
		p.y -=Game::GetInstance()->GetCameraPosition().y;


		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,p,
		frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ GetSize().width, GetSize().height });
	}
	else
	{
		SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x-64.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y },
		frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ -GetSize().width, GetSize().height });
	}
	/*std::wostringstream s1,s2;
	s1 << GetRect().top;
	s2 << GetRect().bottom;
	SGD::GraphicsManager::GetInstance()->DrawString(s1.str().c_str(), SGD::Point{ 20, 20 });
	SGD::GraphicsManager::GetInstance()->DrawString(s2.str().c_str(), SGD::Point{ 50, 20 });
*/

}

SGD::Rectangle  Father::GetRect(void)	const
{
	return SGD::Rectangle(SGD::Point{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x-54.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y+6.0f }, SGD::Size{ 45, 99 });
}
void Father::HandleCollision( IEntity* pOther)
{
	if (pOther->GetType() == ENT_SON)
	{
		dynamic_cast<Father*>(this)->SetCurrCharacter(true);
		dynamic_cast<Father*>(this)->SetBackPack(true);
		dynamic_cast<Son*>(pOther)->SetBackPack(true);
	}
}
