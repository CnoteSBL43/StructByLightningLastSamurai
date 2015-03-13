#include "PauseState.h"


PauseState* PauseState::GetInstance()
{
	static PauseState m_Instance;
	return &m_Instance;
}

void PauseState::Enter()
{

}

void PauseState::Exit()
{

}

bool PauseState::Update(float _ElapsedTime)
{
	return true;
}

void PauseState::Render(float _ElapsedTime)
{

}
