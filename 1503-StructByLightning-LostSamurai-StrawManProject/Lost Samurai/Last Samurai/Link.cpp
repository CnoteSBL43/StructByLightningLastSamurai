#include "Link.h"
#include <cmath>

Link::Link()
{
	particle1 = new ParticleMass;
	particle2 = new ParticleMass;
}

Link::Link(ParticleMass* _particle1, ParticleMass* _particle2)
{
	this->particle1 = _particle1;
	this->particle2 = _particle2;
	SGD::Vector v = particle1->GetCurrPosition() - particle2->GetCurrPosition();
	this->LinkLengthAtRest = v.ComputeLength();
}

Link::~Link()
{
}

void Link::SolveDistanceConstraint(int _numOfIterations)
{
	int N = _numOfIterations;
	float d = GetLinkLengthAtRest();
	SGD::Vector x1, x2, x;
	x1 = particle1->GetCurrPosition();
	x2 = particle2->GetCurrPosition();
	x = x1 - x2;
	float distance = x.ComputeLength();
	SetStiffness(1.0f - pow(1.0f-GetStiffness(), 1.0f / (float)N));
	float w1, w2;
	w1 = particle1->GetMassInv();
	w2 = particle2->GetMassInv();
	x = x.ComputeNormalized();
	SGD::Vector dx1, dx2;
	//dx1 =-x*(w1*GetStiffness() / (w1 + w2))*(distance -d );
	//dx2 = x*(w2*GetStiffness() / (w1 + w2))*(distance - d);
	dx1 =-x*(GetStiffness()*0.5f)*(distance -d );
	dx2 = x*(GetStiffness()*0.5f)*(distance - d);

	if (!particle1->GetFixed() && !particle2->GetFixed())
	{
		particle1->SetCurrPosition(x1 + dx1);
		particle2->SetCurrPosition(x2 + dx2);
	}
	if (particle1->GetFixed())
	{
		particle2->SetCurrPosition(x2 + dx2);
		particle1->SetCurrPosition(x1);
	}
	if (particle2->GetFixed())
	{
		particle1->SetCurrPosition(x1 + dx1);
		particle2->SetCurrPosition(x2);
	}
}