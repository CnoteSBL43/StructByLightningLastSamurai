#pragma once
#include "../SGD Wrappers/SGD_Geometry.h"
class ParticleMass
{
private:

	float mass, massInv, speed, dampingCoEfficient;
	SGD::Vector currPosition;
	SGD::Vector prevPosition;
	SGD::Vector acceleration;
	SGD::Vector sumForces;
	SGD::Vector forces;
	SGD::Vector weight;
	SGD::Vector gravity;
	SGD::Rectangle rect;
	

	bool isFixed;

public:
	
	void AddForce(SGD::Vector _force);
	void RemoveForce(SGD::Vector _force);
	void ResetAcceleration();
	void Update(float dt);

	//Accessors
	float GetMass(){ return mass; }
	float GetMassInv(){ return massInv; }
	float GetSpeed(){ return speed; }
	float GetDampingCoEfficient(){ return dampingCoEfficient; }
	SGD::Vector GetCurrPosition(){ return currPosition; }
	SGD::Vector GetPrevPosition(){ return prevPosition; }
	SGD::Vector GetAcceleration(){ return acceleration; }
	SGD::Vector GetSumForces(){ return sumForces; }
	SGD::Vector GetForces(){ return forces; }
	SGD::Vector GetWeight(){ return weight; }
	SGD::Vector GetGravity(){ return gravity; }
	SGD::Rectangle GetRectPartcile(){ return rect; }
	bool GetFixed(){ return isFixed; }


	//Mutators
	void SetMass(float _mass){ mass = _mass; }
	void SetMassInv(float _massInv){ massInv = _massInv; }
	void SetGravity(SGD::Vector g){ gravity = g; }
	void SetWeight(SGD::Vector w){ weight = w; }
	void SetCurrPosition(SGD::Vector _pos){ currPosition = _pos; }
	void SetPrevPosition(SGD::Vector _pos){ prevPosition = _pos; }
	void SetAcceleration(SGD::Vector _acc){ acceleration = _acc; }
	void SetSumForces(SGD::Vector _sumForce){ sumForces = _sumForce; }
	void SetDampingCoEfficient(float _dec){ dampingCoEfficient = _dec; }
	void SetFixed(bool _fixed){ isFixed = _fixed; }
	void SetRectangle(SGD::Rectangle _r){ rect = _r; }
};