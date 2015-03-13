#include "MainMenuState.h"

MainMenuState* MainMenuState::GetInstance()
{
	static MainMenuState m_Instance;
	return &m_Instance;
}

void MainMenuState::Enter()
{

}

void MainMenuState::Exit()
{

}

bool MainMenuState::Update(float _ElapsedTime)
{
	return true;
}

void MainMenuState::Render(float _ElapsedTime)
{

}
