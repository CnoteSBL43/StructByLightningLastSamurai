#pragma once
#include "Actor.h"
class DartCannon : public Actor
{
public:
	DartCannon();
	~DartCannon();
	void Render();


protected:
	SGD::Rectangle rect;
};

