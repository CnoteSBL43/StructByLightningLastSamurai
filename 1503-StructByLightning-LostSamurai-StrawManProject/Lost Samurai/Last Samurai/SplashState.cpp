#include "SplashState.h"

SplashState* SplashState::GetInstance()
{
	static SplashState m_Instance;
	return &m_Instance;
}

void SplashState::Enter()
{
	m_TeamLogo = SGD::GraphicsManager::GetInstance()->LoadTexture(L"../resource/graphics/TeamLogo.png");
}
void SplashState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_TeamLogo);
}

bool SplashState::Update(float _ElapsedTime)
{
	time += _ElapsedTime;
	if(SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) || time>=10.0f)
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	

	return true;
}

void SplashState::Render(float _ElapsedTime)
{
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_TeamLogo, SGD::Point(160.0f, 150.0f));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Press Esc to Skip", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 70, 375), SGD::Color(0, 2, 150));
}