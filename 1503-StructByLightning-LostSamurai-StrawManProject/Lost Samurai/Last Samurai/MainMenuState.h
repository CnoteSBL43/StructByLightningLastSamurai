#pragma once
#include <Windows.h>
#include "IGameState.h"
#include "../SGD Wrappers/SGD_Handle.h"
#include "InstructionsState.h"
#include "OptionState.h"
#include "CreditState.h"
#include "GameplayState.h"

class MainMenuState :
	public IGameState
{
private:
	MainMenuState() = default;
	~MainMenuState() = default;
	MainMenuState(const MainMenuState&) = delete;
	MainMenuState& operator= (const MainMenuState&) = delete;
	SGD::HTexture m_MainMenu = SGD::INVALID_HANDLE;
	SGD::HTexture m_Instructions = SGD::INVALID_HANDLE;
	SGD::HTexture m_Options = SGD::INVALID_HANDLE;
	SGD::HTexture m_Credits = SGD::INVALID_HANDLE;
	SGD::HTexture m_Exit = SGD::INVALID_HANDLE;
	SGD::HAudio m_GameMusic = SGD::INVALID_HANDLE;
	int m_CursorPos = 0;

public:
	static MainMenuState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);

};

