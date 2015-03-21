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
class TileSystem;
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


public:
	//Singleton
	static Game* GetInstance();
	static void DeleteInstance();

	//Setup,Play,Cleanup
	bool Initialize();
	int Update();
	void Terminate();

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

