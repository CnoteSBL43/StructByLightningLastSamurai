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
	SGD::HAudio m_CreditMusic;
public:
	static CreditState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
	SGD::HTexture m_BackArrow = SGD::INVALID_HANDLE;

};

