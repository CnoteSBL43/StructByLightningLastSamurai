#pragma once
#include "IGameState.h"
class LoadState :
	public IGameState
{
private:
	LoadState() = default;
	~LoadState() = default;
	LoadState(const LoadState&) = delete;
	LoadState& operator= (const LoadState&) = delete;

public:
	static LoadState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

