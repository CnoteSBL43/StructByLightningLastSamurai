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
	//SGD::HAudio m_Movement = SGD::INVALID_HANDLE;
public:
	static PauseState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

