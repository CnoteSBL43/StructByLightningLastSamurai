#pragma once
#include "Actor.h"
#include <vector>
#include "AnimationSystem.h"
class Swordsman :
	public Actor
{
public:
	Swordsman();
	~Swordsman();


	void	Update(float elapsedTime);
	void	Render(void);
	int		GetType(void)	const				{ return ENT_SWORDSMAN; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision( IEntity* pOther);
	void SetDestination(float _dest){ destination = _dest; }
	float GetDestination(){		return destination;	}
	bool toRight = true;
	bool toLeft = false;
	
	void SetTarget(Actor * _target){ target = _target; }
	Actor * GetTarget(){ return target; }

private:
	int direction = 0;
	float frameswitch = 0.0f;
	float destination ;
	bool m_facingRight = true;
	Actor* target = nullptr;
	AnimationTimestamp m_Timestamp;
	bool Debug = false;
};

