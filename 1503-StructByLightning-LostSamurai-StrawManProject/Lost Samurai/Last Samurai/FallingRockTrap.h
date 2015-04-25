#pragma once
#include "Actor.h"
#include "AnimationSystem.h"
class FallingRockTrap : public Actor
{
private:
	AnimationTimestamp m_timestamp;
public:
	FallingRockTrap();
	~FallingRockTrap();
	void Render();
	void Update(float _elapsedtime);
	SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	int GetType()const { return ENT_FALLING_ROCK; }
	float m_Timer = 0;
};

