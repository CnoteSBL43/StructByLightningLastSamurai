#pragma once
#include "GameObjects.h"


class Ladder : public GameObjects
{
public:
	Ladder();
	~Ladder();


	void Update(float elapsedTime);
	void Render(void);
		 
	int	GetType(void) const	{ return ENT_LADDER; }
	SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
};

