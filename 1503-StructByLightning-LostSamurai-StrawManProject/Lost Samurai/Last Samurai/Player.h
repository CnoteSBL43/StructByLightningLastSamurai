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

	SGD::Point GetCheckPoint() const{ return checkPoint; }
	void SetCheckPoint(SGD::Point _checkPoint) { checkPoint = _checkPoint; }

	bool GetjumpOffLedge()const{ return jumpOffLedge; }
	void SetjumpOffLedge(bool _onground){ jumpOffLedge = _onground; }
	bool GetonLadder()const{ return onLadder; }
	void SetonLadder(bool _ladder){ onLadder = _ladder; }
	bool GetOnGround(){ return m_OnGround; }
	void SetOnGround(bool _onground){ m_OnGround = _onground; }
	bool GetHanging(){ return isHanging; }
	void SetHanging(bool _hang){ isHanging = _hang; }
	float GetGravity(){ return gravity; }
	bool GetFacing()const{ return m_FacingtoRight; }
	void SetFacing(bool _facingright){ m_FacingtoRight = _facingright; }
	float GetStamina() { return m_Stamina; }
	void SetStamina(float _stamina) { m_Stamina = _stamina; }
private:
	float m_Stamina;
	float gravity = 4.9f;
	bool m_BackPack = false;
	bool m_OnGround = true;
	unsigned int	m_unRefCount = 1;	// calling new gives the 'prime' reference
	bool m_FacingtoRight = true;//to change the scale for the father(direction)
	SGD::Point checkPoint;
	bool isHanging = false;
	bool jumpOffLedge = false;//bool to let the father jump off the ledge
	bool onLadder = false;
};

