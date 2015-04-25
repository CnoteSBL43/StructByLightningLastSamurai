#pragma once
#include "Actor.h"
#include "AnimationSystem.h"
class FallingRock :
	public Actor
{
private:
	AnimationTimestamp m_Timestamp;

	Actor* Owner = nullptr;
public:
	FallingRock();
	~FallingRock();
	void SetOwner(Actor* _actor) { Owner = _actor; }
	void Render();
	void Update(float _elapsedtime);
	void HandleCollision(IEntity* pOther);
	int GetType() const { return ENT_FALLING_ROCK; }
};

