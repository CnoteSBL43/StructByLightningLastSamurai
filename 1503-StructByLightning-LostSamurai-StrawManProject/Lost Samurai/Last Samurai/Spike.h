#pragma once
#include "Actor.h"
class Spike: public Actor
{
public:

	
	
	Spike();
	~Spike();
	void Render();
	//SGD::Rectangle GetRect() const;
	

protected:
SGD::Rectangle rect;
	bool Debug = false;
};

