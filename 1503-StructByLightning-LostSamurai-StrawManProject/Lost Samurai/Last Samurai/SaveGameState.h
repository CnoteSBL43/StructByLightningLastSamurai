#pragma once
#include "IGameState.h"
class SaveGameState :
	public IGameState
{
private:
	SaveGameState() = default;
	~SaveGameState() = default;
	SaveGameState(const SaveGameState&) = delete;
	SaveGameState& operator= (const SaveGameState&) = delete;

public:
	static SaveGameState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
};

