#pragma once
#include "../SGD Wrappers/SGD_Handle.h"
#include"../SGD Wrappers/SGD_Geometry.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
#include "../SGD Wrappers/SGD_Utilities.h"
#define WINDOW_WIDTH		((int)800)									// window width
#define WINDOW_HEIGHT		((int)600)									// window height
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
	bool m_PlaySound = true;
	bool m_FullScreen = false;


public:
	//Singleton
	static Game* GetInstance();
	static void DeleteInstance();

	SGD::Size	GetScreenSize(void) const		{ return m_szScreenSize; }
	SGD::Point	GetCameraPosition(void)const	{ return m_CameraPosition; }
	SGD::Size	GetWorldSize(void)const			{ return m_szWorldSize; }
	void SetCameraPosition(SGD::Point _pos){ m_CameraPosition = _pos; }
	/*void SetCamVector(SGD::Vector _vec){ m_CamVector = _vec;}
	SGD::Vector GetCameraVector(void)const { return m_CamVector; }*/
	bool GetFullScreen(){ return m_FullScreen; }
	void SetFullScreen(bool _screen){ m_FullScreen = _screen; }
	//Setup,Play,Cleanup
	bool Initialize();
	int Update();
	void Terminate();

	SGD::Size		m_szScreenSize = SGD::Size{ 800, 600 };
	SGD::Size		m_szWorldSize = SGD::Size{ 1024, 1024};
	SGD::Point		m_CameraPosition;
	SGD::Vector m_CamVector;

	//State Mutator
	void ChangeState(IGameState* _NextState);

	float GetScreenWidth() const
	{
		return m_fScreenWidth;
	}

	float GetScreenHeight() const
	{
		return m_fScreenHeight;
	}

	bool GetPlaySound()
	{
		return m_PlaySound;
	}
	void SetPlaySound(bool _PlaySound)
	{
		m_PlaySound = _PlaySound;
	}


private:
	float					m_fScreenWidth = 1.0f;
	float					m_fScreenHeight = 1.0f;
};

