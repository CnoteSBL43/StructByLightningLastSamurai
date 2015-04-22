#pragma once
#include "Actor.h"
#include "AnimationTimestamp.h"
#include "Door.h"
#include "../SGD Wrappers/SGD_IListener.h"
class AutoLockingDoor :public Door, public SGD::IListener
{
	AnimationTimestamp m_Timestamp;
	bool playerNear = false;
	int m_ID = 0;
public:
	AutoLockingDoor();
	~AutoLockingDoor();
	void Update(float _elspasedtime);
	void Render();
	int		GetType(void)	const;
	SGD::Rectangle GetRect(void)	const;
	void HandleCollision(IEntity* pOther);
	bool isOpen = false;
	void HandleEvent(const SGD::Event* pEvent);
	bool GetOpen() { return isOpen; }
	void SetOpen(bool _bool) { isOpen = _bool; }
	bool GetPlayerNear(){ return playerNear; }
	void SetID(int _ID) { m_ID = _ID; }
	int GetID() const { return m_ID; };
};

