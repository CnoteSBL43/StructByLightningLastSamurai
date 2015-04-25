#pragma once
#include "Actor.h"
#include "AnimationTimestamp.h"
class Door: public Actor
{
	AnimationTimestamp m_Timestamp;
public:
	Door();
	~Door();
	void Update(float _elspasedtime);
	void Render();
	int		GetType(void)	const;
	//SGD::Rectangle GetRect(void)	const;
	void HandleCollision(IEntity* pOther);
};

