#pragma once
#include "IGameState.h"
class GameModeSelectState :
	public IGameState
{
private:
	GameModeSelectState() = default;
	~GameModeSelectState() = default;
	GameModeSelectState(const GameModeSelectState&) = delete;
	GameModeSelectState& operator= (const GameModeSelectState&) = delete;

public:
	static GameModeSelectState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

