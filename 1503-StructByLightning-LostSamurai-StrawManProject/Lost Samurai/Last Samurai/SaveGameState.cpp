#include "SaveGameState.h"

SaveGameState* SaveGameState::GetInstance()
{
	static SaveGameState m_Instance;
	return &m_Instance;
}

void SaveGameState::Enter()
{

}

void SaveGameState::Exit()
{

}

bool SaveGameState::Update(float _ElapsedTime)
{
	
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) )
	{
		Game::GetInstance()->Pause(GameplayState::GetInstance());
	}
	return true;
}

void SaveGameState::Render(float _ElapsedTime)
{

}