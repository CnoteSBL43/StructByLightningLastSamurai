#pragma once
#include "IGameState.h"
#include "Game.h"
#include <Windows.h>
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
#include "MainMenuState.h"

class InstructionsState :
	public IGameState
{
private:
	InstructionsState() = default;
	~InstructionsState() = default;
	InstructionsState(const InstructionsState&) = delete;
	InstructionsState& operator= (const InstructionsState&) = delete;
	bool Switch = false;
	bool  Arcade = false;
	SGD::HAudio m_infoMusic;

public:
	static InstructionsState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
	SGD::HTexture m_BackArrow = SGD::INVALID_HANDLE;
};

