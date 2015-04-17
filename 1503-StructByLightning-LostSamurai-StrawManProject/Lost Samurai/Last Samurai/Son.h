#pragma once
#include "Player.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include <vector>
#include "AnimationSystem.h"
class Son :
	public Player, public SGD::IListener
{
public:
	Son();
	~Son();


	void	Update(float elapsedTime);
	void	Render(void);
	int		GetType(void)	const				{ return ENT_SON; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision(IEntity* pOther);
	int GetDirection(){ return direction; }
	bool GetCurrCharacter(){ return isCurrentCharacter; }
	void SetCurrCharacter(bool _isCurrentCharacter){ isCurrentCharacter = _isCurrentCharacter; }
	bool GetFacing(){ return m_FacingtoRight; }
	void SetFacing(bool _facingright){ m_FacingtoRight = _facingright; }
	bool letLeft = true, letRight = true, cannotJump = false, upArrow = false, lrArrow = false;//lrArrow so the player can get off the father
	bool GetCollisionRect(){ return collisionrect; }
	void SetCollisionRect(bool _collisionrect){ collisionrect = _collisionrect; }
	void HandleEvent(const SGD::Event* pEvent);
	AnimationTimestamp& GetTimeStamp() { return m_Timestamp; }
	SGD::Color GetStaminaState() { return m_staminastate; }
	void SetStaminaState(SGD::Color _color) { m_staminastate = _color; }

private:
	AnimationTimestamp m_Timestamp;
	int direction = 0;
	float frameswitch = 0.0f;
	bool m_FacingtoRight = true;//to change the scale for the Son(direction)
	bool isCurrentCharacter = false;
	float previousPosY;
	bool collisionrect = false;//collision rectangle  fix ?
	bool Debug = false;
	//bool grounded = true;
	SGD::Color m_staminastate = { 255, 255, 255, 255 };
	bool isFlashing = false;
	float FlashTimer = 0.0f;
	float FlashNow = 0.2f;
};

