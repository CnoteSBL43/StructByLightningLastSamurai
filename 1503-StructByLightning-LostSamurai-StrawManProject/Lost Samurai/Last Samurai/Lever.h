#pragma once
#include "GameObjects.h"
#include "AnimationSystem.h"
class Lever : public GameObjects
{
	int ID;
	AnimationTimestamp m_Timestamp;
public:
	Lever();
	~Lever();

	void Update(float elapsedTime);
	void Render(void);

	int	GetType(void) const	{ return ENT_LEVERS; }
	SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	void SetID(int _id){ ID = _id; }
	int GetID() const { return ID; }
};

