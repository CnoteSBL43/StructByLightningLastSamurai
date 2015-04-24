#pragma once
#include<Windows.h>
#include "IGameState.h"
#include "Game.h"
#include "../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include"MainMenuState.h"
#include"InstructionsState.h"


class SplashState :
	public IGameState
{
private:
	SplashState() = default;
	~SplashState() = default;
	SplashState(const SplashState&) = delete;
	SplashState& operator= (const SplashState&) = delete;
	SGD::HTexture m_TeamLogo = SGD::INVALID_HANDLE;
	float time = 0.0f;
	SGD::HAudio SplashMusic;
	SGD::HAudio Select;
public:
	static SplashState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

