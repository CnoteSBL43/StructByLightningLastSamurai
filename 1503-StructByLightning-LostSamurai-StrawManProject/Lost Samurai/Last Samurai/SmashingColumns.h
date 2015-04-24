#pragma once
#include "Actor.h"
#include "AnimationSystem.h"
class SmashingColumns : public Actor
{

private:
	bool isActive = true;
	SGD::Point m_currentpos;// = { m_ptPosition.x, 118 };
	SGD::Point bottom;// = { m_ptPosition.x, m_ptPosition.y + (150.0f) };
	AnimationTimestamp m_timestamp;
public:
	SmashingColumns();
	~SmashingColumns();
	int GetType()const { return Actor::ENT_SMASHING_COLUMNS; }
	void Render();
	void Update(float _elapsedtime);
	SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
protected:
	SGD::Rectangle rect;

	float m_Timer = 0.0;
};

