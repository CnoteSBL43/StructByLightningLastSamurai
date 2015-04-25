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
#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_MessageManager.h"

// this is Getting the Instance of the Game so that it can be a singleton 
Game* Game::m_Instance = nullptr;

//*********************************************************************//
//	File: Game.cpp
//	Function: GetInstance
//	Parameters: None
//	Return type: Game* - (An Game Pointer);
//  What it is used for:
// this is used to make a singleton 
//
//*********************************************************************//
Game* Game::GetInstance()
{
	// This is an if Check, Checking is m_Instance is a Nullptr 
	// If it you will new alocate a Game to it
	// Then Return the newly Alocated Game Instance
	if (m_Instance == nullptr)
		m_Instance = new Game;
	return m_Instance;
}

//*********************************************************************//
//	File: Game.cpp
//	Function: DeleteInstance
//	Parameters: None
//	Return type: Void
//  What it is used for:
//  It is used to Delete the Singleton 
//
//*********************************************************************//
void Game::DeleteInstance()
{
	// This is where you are going to delete your m_Instance 
	delete m_Instance;
	// After you Delete your m_Instance you are going to set it to a Null Pointer (SAFE CHECK)
	m_Instance = nullptr;
}

//*********************************************************************//
//	File: Game.cpp
//	Function: ChangeState
//	Parameters: IGameState* - ( A IGameState Pointer)
//	Return type: Void
//  What it is used for:
//  To Switch between States 
//
//*********************************************************************//
void Game::ChangeState(IGameState* _NextState)
{
	// This is an If Check that will Check if m_CurrentState is not  NUll Pointer 
	if (m_CurrentState != nullptr)
		// This will exit the State the m_CurrentState is At, at the moment in time 
		m_CurrentState->Exit();
	// This will go to the next state that it assigned to in the pramater 
	m_CurrentState = _NextState;

	// This is an If Check that will Check if m_CurrentState is not  NUll Pointer 
	if (m_CurrentState != nullptr)
		// this will Enter the new state that you want to go in 
		m_CurrentState->Enter();
}

//*********************************************************************//
//	File: Game.cpp
//	Function: Initialize
//	Parameters: None
//	Return type: Boolean
//  What it is used for:
// To Initialize all of the Variables in Game.cpp  
//
//*********************************************************************//
bool Game::Initialize()
{
	// This is Seeding The Random Generator in the Compiler 
	srand((unsigned int)time(nullptr));

	// This is a If check that is Using the SGD Grphics Manager 
	// It is going to Initialize the Window. Call the Window "LOST SAMURAI" and set the Screen Size 
	if (SGD::GraphicsManager::GetInstance()->Initialize(L"Lost Samurai", m_szScreenSize, false) == false ||
		SGD::InputManager::GetInstance()->Initialize() == false ||
		SGD::AudioManager::GetInstance()->Initialize() == false)
		return false;
//	bg = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/okay.jpg");

	// Initialize the Event & Message Managers
	SGD::EventManager::GetInstance()->Initialize();
	font.LoadLookUpChart("../resource/XML/font.xml");



#if !defined( DEBUG ) && !defined( _DEBUG )
	SGD::GraphicsManager::GetInstance()->ShowConsoleWindow(false);
#endif
	// This is changeing the State to the Splash screen when you First enter the Game 
	ChangeState(SplashState::GetInstance());
	// This is used to Get the Time that is stored from the begining of the Compiler 
	m_GameTime = GetTickCount();

	//Read Character info
	//Reading the options file
	// This is a Tiny XML Document you Need to make to Load from a File
	TiXmlDocument m_Document;
	// This is an If Check that will check if there is a File Named "Options" if not it will make one 
	if (m_Document.LoadFile("Options") == false)
	{
		// This is a Tiny XML Document you Need to make to Load from a File
		TiXmlDocument m_Document;
		// This is a Tiny XML Declaration, You nee this to Make XML Work Properly
		TiXmlDeclaration* m_Declare = new TiXmlDeclaration{ "1.0", "utf - 8", "" };
		// After you Get the Declaration you WIll Link it to the Documents EndChild
		m_Document.LinkEndChild(m_Declare);
		// YOu Will Make a Tiny XML XElement Pointer and Dynamiclly Alcoate it And make the XML FIle Name 
		TiXmlElement* m_Element = new TiXmlElement{ "Options.xml" };
		// After you Make the XElement you Will Link it to the Document Again 
		m_Document.LinkEndChild(m_Element);
		// With the newly Alocated XElement Pointer you Will Get Its Double Attribute 
		// This Double Attribute will Set the Music Volume With a string and a Integer variable
		m_Element->SetDoubleAttribute("MusicVolume", m_MusicVol);
		// This Double Attribute will Set the SFX Volume With a string and a Integer variable
		m_Element->SetDoubleAttribute("SFXVolume", m_SFXVol);
		// This Double Attribute will Set the FULLScreen With a string and a Boolean variable
		m_Element->SetDoubleAttribute("FullScreen", m_FullScreen);
		m_Element->SetDoubleAttribute("Language", m_Language);
		// After you Get done saveing all your variables inside the XML file you WIll The Document and save it out
		m_Document.SaveFile("Options");
	}
	else
	{
		// this will Load The XML FIle that you Created back into the Comipler 
		// this is a Variable for the Full screen 
		int fullscreen = (int)m_FullScreen;
		// You Will make a Tiny XElement Pointer and assign it to The Document
		TiXmlElement* m_Element = m_Document.RootElement();
		// Use the XElement Variable to Find the String in the XML File and then Store the Variable to the M_MusicVol Variable 
		m_Element->Attribute("MusicVolume", &m_MusicVol);
		// Use the XElement Variable to Find the String in the XML File and then Store the Variable to the m_SFXVol Variable 
		m_Element->Attribute("SFXVolume", &m_SFXVol);
		// Use the XElement Variable to Find the String in the XML File and then Store the Variable to the FullScreen Variable 
		m_Element->Attribute("FullScreen", &fullscreen);
		m_Element->Attribute("Language", &m_Language);
		// This is an If check that checks if the fullscreen variable is 0(False == 0) Or if it is 1 (True == 1)
		if (fullscreen == 0)
			m_FullScreen = false;
		else
			m_FullScreen = true;
	}
	// You will Set the FullScreen Variable to the Fullscreen Function 
	SetFullScreen(m_FullScreen);
	// You will Set the Music  Variable to the MusicVolume Function 
	SetMusicVolume(m_MusicVol);
	// You will Set the SFX  Variable to the SFXVolume Function 
	SetSFXVolume(m_SFXVol);

	return true;
}


