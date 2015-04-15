#pragma once
#include"Rope.h"



class Pulley
{
private: 
	Rope * r;
	SGD::Vector p1, p2, p3;
	int index;
public:
	Pulley();
	Pulley(int length, int numberOfPartciles, SGD::Vector location);
	~Pulley();
	void Update(float dt);
	void Render(float dt);
	void Pull();
	void Grab(SGD::Point _p);
	
	//Accessors
	SGD::Vector GetPoint1(){ return p1;  }
	SGD::Vector GetPoint2(){ return p2;  }
	SGD::Vector GetPoint3(){ return p3; }
	SGD::Rectangle GetRect() { return r->GetParticleAt(index)->GetRectPartcile(); }
	//Mutators
	void SetPoint1(SGD::Vector _p1){ p1 = _p1; }
	void SetPoint2(SGD::Vector _p2){ p2 = _p2; }
	void SetPoint3(SGD::Vector _p3){ p3 = _p3; }
	

};

