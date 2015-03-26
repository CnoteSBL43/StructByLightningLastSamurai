#pragma once
#include "IEntity.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include "Actor.h"
class Tile :public Actor
{

	struct CollisonRect
	{
		int PositionX;
		int PositionY;
		int SizeWidth;
		int SizeHeight;

	};
	SGD::Rectangle rect;
public:
	SGD::Rectangle GetRect() const;
	void SetRect(SGD::Rectangle _Rect) { rect = _Rect; }
	void Render();
	Tile();
	~Tile();
	CollisonRect* CollisionRectangle;
	void HandleCollision(IEntity* pOther);
	int GetType(void)	const;
};

