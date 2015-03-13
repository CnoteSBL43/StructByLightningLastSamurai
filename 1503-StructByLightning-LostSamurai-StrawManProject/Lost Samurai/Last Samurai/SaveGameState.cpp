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
	return true;
}

void SaveGameState::Render(float _ElapsedTime)
{

}