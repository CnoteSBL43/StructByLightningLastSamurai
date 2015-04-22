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
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) || time >= 8.0f ||  (SGD::InputManager::GetInstance()->IsButtonPressed(0, 9)))
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	

	return true;
}

void SplashState::Render(float _ElapsedTime)
{
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_TeamLogo, SGD::Point(160.0f, 150.0f));
	if (Game::GetInstance()->GetLanguage()==0)
	{
		Game::GetInstance()->GetFont().Draw("Press Esc to Skip", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 80, 375), 0.4f,SGD::Color(250, 0,0));
	}
	else
		Game::GetInstance()->GetFont().Draw("Presione Esc Para Saltar", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 80, 375), 0.4f,SGD::Color(250, 0,0));
	
}