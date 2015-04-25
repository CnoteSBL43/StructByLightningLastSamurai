#pragma once
#include "Actor.h"
#include "AnimationSystem.h"
class RollingBoulder :
	public Actor
{
private:
	AnimationTimestamp m_Timestamp;

public:
	RollingBoulder();
	~RollingBoulder();
	void Render();
	void Update(float _elapsedtime);
	void HandleCollision(IEntity* pOther);
	int GetType() const { return ENT_ROLLING_BOULDER; }
};

