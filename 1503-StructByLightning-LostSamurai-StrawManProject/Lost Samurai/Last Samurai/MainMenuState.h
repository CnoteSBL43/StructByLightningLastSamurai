#pragma once
#include "IGameState.h"
class MainMenuState :
	public IGameState
{
private:
	MainMenuState() = default;
	~MainMenuState() = default;
	MainMenuState(const MainMenuState&) = delete;
	MainMenuState& operator= (const MainMenuState&) = delete;

public:
	static MainMenuState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

