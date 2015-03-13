#pragma once
#include "IGameState.h"
class LoadGameState :
	public IGameState
{
private:
	LoadGameState() = default;
	~LoadGameState() = default;
	LoadGameState(const LoadGameState&) = delete;
	LoadGameState& operator= (const LoadGameState&) = delete;

public:
	static LoadGameState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

