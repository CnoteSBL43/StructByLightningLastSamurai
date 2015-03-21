#include "InstructionsState.h"

InstructionsState* InstructionsState::GetInstance()
{
	static InstructionsState m_Instance;
	return &m_Instance;
}

void InstructionsState::Enter()
{

}

void InstructionsState::Exit()
{

}

bool InstructionsState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	return true;
}

void InstructionsState::Render(float _ElapsedTime)
{
	SGD::GraphicsManager::GetInstance()->DrawString(L"Instructions", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 50, 10), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Left Arrow", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 50), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Move Left", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 + 50, 50), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Right Arrow", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 100), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Move Right", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 + 50, 100), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Spacebar", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 100, 150), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Jump", SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 + 50, 150), SGD::Color(0, 255, 0));
}  ;