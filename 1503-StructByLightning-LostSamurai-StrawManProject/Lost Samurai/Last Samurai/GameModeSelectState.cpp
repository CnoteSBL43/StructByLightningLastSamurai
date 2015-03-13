#include "GameModeSelectState.h"


GameModeSelectState* GameModeSelectState::GetInstance()
{
	static GameModeSelectState m_Instance;
	return &m_Instance;
}

void GameModeSelectState::Enter()
{

}

void GameModeSelectState::Exit()
{

}

bool GameModeSelectState::Update(float _ElapsedTime)
{
	return true;
}

void GameModeSelectState::Render(float _ElapsedTime)
{

}
