#pragma once
#include "Player.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "AnimationTimestamp.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include <vector>
class Father : public Player, public SGD::IListener

{
public:
	Father();
	~Father();

	void	Update(float elapsedTime);
	void	Render(void);
	int		GetType(void)	const				{ return ENT_FATHER; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision(IEntity* pOther);


	AnimationTimestamp GetTimeStamp() { return m_Timestamp; }
	bool GetHanging(){ return isHanging; }
	bool GetCurrCharacter(){ return isCurrentCharacter; }
	void SetCurrCharacter(bool _isCurrentCharacter){ isCurrentCharacter = _isCurrentCharacter; }
	int GetDirection(){ return direction; }

	void SetDirection(int _direction) { direction = _direction; }
	void HandleEvent(const SGD::Event* pEvent);
	bool GetCollisionRect(){ return collisionrect; }
	void SetCollisionRect(bool _collisionrect){ collisionrect = _collisionrect; }
	void SetHanging(bool _collisionrect){ isHanging = _collisionrect; }

	bool letLeft = true, letRight = true, cannotJump = false, upArrow = false;
	bool enemy = false;//to create enemy once
	//bool grounded = true;
	SGD::Color GetStaminaState() { return m_staminastate; }
	void SetStaminaState(SGD::Color _color) { m_staminastate = _color; }
	bool GetTargeted() { return Targeted; }
	void SetTargeted(bool _bool) { Targeted = _bool; }


private:
	AnimationTimestamp m_Timestamp;
	int direction = 0;
	float frameswitch = 0.0f;
	//to change the scale for the father(direction)
	bool isCurrentCharacter = true; //to check if he is the current character. Starts as the father always 	
	bool Debug = false;
	bool isHanging = false;
	bool collisionrect = false;//collision rectangle  fix ?
	float previousPosY;
	SGD::Color m_staminastate = { 255, 255, 255, 255 };
	bool isFlashing = false;
	float FlashTimer = 0.0f;
	float FlashNow = 0.2f;
	bool Targeted = false;
	float timeinair = 0.0f;
	bool spawn = true;
};

