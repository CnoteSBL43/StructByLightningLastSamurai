#pragma once
#include "GameObjects.h"

class Lever : public GameObjects
{
	bool playerNear = false;

public:
	Lever();
	~Lever();

	void Update(float elapsedTime);
	void Render(void);

	int	GetType(void) const	{ return ENT_LEVERS; }
	SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	bool GetPlayerNear(){ return playerNear; }
};