//*********************************************************************//
//	File: Game.cpp
//	Function: Update
//	Parameters: None
//	Return type: Integer 
//  What it is used for:
// To Update the Current State
//
//*********************************************************************//
int Game::Update()
{
	// This is an if Check that Graphics Manager The Input Manager and the Audio Manager Are all true
	// If not then Return 1
	if (SGD::GraphicsManager::GetInstance()->Update() == false ||
		SGD::InputManager::GetInstance()->Update() == false ||
		SGD::AudioManager::GetInstance()->Update() == false)
		return 1;



	// This will Set the Current Time the Get Tick count 
	unsigned long CurrentTime = GetTickCount();
	// you are doing an equation to get the elapseTime  
	float ElapsedTime = (CurrentTime - m_GameTime) / 1000.0f;
	// Then setting m_GameTime  to the CurrentTime 
	m_GameTime = CurrentTime;

	/*if (ElapsedTime > .100f)
		ElapsedTime = .100f;*/

	if (m_CurrentState->Update(ElapsedTime) == false)
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

//	SGD::GraphicsManager::GetInstance()->DrawTexture(bg, { 0, 0 });
	m_CurrentState->Render(ElapsedTime);
	return 0;
}

//*********************************************************************//
//	File: Game.cpp
//	Function: Terminate
//	Parameters: None
//	Return type: Void
//  What it is used for:
//  To destory all of the variables that were Initialized 
//
//*********************************************************************//
void Game::Terminate()
{
	font.Terminate();
	SetLevel(0);
	AnimationSystem::GetInstance()->Exit();
	SGD::GraphicsManager::GetInstance()->UnloadTexture(bg);
	ChangeState(nullptr);
	SGD::AudioManager::GetInstance()->Terminate();
	SGD::AudioManager::GetInstance()->DeleteInstance();

	SGD::InputManager::GetInstance()->Terminate();
	SGD::InputManager::GetInstance()->DeleteInstance();

	SGD::GraphicsManager::GetInstance()->Terminate();
	SGD::GraphicsManager::GetInstance()->DeleteInstance();

	SGD::EventManager::GetInstance()->Terminate();
	SGD::EventManager::GetInstance()->DeleteInstance();

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

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) || SGD::InputManager::GetInstance()->IsButtonPressed(0, 9))
	{
		m_PreviousState->Exit();
		m_PreviousState = nullptr;
	}
	else
		m_CurrentState->Enter();
}
