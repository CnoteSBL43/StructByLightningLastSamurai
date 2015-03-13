#pragma once
#include "IGameState.h"
class PauseState :
	public IGameState
{
private:
	PauseState() = default;
	~PauseState() = default;
	PauseState(const PauseState&) = delete;
	PauseState& operator= (const PauseState&) = delete;

public:
	static PauseState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

