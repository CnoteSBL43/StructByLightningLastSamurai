#pragma once
#include "IGameState.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
class LoadGameState :
	public IGameState
{
private:
	LoadGameState() = default;
	~LoadGameState() = default;
	LoadGameState(const LoadGameState&) = delete;
	LoadGameState& operator= (const LoadGameState&) = delete;
	bool isLoading;
	float m_LoadTimer = 6.0f;
	float m_LoadingTime = 0.0f;
	SGD::HAudio LoadMusic;
public:
	static LoadGameState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);

};

