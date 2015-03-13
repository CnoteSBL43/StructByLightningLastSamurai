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
	return true;
}

void InstructionsState::Render(float _ElapsedTime)
{

}