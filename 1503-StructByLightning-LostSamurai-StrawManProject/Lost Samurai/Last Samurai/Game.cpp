#include "Game.h"

#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
#include "../SGD Wrappers/SGD_Utilities.h"
#include "IGameState.h"
#include "SplashState.h"

#include <ctime>
#include <cstdlib>
#include <cassert>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

Game* Game::m_Instance = nullptr;

Game* Game::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new Game;
	return m_Instance;
}

void Game::DeleteInstance()
{
	delete m_Instance;
	m_Instance = nullptr;
}

void Game::ChangeState(IGameState* _NextState)
{
	if (m_CurrentState != nullptr)
	{
		m_CurrentState->Exit();
	}
	m_CurrentState = _NextState;

	if (m_CurrentState != nullptr)
	{
		m_CurrentState->Enter();
	}
}

bool Game::Initialize()
{
	srand((unsigned int)time(nullptr));

	if (SGD::GraphicsManager::GetInstance()->Initialize(L"Lost Samurai", m_ScreenSize, false) == false || 
		   SGD::InputManager::GetInstance()->Initialize() == false || 
		   SGD::AudioManager::GetInstance()->Initialize() == false)
		return false;
#if !defined( DEBUG ) && !defined( _DEBUG )
	SGD::GraphicsManager::GetInstance()->ShowConsoleWindow(false);
#endif
	ChangeState(SplashState::GetInstance());

	m_GameTime = GetTickCount();
	return true;
}

int Game::Update()
{
	if (SGD::GraphicsManager::GetInstance()->Update() == false ||
		SGD::InputManager::GetInstance()->Update() == false ||
		SGD::AudioManager::GetInstance()->Update() == false)
		return 1;
	unsigned long CurrentTime = GetTickCount();
	float ElapsedTime = (CurrentTime - m_GameTime) / 1000.0f;
	m_GameTime = CurrentTime;

	if (m_CurrentState->Update(ElapsedTime)== false)
	{
	return 1;
	}
	m_CurrentState->Render(ElapsedTime);
	return 0;
}

void Game::Terminate()
{
	ChangeState(nullptr);
	SGD::AudioManager::GetInstance()->Terminate();
	SGD::AudioManager::GetInstance()->DeleteInstance();

	SGD::InputManager::GetInstance()->Terminate();
	SGD::InputManager::GetInstance()->DeleteInstance();

	SGD::GraphicsManager::GetInstance()->Terminate();
	SGD::GraphicsManager::GetInstance()->DeleteInstance();
}