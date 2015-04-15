#pragma once
#include "ParticleMass.h"
#include "../SGD Wrappers/SGD_Geometry.h"
class Link
{
private:
	float stiffness, damping, LinkLengthAtRest;
public:
	Link();
	Link(ParticleMass* _particle1, ParticleMass* _particle2);
	~Link();
	void SolveDistanceConstraint(int _numOfIterations);
	ParticleMass* particle1;
	ParticleMass* particle2;

	//Accessors
	float GetStiffness(){ return stiffness; }
	float GetDamping(){ return damping; }
	float GetLinkLengthAtRest(){ return LinkLengthAtRest; }
	//Mutators
	void SetStiffness(float _stiff){  stiffness = _stiff; }
	void SetDamping(float _damping){  damping = _damping; }
	void SetLinkLengthAtRest(float _length){ LinkLengthAtRest = _length; }
};

