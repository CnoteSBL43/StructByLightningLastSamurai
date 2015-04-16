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
	SGD::HAudio m_GameMusic = SGD::INVALID_HANDLE;
	SGD::HTexture m_Pointer = SGD::INVALID_HANDLE;
	int m_CursorPos = 0;
	bool isLoading = false;

public:
	static MainMenuState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

