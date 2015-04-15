#pragma once
#include "Actor.h"
#include "Cannon.h"
#include "AnimationTimestamp.h"
#include "DartCannon.h"
class Arrow : public Actor
{
public:
	Arrow();
	~Arrow();
	void SetDartCannon(DartCannon* _Cannon);
	void Render();
	void Update(float elapsedTime);
	int	GetType(void) const;
	//SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	SGD::Rectangle GetRect() const;
private:
	AnimationTimestamp m_Timestamp;
	DartCannon* m_DartCannon;
	SGD::Rectangle rect;
	bool Debug = false;
};

