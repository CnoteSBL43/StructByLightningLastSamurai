#include "LoadGameState.h"


LoadGameState* LoadGameState::GetInstance()
{
	static LoadGameState m_Instance;
	return &m_Instance;
}

void LoadGameState::Enter()
{

}

void LoadGameState::Exit()
{

}

bool LoadGameState::Update(float _ElapsedTime)
{
	return true;
}

void LoadGameState::Render(float _ElapsedTime)
{

}
