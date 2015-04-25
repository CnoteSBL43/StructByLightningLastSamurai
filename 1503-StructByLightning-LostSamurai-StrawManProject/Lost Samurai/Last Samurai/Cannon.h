#pragma once
#include "Actor.h"
class Cannon : public Actor
{
public:
	Cannon();
	~Cannon();
	void Render();
	void Update(float _elapsedtime);
	SGD::Rectangle GetRect(void) const;
protected:
	SGD::Rectangle rect;
	float m_Timer = 0.0;
};

