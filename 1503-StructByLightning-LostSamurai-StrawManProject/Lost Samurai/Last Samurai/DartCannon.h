#pragma once
#include "Actor.h"
class DartCannon : public Actor
{
public:
	DartCannon();
	~DartCannon();
	void Render();
	void Update(float _elapsedtime);
	SGD::Rectangle GetRect(void) const;
protected:
	SGD::Rectangle rect;
	float m_Timer = 0.0;
};

