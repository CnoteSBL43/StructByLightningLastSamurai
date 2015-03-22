#include "CreditState.h"

CreditState* CreditState::GetInstance()
{
	static CreditState m_Instance;
	return &m_Instance;
}

void CreditState::Enter()
{

}

void CreditState::Exit()
{

}

bool CreditState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	return true;
}

void CreditState::Render(float _ElapsedTime)
{
	SGD::GraphicsManager::GetInstance()->DrawString(L"Credits", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 10, 10), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Shawn Paris", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 50), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Jacob Keffer", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 100), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Cory Saunders", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 150), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Blake Bergstorm", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 200), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Varun Kumar", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 250), SGD::Color(0, 255, 0));


}
