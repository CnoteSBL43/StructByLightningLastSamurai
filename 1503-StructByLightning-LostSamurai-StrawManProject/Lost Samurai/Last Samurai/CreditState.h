#pragma once
#include "IGameState.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include"../SGD Wrappers/SGD_InputManager.h"
#include"MainMenuState.h"
#include"Game.h"

class CreditState :
	public IGameState
{
private:
	CreditState() = default;
	~CreditState() = default;
	CreditState(const CreditState&) = delete;
	CreditState& operator= (const CreditState&) = delete;

public:
	static CreditState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

