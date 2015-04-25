#pragma once
#include "Actor.h"
class FinalDoor :
	public Actor
{
public:
	FinalDoor();
	~FinalDoor();
	void	Update(float elapsedTime);
	void	Render(void);
	int		GetType(void)	const				{ return ENT_FINALDOOR; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision(IEntity* pOther);
};

