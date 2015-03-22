#pragma once
#include "Player.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include <vector>
class Father :
	public Player
{
public:
	Father();
	~Father();

	void	Update(float elapsedTime)	;
	void	Render(void)				;
	int		GetType(void)	const				{ return ENT_FATHER; }
	SGD::Rectangle GetRect(void)	const			;
	void	HandleCollision( IEntity* pOther)	;

	//void SetCamVector(SGD::Vector _vec){ pos = _vec; }
	//SGD::Vector GetCameraVector(void)const { return pos; }

	bool GetCurrCharacter(){ return isCurrentCharacter; }
	void SetCurrCharacter(bool _isCurrentCharacter){ isCurrentCharacter = _isCurrentCharacter; }
	int GetDirection(){	return direction;	}
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
	float jumpVelocity = 256.0f, gravity = 0.8f,frameswitch = 0.0f;
	bool m_FacingtoRight = true;//to change the scale for the father(direction)
	bool isCurrentCharacter = true; //to check if he is the current character. Starts as the father always 	
};

