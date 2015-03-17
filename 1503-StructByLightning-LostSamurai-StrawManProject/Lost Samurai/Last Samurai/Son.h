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
	void	HandleCollision(const IEntity* pOther);
	int GetDirection(){		return direction;}
	bool GetCurrCharacter(){ return isCurrentCharacter; }
	void SetCurrCharacter(bool _isCurrentCharacter){ isCurrentCharacter = _isCurrentCharacter; }

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


};

