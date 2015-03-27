#pragma once
#include "../SGD Wrappers/SGD_Handle.h"
#include"../SGD Wrappers/SGD_Geometry.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
#include "../SGD Wrappers/SGD_Utilities.h"
#include "SplashState.h"


class IGameState;
class TileSystem;
class Game
{
private:
	// this is a Static Game Instance Variable 
	static Game* m_Instance;
	// This is a Default Game Constructor 
	Game() = default;
	// This is a Default Game Destructor 
	~Game() = default;
	// This is a Defualt Copy Constructor 
	Game(const Game&) = delete;
	// This is a Defualt Assignment Operator 
	Game& operator=(const Game&) = delete;
	// This is a IGameState Pointer So that you Can store the Current game State
	IGameState* m_CurrentState = nullptr;
	IGameState* m_PreviousState = nullptr;
	IGameState* pCurrentState = nullptr; //for pause menu
	
	// This is a Unsigned long Variable used to get Real time 
	unsigned long m_GameTime = 0;
	// This is used for storing the Music Volumes and SFX Volumes 
	int m_MusicVol = 100, m_SFXVol = 100;
	// This is a variable that is used to make the Game go into full screen mode 
	bool m_FullScreen = false;



public:
	// this is a Static Game Singleton GetInsatance()
	static Game* GetInstance();
	// this is a Static Game Singleton DeleteInstance()
	static void DeleteInstance();

	// this a Getter for the Screen Size of the Game 
	SGD::Size	GetScreenSize(void) const		{ return m_szScreenSize; }
	// This is a Getter for the Camera Position in the Game 
	SGD::Point	GetCameraPosition(void)const	{ return m_CameraPosition; }
	// this is a Getter for the World Size of the Game 
	SGD::Size	GetWorldSize(void)const			{ return m_szWorldSize; }
	// This is a Mutator that is Setting the Camera's Position 
	void SetCameraPosition(SGD::Point _pos){ m_CameraPosition = _pos; }
	// This is a Getter To see if the Full screen mode is true or false 
	bool GetFullScreen(){ return m_FullScreen; }
	// This is a mutator to set the fullscreen to either true or false
	void SetFullScreen(bool _screen){ m_FullScreen = _screen; }
	// This is a Getter to Get the Core Music 
	int GetMusicVolume(){ return m_MusicVol; }
	// This is a setter the sets the Volume of the Core Music 
	void SetMusicVolume(int _musicVol){ m_MusicVol = _musicVol; }
	// This is a Getter that gets the SFX Volume 
	int GetSFXVolume(){ return m_SFXVol; }
	// This is a mutator to set the Volume of the SFX 
	void SetSFXVolume(int _sfxVol){ m_SFXVol = _sfxVol; }


	//Setup,Play,Cleanup
	// This is used to Initailize all of the Variables and gamestate that will be set at the start of the game 
	bool Initialize();
	// This will Update all of the object that are in the Games Update 
	int Update();
	// This will Terminate all of the The Variables used int he Game Class 
	void Terminate();
	void Pause(IGameState* n_NextState);
	bool CheckPrevious();

	// This is a Size Variable that is used to adjust the Screne size of the Game 
	SGD::Size		m_szScreenSize = SGD::Size{ 800, 600};
	// This is a Size Variable that is used to adjust the World  size of the Game 
	SGD::Size		m_szWorldSize = SGD::Size{ 1024, 800};
	// This is a Point So that you can set the Where the camera is going to be 
	SGD::Point		m_CameraPosition;

	//State Mutator
	// This is going to change a state when needed 
	void ChangeState(IGameState* _NextState);

};

