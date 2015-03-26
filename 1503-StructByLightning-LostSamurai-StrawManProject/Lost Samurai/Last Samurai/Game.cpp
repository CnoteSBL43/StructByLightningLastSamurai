#include "Game.h"
#include "../Last Samurai/TileSystem.h"
#include "IGameState.h"
#include <ctime>
#include <cstdlib>
#include <cassert>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "../SGD Wrappers/SGD_AudioManager.h"
#include "GameplayState.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_MessageManager.h"
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

	if (SGD::GraphicsManager::GetInstance()->Initialize(L"Lost Samurai", m_szScreenSize, false) == false || 
		   SGD::InputManager::GetInstance()->Initialize() == false || 
		   SGD::AudioManager::GetInstance()->Initialize() == false)
		return false;

	// Initialize the Event & Message Managers
	SGD::EventManager::GetInstance()->Initialize();
	//SGD::MessageManager::GetInstance()->Initialize(&Game::MessageProc);

#if !defined( DEBUG ) && !defined( _DEBUG )
	SGD::GraphicsManager::GetInstance()->ShowConsoleWindow(false);
#endif
	ChangeState(SplashState::GetInstance());

	m_GameTime = GetTickCount();

	//Reading the options file

	TiXmlDocument m_Document;
	if (m_Document.LoadFile("Options") == false)
	{
		TiXmlDocument m_Document;
		TiXmlDeclaration* m_Declare = new TiXmlDeclaration{ "1.0", "utf - 8", "" };
		m_Document.LinkEndChild(m_Declare);
		TiXmlElement* m_Element = new TiXmlElement{ "Options.xml" };
		m_Document.LinkEndChild(m_Element);
		m_Element->SetDoubleAttribute("MusicVolume", m_MusicVol);
		m_Element->SetDoubleAttribute("SFXVolume", m_SFXVol);
		m_Element->SetDoubleAttribute("FullScreen",m_FullScreen);
		m_Document.SaveFile("Options");
	}
	else
	{
		int fullscreen = (int)m_FullScreen;
		TiXmlElement* m_Element = m_Document.RootElement();
		m_Element->Attribute("MusicVolume", &m_MusicVol);
		m_Element->Attribute("SFXVolume", &m_SFXVol);
		m_Element->Attribute("FullScreen", &fullscreen);
		if (fullscreen == 0)
			m_FullScreen = false;
		else 
			m_FullScreen = true;
	}
	
	SetFullScreen(m_FullScreen);
	SetMusicVolume(m_MusicVol);
	SetSFXVolume(m_SFXVol);
	
	return true;
}



int Game::Update()
{
	if (SGD::GraphicsManager::GetInstance()->Update() == false ||
		SGD::InputManager::GetInstance()->Update() == false ||
		SGD::AudioManager::GetInstance()->Update() == false)
		return 1;

	
	//SGD::MessageManager::GetInstance()->Update();

	unsigned long CurrentTime = GetTickCount();
	float ElapsedTime = (CurrentTime - m_GameTime) / 1000.0f;
	
	m_GameTime = CurrentTime;


	if (m_CurrentState->Update(ElapsedTime)== false)
	{
		return 1;
	}

	//Fullscreen or not
	if (GetFullScreen())
		SGD::GraphicsManager::GetInstance()->Resize(SGD::Size{ GetScreenSize().width, GetScreenSize().height }, !GetFullScreen());
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Alt))
	{
		if (!GetFullScreen())
			SetFullScreen(true);
		else
			SetFullScreen(false);
		SGD::GraphicsManager::GetInstance()->Resize(SGD::Size{ GetScreenSize().width, GetScreenSize().height }, !GetFullScreen());

	}
	SGD::EventManager::GetInstance()->Update();
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

	//SGD::EventManager::GetInstance()->Terminate();
	//SGD::EventManager::GetInstance()->DeleteInstance();
}

bool Game::CheckPrevious()
{
	if (m_PreviousState == nullptr)
		return false;

	return true;
}

void Game::Pause(IGameState* m_NextState)
{
	m_PreviousState = m_CurrentState;
	m_CurrentState = m_NextState;

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		m_PreviousState->Exit();
		m_PreviousState = nullptr;
	}
	else
		m_CurrentState->Enter();
}