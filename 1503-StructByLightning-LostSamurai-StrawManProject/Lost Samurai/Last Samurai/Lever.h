#pragma once
#include "GameObjects.h"
#include "AnimationSystem.h"
class Lever : public GameObjects
{
private:
	bool playerNear = false;
	AnimationTimestamp m_Timestamp;
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

