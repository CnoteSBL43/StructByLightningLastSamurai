#include "SplashState.h"

SplashState* SplashState::GetInstance()
{
	static SplashState m_Instance;
	return &m_Instance;
}

void SplashState::Enter()
{

}

void SplashState::Exit()
{

}

bool SplashState::Update(float _ElapsedTime)
{
	return true;
}

void SplashState::Render(float _ElapsedTime)
{

}