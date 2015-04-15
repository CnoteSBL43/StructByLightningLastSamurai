#pragma once
#include "Actor.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Utilities.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "../SGD Wrappers/SGD_IListener.h"

class Player :
	public Actor
{
public:
	Player();
	~Player();
	
	void	Update(float elapsedTime) = 0;
	void	Render(void) = 0;

	int		GetType(void)	const			override	{ return ENT_PLAYER; }
	SGD::Rectangle GetRect(void)	const = 0;
	void	HandleCollision(IEntity* pOther) = 0;
	bool GetBackPack(){ return m_BackPack; }
	void SetBackPack(bool _back){ m_BackPack = _back; }



	bool GetOnGround(){ return m_OnGround; }
	void SetOnGround(bool _onground){ m_OnGround = _onground; }

	float GetGravity(){ return gravity; }
	float GetJumpVelocity(){ return jumpVelocity; }
	void SetJumpVelocity(float _jumpVelocity){ jumpVelocity = _jumpVelocity; }
	bool GetFacing(){ return m_FacingtoRight; }
	void SetFacing(bool _facingright){ m_FacingtoRight = _facingright; }

private:
	int m_Stamina;
	float jumpVelocity = 256.0f, gravity = 4.9f;
	bool m_Hanging;
	bool m_BackPack = false;
	bool m_OnGround = true;
	unsigned int	m_unRefCount = 1;	// calling new gives the 'prime' reference
	bool m_FacingtoRight = true;//to change the scale for the father(direction)


};

