#include "OptionState.h"

OptionState* OptionState::GetInstance()
{
	static OptionState m_Instance;
	return &m_Instance;
}

void OptionState::Enter()
{

}

void OptionState::Exit()
{

}

bool OptionState::Update(float _ElapsedTime)
{
	return true;
}

void OptionState::Render(float _ElapsedTime)
{

}