#pragma once
#include "Bullet.h"
#include "Cannon.h"
#include "AnimationTimestamp.h"
#include "DartCannon.h"
class Arrow : public Bullet
{
public:
	Arrow();
	~Arrow();
	void SetDartCannon(Actor* _Cannon);
	void Render();
	void Update(float elapsedTime);
	int	GetType(void) const;
	//SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	SGD::Rectangle GetRect() const;
private:
	AnimationTimestamp m_Timestamp;
	Actor* m_DartCannon;
	SGD::Rectangle rect;
	bool Debug = false;
	float m_timer = 30.0;
};

