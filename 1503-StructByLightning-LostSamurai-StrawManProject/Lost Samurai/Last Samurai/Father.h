#pragma once
#include "Player.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "AnimationTimestamp.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include "../SGD Wrappers/SGD_AudioManager.h"
#include <vector>
#include "Son.h"
class Father : public Player, public SGD::IListener

{
	Son* m_Son = nullptr;
public:
	Father();
	~Father();

	void	Update(float elapsedTime);
	void	Render(void);
	int		GetType(void)	const				{ return ENT_FATHER; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision(IEntity* pOther);
	SGD::HAudio m_RegenStamina = SGD::INVALID_HANDLE;

	AnimationTimestamp GetTimeStamp() { return m_Timestamp; }
	bool GetCurrCharacter(){ return isCurrentCharacter; }
	void SetCurrCharacter(bool _isCurrentCharacter){ isCurrentCharacter = _isCurrentCharacter; }
	int GetDirection(){ return direction; }

	void SetDirection(int _direction) { direction = _direction; }
	void HandleEvent(const SGD::Event* pEvent);
	bool GetCollisionRect(){ return collisionrect; }
	void SetCollisionRect(bool _collisionrect){ collisionrect = _collisionrect; }
	bool letLeft = true, letRight = true, cannotJump = false, upArrow = false;
	bool enemy = false;//to create enemy once
	//bool grounded = true;
	SGD::Color GetStaminaState() { return m_staminastate; }
	void SetStaminaState(SGD::Color _color) { m_staminastate = _color; }
	bool GetTargeted() { return Targeted; }
	void SetTargeted(bool _bool) { Targeted = _bool; }


private:
	SGD::HAudio m_FatherJump;
	SGD::HAudio FatherWalking;
	SGD::HAudio FatherLanding;
	AnimationTimestamp m_Timestamp;
	bool landing = false;
	int direction = 0;
	float frameswitch = 0.0f;
	//to change the scale for the father(direction)
	bool isCurrentCharacter = true; //to check if he is the current character. Starts as the father always 	
	bool Debug = false;
	bool collisionrect = false;//collision rectangle  fix ?
	float previousPosY;
	SGD::Color m_staminastate = { 255, 255, 255, 255 };
	bool isFlashing = false;
	bool  Landing = false;
	float FlashTimer = 0.0f;
	float FlashNow = 0.2f;
	bool Targeted = false;
	float timeinair = 0.0f;
	bool spawn = true;
	SGD::HAudio ClimbLadder;
	SGD::HAudio m_FatherJump;
	SGD::HAudio FatherWalking;
	SGD::HAudio FatherLanding;
	SGD::HAudio m_RegenStamina;
	SGD::HAudio PushBoxSound;
};

