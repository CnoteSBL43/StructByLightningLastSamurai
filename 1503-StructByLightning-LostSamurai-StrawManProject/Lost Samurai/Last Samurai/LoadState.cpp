#include "LoadState.h"


LoadState* LoadState::GetInstance()
{
	static LoadState m_Instance;
	return &m_Instance;
}

void LoadState::Enter()
{

}

void LoadState::Exit()
{

}

bool LoadState::Update(float _ElapsedTime)
{
	return true;
}

void LoadState::Render(float _ElapsedTime)
{

}