#pragma once
#include "Game.h"
#include "Actor.h"
class GameObjects :public Actor
{
private:
	bool m_Triggered = false;
	SGD::Point m_TriggerRange;



public:
	GameObjects();
	~GameObjects();

	//Accessors
	SGD::Point GetTriggerRange(){ return m_TriggerRange; }
	bool GetIsTriggered(){ return m_Triggered; }
	//Mutators
	void SetTriggerRange(SGD::Point _p){ m_TriggerRange = _p; }
	void SetTriggered(bool _p){ m_Triggered = _p; }

	void	Update(float elapsedTime) = 0;
	void	Render(void) = 0;

	int		GetType(void)	const			override	{ return ENT_GAMEOBJECT; }
	SGD::Rectangle GetRect(void)	const = 0;
	void	HandleCollision(IEntity* pOther) = 0;

};

