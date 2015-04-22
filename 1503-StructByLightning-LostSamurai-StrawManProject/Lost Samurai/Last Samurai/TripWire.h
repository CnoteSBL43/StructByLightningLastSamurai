#pragma once
#include "GameObjects.h"


class TripWire: GameObjects
{
public:
	TripWire();
	~TripWire();

	void Update(float elapsedTime);
	void Render(void);

	SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	//void HandleEvent(const SGD::Event* pEvent);
};

