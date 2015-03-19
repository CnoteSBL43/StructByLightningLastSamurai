#pragma once
#include "IGameState.h"
#include "../SGD Wrappers/SGD_Geometry.h"
class TileSystem;
class GameplayState :
	public IGameState
{
private:
	GameplayState() = default;
	~GameplayState() = default;
	GameplayState(const GameplayState&) = delete;
	GameplayState& operator= (const GameplayState&) = delete;
	TileSystem* Load;
SGD::Point m_start = { 0, 0 };

public:
	static GameplayState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

