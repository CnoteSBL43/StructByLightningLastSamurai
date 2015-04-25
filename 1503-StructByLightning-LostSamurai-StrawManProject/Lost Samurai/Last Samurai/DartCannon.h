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
	int GetType() const { return ENT_DART_TRAP; }
protected:
	SGD::Rectangle rect;
	float m_Timer = 0.0;
};

