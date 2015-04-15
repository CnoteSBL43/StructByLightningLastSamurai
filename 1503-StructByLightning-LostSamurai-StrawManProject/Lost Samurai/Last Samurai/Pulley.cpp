#include "Pulley.h"
#include"GameplayState.h"

Pulley::Pulley()
{
}

Pulley::Pulley(int length, int numberOfPartciles, SGD::Vector location)
{
	index = 0;
	r = new Rope(length, numberOfPartciles, location);
	SetPoint1({ r->GetParticleAt(10)->GetCurrPosition().x-50.0f, r->GetParticleAt(10)->GetCurrPosition().y -100.0f });
	SetPoint2({ r->GetParticleAt(10)->GetCurrPosition().x, r->GetParticleAt(10)->GetCurrPosition().y - 200.0f });
	SetPoint3({ r->GetParticleAt(10)->GetCurrPosition().x+50.0f, r->GetParticleAt(10)->GetCurrPosition().y - 180.0f });
	
	r->GetParticleAt(9)->SetFixed(true);
	r->GetParticleAt(10)->SetFixed(true);
	r->GetParticleAt(11)->SetFixed(true);
	r->GetParticleAt(9)->SetCurrPosition(GetPoint1());
	r->GetParticleAt(10)->SetCurrPosition(GetPoint2());
	r->GetParticleAt(11)->SetCurrPosition(GetPoint3());
	r->GetParticleAt(19)->SetMass(800.0f);
	r->GetParticleAt(0)->SetCurrPosition({ r->GetParticleAt(9)->GetCurrPosition().x-20.0f, r->GetParticleAt(9)->GetCurrPosition().y + 150.0f });
	r->GetParticleAt(19)->SetCurrPosition({ r->GetParticleAt(11)->GetCurrPosition().x +150.0f, r->GetParticleAt(11)->GetCurrPosition().y + 150.0f });
}

Pulley::~Pulley()
{
}

void Pulley::Grab(SGD::Point _p)
{
	if (GameplayState::GetInstance()->GetMovementOff())
	{
		r->GetParticleAt(0)->SetCurrPosition({ _p.x, _p.y - 16.0f });
		r->GetParticleAt(0)->SetFixed(true);
	}
	else
	{
		r->GetParticleAt(index)->SetFixed(false);
		for (int i = r->GetNumberOfParticles() - 1; i >= 0; i--)
		{
			if (r->GetParticleAt(i)->GetFixed() && i > 11)
			{
				r->GetParticleAt(0)->SetFixed(false);
				if (i == r->GetNumberOfParticles() - 1)
				{
					r->GetParticleAt(0)->SetCurrPosition({ _p.x, _p.y - 16.0f });
					break;
				}
				r->GetParticleAt(0)->SetCurrPosition({ _p.x, _p.y - 16.0f });
				r->GetParticleAt(i - 3)->SetCurrPosition({ r->GetParticleAt(i - 2)->GetCurrPosition().x, r->GetParticleAt(i - 2)->GetCurrPosition().y });
				r->GetParticleAt(i - 2)->SetCurrPosition({ r->GetParticleAt(i - 1)->GetCurrPosition().x, r->GetParticleAt(i - 1)->GetCurrPosition().y });
				r->GetParticleAt(i - 1)->SetCurrPosition({ r->GetParticleAt(i)->GetCurrPosition().x, r->GetParticleAt(i)->GetCurrPosition().y });
				r->GetParticleAt(i - 3)->SetFixed(true);
				r->GetParticleAt(i)->SetFixed(false);
				if (i == 12)
				{r->GetParticleAt(19)->SetCurrPosition({ GetPoint3().x, GetPoint3().y + 150.0f });
				r->GetParticleAt(19)->SetFixed(true);
			}
			}
		}
		
		index = 0;
	}

}

void Pulley::Pull()
{																																																																											
	r->GetParticleAt(19)->SetFixed(false);
	/*for (int i = 11; i < 20; i++)
	{
		GameplayState::GetInstance()->stiffnessValue = 0.1f;
		r->GetParticleAt(i)->SetGravity({ 0.0f, 9.0f });
		r->GetParticleAt(i)->SetDampingCoEfficient(0.8f);
		r->GetParticleAt(i)->SetSumForces(SGD::Vector{ 0.0f, 0.0f });
		r->GetParticleAt(i)->SetWeight(r->GetParticleAt(i)->GetGravity()*r->GetParticleAt(i)->GetMass());
		r->GetParticleAt(i)->AddForce(r->GetParticleAt(i)->GetWeight());
	}*/
	for (int i = 0; i < r->GetNumberOfParticles(); i++)
	{
		if (i < 7)
		{
			if (r->GetParticleAt(i)->GetFixed())
			{
				r->GetParticleAt(i + 1)->SetCurrPosition({ r->GetParticleAt(i)->GetCurrPosition().x, r->GetParticleAt(i)->GetCurrPosition().y });
				r->GetParticleAt(i + 1)->SetFixed(true);
				r->GetParticleAt(i)->SetFixed(false);
				index = i + 1;
				break;
			}
		}
	}
	for (int j = index+1; j < r->GetNumberOfParticles(); j++)
	{
		if (j < 16)
		{
			if (r->GetParticleAt(j)->GetFixed())
			{
				r->GetParticleAt(j + 3)->SetCurrPosition({ r->GetParticleAt(j + 2)->GetCurrPosition().x, r->GetParticleAt(j + 2)->GetCurrPosition().y });
				r->GetParticleAt(j + 2)->SetCurrPosition({ r->GetParticleAt(j + 1)->GetCurrPosition().x, r->GetParticleAt(j + 1)->GetCurrPosition().y });
				r->GetParticleAt(j + 1)->SetCurrPosition({ r->GetParticleAt(j)->GetCurrPosition().x, r->GetParticleAt(j)->GetCurrPosition().y });
				r->GetParticleAt(j + 3)->SetFixed(true);
				r->GetParticleAt(j + 2)->SetFixed(true);
				r->GetParticleAt(j + 1)->SetFixed(true);
				r->GetParticleAt(j)->SetFixed(false);
				break;
			}
		}
	}
	/*for (int i = 1; i < r->GetNumberOfParticles(); i++)
	{
		bool ok = false;
		if (r->GetParticleAt(i)->GetFixed())
		{
			if (i < 19)
			{
				if (r->GetParticleAt(i + 1)->GetFixed() == false)
				{
					r->GetParticleAt(i + 1)->SetFixed(true);
					r->GetParticleAt(i + 1)->SetCurrPosition({ r->GetParticleAt(i)->GetCurrPosition().x, r->GetParticleAt(i)->GetCurrPosition().y });
					r->GetParticleAt(i)->SetFixed(false);
					ok = true;
				}
			}
		}
		if (ok)
			break;
	}*/
	
}

void Pulley::Update(float dt)
{
	r->Update(dt);
}

void Pulley::Render(float dt)
{
	r->Render(dt);
}