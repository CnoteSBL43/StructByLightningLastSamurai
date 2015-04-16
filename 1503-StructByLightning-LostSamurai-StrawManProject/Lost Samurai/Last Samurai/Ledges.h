#pragma once
#include "Actor.h"
class Ledges :
	public Actor
{
public:
	Ledges();
	~Ledges();

	void	Update(float elapsedTime) ;
	void	Render(void) ;

	int		GetType(void)	const			{ return ENT_LEDGE; }
	SGD::Rectangle GetRect(void)	const ;
	void	HandleCollision(IEntity* pOther);
};

