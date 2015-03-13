#pragma once
#include "IGameState.h"
class SplashState :
	public IGameState
{
private:
	SplashState() = default;
	~SplashState() = default;
	SplashState(const SplashState&) = delete;
	SplashState& operator= (const SplashState&) = delete;

public:
	static SplashState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

