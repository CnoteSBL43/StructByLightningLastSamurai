#pragma once
class IGameState
{
public:
	virtual void	Enter(void) = 0;
	virtual void	Exit(void) = 0;
	virtual bool	Update(float elapsedTime) = 0;
	virtual void	Render(float elapsedTime) = 0;
protected:
	IGameState() = default;
	~IGameState() = default;
};

