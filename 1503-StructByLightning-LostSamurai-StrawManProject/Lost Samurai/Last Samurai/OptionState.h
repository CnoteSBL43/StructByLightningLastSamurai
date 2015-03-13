#pragma once
#include "IGameState.h"
class OptionState :
	public IGameState
{
private:
	OptionState() = default;
	~OptionState() = default;
	OptionState(const OptionState&) = delete;
	OptionState& operator= (const OptionState&) = delete;

public:
	static OptionState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

