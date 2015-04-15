#pragma once
#include "Actor.h"
class Spike: public Actor
{
public:

	
	
	Spike();
	~Spike();
	
	//SGD::Rectangle GetRect() const;
	void Render();

protected:
SGD::Rectangle rect;
	bool Debug = false;
};

