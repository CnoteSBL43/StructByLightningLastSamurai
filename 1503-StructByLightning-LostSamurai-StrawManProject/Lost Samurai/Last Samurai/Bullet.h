#pragma once
#include "Actor.h"
class Bullet : public Actor
{
public:
	Bullet();
	~Bullet();
	void Render(){}
	void Update(float _elapsedTime) {}
	int GetType()const { return Actor::ENT_BASE; }
	void HandleCollisiont(IEntity* pOther);
	SGD::Rectangle GetRect() {}
};

