#pragma once
#include "Player.h"
#include <vector>
class Swordsman :
	public Player
{
public:
	Swordsman();
	~Swordsman();


	void	Update(float elapsedTime);
	void	Render(void);
	//int		GetType(void)	const				{ return ENT_SWORDSMAN; }
	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision( IEntity* pOther);
	void SetDestination(float _dest){ destination = _dest; }
	float GetDestination(){		return destination;	}
	bool toRight = true;
	bool toLeft = false;
	


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
	float destination ;
	bool m_facingRight = true;

};

