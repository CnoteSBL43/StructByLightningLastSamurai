#pragma once
#include "Actor.h"
#include "Father.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include "AnimationSystem.h"

class BowMan :public Actor, public SGD::IListener
{
private:
	enum Status { Alert, Wander, Attack, };
	Status m_Stats = Wander;
	Player* m_Target = nullptr;
	SGD::Point m_Wander = { 0, 0 };
	AnimationTimestamp m_Timestamp;
	bool m_facingRight = true;
	bool Debug = false;
	bool isAlerted = false;
	float AlertTimer = 0.0f;
	float ChangeFaceTimer = 0.0f;
	SGD::Vector EnemyDistance = {};
	float m_Timer = 0.0f;
	SGD::HTexture m_AlertedImage = SGD::INVALID_HANDLE;

public:
	bool GetAlerted() const { return isAlerted; }
	bool Facing() const { return m_facingRight; }
	SGD::Rectangle GetRect() const;
	BowMan();
	~BowMan();
	Status GetStatus() const { return m_Stats; }
	void SetStatus(Status _state) { m_Stats = _state; }
	void Render(void);
	void Update(float _elapsedtime);
	int	 GetType(void)	const;
	void HandleEvent(const SGD::Event* pEvent);
	//SGD::Rectangle GetRect(void) const;
	void HandleCollision(IEntity* pOther);
	void SetTarget(Player* _target) { m_Target = _target; }
	Player* GetEnemyTarget() { return m_Target; }
	void SetDestination(float _dest){ destination = _dest; }
	float GetDestination(){ return destination; }
	bool toRight = true;
	bool toLeft = false;
	float destination = 0.0f;



};

