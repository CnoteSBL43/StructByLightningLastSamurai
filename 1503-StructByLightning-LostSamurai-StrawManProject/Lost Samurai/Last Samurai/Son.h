#pragma once
#include "Player.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include <vector>
class Son :
	public Player
{
public:
	Son();
	~Son();


	void	Update(float elapsedTime);
	void	Render(void);
	int		GetType(void)	const				{ return ENT_SON; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision( IEntity* pOther);
	int GetDirection(){		return direction;}
	bool GetCurrCharacter(){ return isCurrentCharacter; }
	void SetCurrCharacter(bool _isCurrentCharacter){ isCurrentCharacter = _isCurrentCharacter; }
	bool GetFacing(){ return m_FacingtoRight; }
	void SetFacing(bool _facingright){ m_FacingtoRight = _facingright; }



private:
	struct Frame
	{
		SGD::Rectangle		rFrame;		// source rectangle
		SGD::Point			ptAnchor;	// relative position within source
	};
	std::vector<Frame> frames;
	void CreateFrames();

	int direction = 0;
	float frameswitch = 0.0f;
	bool m_FacingtoRight = true;//to change the scale for the Son(direction)
	bool isCurrentCharacter=false;
	bool lrArrow = false, upArrow = false; // using this so that when backpacked i move left or right the son falls down to ground //same reason for up
};

