#pragma once
#include "Player.h"
class Swordsman :
	public Player
{
public:
	Swordsman();
	~Swordsman();


	void	Update(float elapsedTime);
	void	Render(void);
	//int		GetType(void)	const				{ return ENT_SWORDSMAN; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision(const IEntity* pOther);
};

