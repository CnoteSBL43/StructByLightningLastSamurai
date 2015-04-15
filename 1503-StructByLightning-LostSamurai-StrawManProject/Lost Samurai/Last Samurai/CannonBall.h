#pragma once
#include "Actor.h"
#include "Cannon.h"
#include "AnimationTimestamp.h"
class CannonBall: public Actor
{
public:
	CannonBall();
	~CannonBall();
	
	void SetCannon(Cannon* _Cannon);
	void Render();
	void Update(float elapsedTime);
	int	GetType(void) const;
	//SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	SGD::Rectangle GetRect() const;
private:
	AnimationTimestamp m_Timestamp;
	Cannon* m_Cannon;
	SGD::Rectangle rect;
	bool Debug = false;
};

