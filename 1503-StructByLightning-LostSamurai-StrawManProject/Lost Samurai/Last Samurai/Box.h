#pragma once
#include "GameplayState.h"
#include "GameObjects.h"
class Box : public GameObjects
{
private:
	bool isHeavy;
public:
	Box();
	~Box();
	void CalculateVelocity(SGD::Vector _v);

	void	Update(float elapsedTime)	;
	void	Render(void)				;

	int		GetType(void)	const				{ return Actor::ENT_BOX; }
	SGD::Rectangle GetRect(void)	const		;
	void	HandleCollision(IEntity* pOther)	;

};

