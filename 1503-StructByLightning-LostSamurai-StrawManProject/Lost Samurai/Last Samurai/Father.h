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

	void BackPack() ;

	void	Update(float elapsedTime)	;
	void	Render(void)				;
	int		GetType(void)	const				{ return ENT_FATHER; }
	SGD::Rectangle GetRect(void)	const			;
	void	HandleCollision(const IEntity* pOther)	;

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

	int GetDirection(){
		return direction;
	}

};

