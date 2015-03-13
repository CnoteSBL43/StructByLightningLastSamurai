#pragma once
#include "IGameState.h"
class InstructionsState :
	public IGameState
{
private:
	InstructionsState() = default;
	~InstructionsState() = default;
	InstructionsState(const InstructionsState&) = delete;
	InstructionsState& operator= (const InstructionsState&) = delete;

public:
	static InstructionsState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

