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

	bool GetCurrCharacter(){ return isCurrentCharacter; }
	void SetCurrCharacter(bool _isCurrentCharacter){ isCurrentCharacter = _isCurrentCharacter; }
	int GetDirection(){ return direction; }
	
	void SetDirection(int _direction) { direction = _direction; }
	void HandleEvent(const SGD::Event* pEvent);
	bool GetCollisionRect(){ return collisionrect; }
	void SetCollisionRect(bool _collisionrect){ collisionrect = _collisionrect; }

	bool letLeft = true, letRight = true, cannotJump = false, upArrow = false;
	bool enemy = false;//to create enemy once
	bool grounded = true;


private:
	AnimationTimestamp m_Timestamp;
	int direction = 0;
	float frameswitch = 0.0f;
	//to change the scale for the father(direction)
	bool isCurrentCharacter = true; //to check if he is the current character. Starts as the father always 	
	bool Debug = false;

	bool collisionrect = false;//collision rectangle  fix ?
	float previousPosY;
};

