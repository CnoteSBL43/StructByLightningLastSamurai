#include "GameplayState.h"


GameplayState* GameplayState::GetInstance()
{
	static GameplayState m_Instance;
	return &m_Instance;
}

void GameplayState::Enter()
{

}

void GameplayState::Exit()
{

}

bool GameplayState::Update(float _ElapsedTime)
{
	return true;
}

void GameplayState::Render(float _ElapsedTime)
{

}