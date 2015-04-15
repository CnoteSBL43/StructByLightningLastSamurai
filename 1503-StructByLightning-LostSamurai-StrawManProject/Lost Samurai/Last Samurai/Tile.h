#pragma once
#include "IEntity.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include "Actor.h"
#include <string>
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
	std::string m_Trigger;
	int _Type = ENT_TILES;
public:
	SGD::Rectangle GetRect() const;
	void SetRect(SGD::Rectangle _Rect) { rect = _Rect; }
	void Render();
	Tile();
	~Tile();
	CollisonRect* CollisionRectangle;
	void HandleCollision(IEntity* pOther);
	int GetType(void)	const;
	void SetType(int _type) { _Type = _type; }
	void Update(float _elapsedTime);
	void SetString(std::string _string) { m_Trigger = _string; }
	std::string GetTrigger() { return m_Trigger; }
	// this is For Debug Mode;
	bool Debug = false;
};

