#pragma once
#include "../SGD Wrappers/SGD_Handle.h"
#include"../SGD Wrappers/SGD_Geometry.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
#include "../SGD Wrappers/SGD_Utilities.h"
#include "SplashState.h"

class IGameState;

class Game
{
private:
	static Game* m_Instance;
	Game() = default;
	~Game() = default;
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	IGameState* m_CurrentState = nullptr;
	unsigned long m_GameTime = 0;

	int m_MusicVol = 100, m_SFXVol = 100;
	bool m_FullScreen = false;



public:
	//Singleton
	static Game* GetInstance();
	static void DeleteInstance();

	SGD::Size	GetScreenSize(void) const		{ return m_szScreenSize; }
	SGD::Point	GetCameraPosition(void)const	{ return m_CameraPosition; }
	SGD::Size	GetWorldSize(void)const			{ return m_szWorldSize; }
	void SetCameraPosition(SGD::Point _pos){ m_CameraPosition = _pos; }

	bool GetFullScreen(){ return m_FullScreen; }
	void SetFullScreen(bool _screen){ m_FullScreen = _screen; }

	int GetMusicVolume(){ return m_MusicVol; }
	void SetMusicVolume(int _musicVol){ m_MusicVol = _musicVol; }

	int GetSFXVolume(){ return m_SFXVol; }
	void SetSFXVolume(int _sfxVol){ m_SFXVol = _sfxVol; }


	//Setup,Play,Cleanup
	bool Initialize();
	int Update();
	void Terminate();

	SGD::Size		m_szScreenSize = SGD::Size{ 800, 600 };
	SGD::Size		m_szWorldSize = SGD::Size{ 1024, 1024};
	SGD::Point		m_CameraPosition;

	//State Mutator
	void ChangeState(IGameState* _NextState);

};

