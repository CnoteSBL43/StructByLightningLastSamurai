#pragma once
#include "Player.h"
class Son :
	public Player
{
public:
	Son();
	~Son();

	void	Update(float elapsedTime);
	void	Render(void);
	int		GetType(void)	const				{ return ENT_SON; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision(const IEntity* pOther);
};

