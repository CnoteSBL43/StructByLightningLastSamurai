#pragma once
#include "../SGD Wrappers/SGD_Handle.h"
#include"../SGD Wrappers/SGD_Geometry.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
#include "../SGD Wrappers/SGD_Utilities.h"
#include "SplashState.h"
#include "BitmapFont.h"

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
	int m_MusicVol = 100, m_SFXVol = 100, m_Language = 0;//0-english 1 -spanish
	// This is a variable that is used to make the Game go into full screen mode 
	bool m_FullScreen = false;
	BitmapFont font;
	// This is a Size Variable that is used to adjust the Screne size of the Game 
	SGD::Size		m_szScreenSize = SGD::Size{ 800, 600 };
	// This is a Size Variable that is used to adjust the World  size of the Game 
	SGD::Size		m_szWorldSize = SGD::Size{ 1024, 800 };
	// This is a Point So that you can set the Where the camera is going to be 
	SGD::Point		m_CameraPosition;
	SGD::Vector		m_CameraPosVector;
	SGD::Vector		m_CameraDestinationVector;

	int level = 2;

public:
	//SGD::HTexture bg = SGD::INVALID_HANDLE;
	bool cameraPanningOn = false;
	// this is a Static Game Singleton GetInsatance()
	static Game* GetInstance();
	// this is a Static Game Singleton DeleteInstance()
	static void DeleteInstance();
	float jumpvelocity = 1024.0f;
	// this a Getter for the Screen Size of the Game 
	SGD::Size	GetScreenSize(void) const		{ return m_szScreenSize; }
	// this is a Getter for the World Size of the Game 
	SGD::Size	GetWorldSize(void)const			{ return m_szWorldSize; }
	// This is a Accessor for the Camera Position in the Game 
	SGD::Point	GetCameraPosition(void)const	{ return m_CameraPosition; }
	SGD::Vector GetCameraPosVector(void)const { return m_CameraPosVector; }
	SGD::Vector GetCameraDestinationVector(void)const { return m_CameraDestinationVector; }
	// This is a Mutator that is Setting the Camera's Position 
	void SetCameraPosition(SGD::Point _pos){ m_CameraPosition = _pos; }
	void SetCameraPosVector(SGD::Vector _vec){ m_CameraPosVector = _vec; }
	void SetCameraDestinationVector(SGD::Vector _vec){ m_CameraDestinationVector = _vec; }
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
	int GetLanguage(){ return m_Language; }
	void SetLanguage(int _language){ m_Language = _language; }


	//Font
	BitmapFont GetFont(){ return font; }

	//Setup,Play,Cleanup
	// This is used to Initailize all of the Variables and gamestate that will be set at the start of the game 
	bool Initialize();
	// This will Update all of the object that are in the Games Update 
	int Update();
	// This will Terminate all of the The Variables used int he Game Class 
	void Terminate();
	void Pause(IGameState* n_NextState);
	bool CheckPrevious();



	//State Mutator
	// This is going to change a state when needed 
	void ChangeState(IGameState* _NextState);

	//change level
	bool changelevel = false;
};

