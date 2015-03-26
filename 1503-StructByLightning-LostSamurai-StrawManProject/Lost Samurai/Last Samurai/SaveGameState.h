#pragma once
#include "IGameState.h"
#include "GameplayState.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"
class SaveGameState :
	public IGameState
{
private:
	SaveGameState() = default;
	~SaveGameState() = default;
	SaveGameState(const SaveGameState&) = delete;
	SaveGameState& operator= (const SaveGameState&) = delete;
	int m_CursorPos = 0;

public:
	static SaveGameState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

