#include "ParticleMass.h"

void ParticleMass::AddForce(SGD::Vector _force)
{
	sumForces +=  _force;
}

void ParticleMass::RemoveForce(SGD::Vector _force)
{
	sumForces -= _force;
}

void ParticleMass::Update(float dt)
{
	if (!isFixed)
	{
		SetAcceleration((sumForces));
		SGD::Vector savePosition = GetCurrPosition();
		SetCurrPosition(GetCurrPosition() + ((GetCurrPosition() - GetPrevPosition())*(1.0f - GetDampingCoEfficient())) + GetAcceleration()*dt*dt);
		SetPrevPosition(savePosition);
	}
	else
	{
		ResetAcceleration();
	}
}

void ParticleMass::ResetAcceleration()
{
	SetAcceleration(SGD::Vector{ 0, 0 });
}
