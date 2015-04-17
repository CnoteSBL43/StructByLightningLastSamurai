#include "Rope.h"
#include "Game.h"
#include "GameplayState.h"
Rope::Rope()
{
}


Rope::~Rope()
{
	
}

Rope::Rope(int length, int _numberOfParticles, SGD::Vector location)
{
	SetParticleLenght(length);
	SetNumberOfParticles(_numberOfParticles);
	SetNumberOfLinks(_numberOfParticles - 1);
	particles.resize(_numberOfParticles);
	links.resize(GetNumberOfLinks());
	
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		float x = i*((float)length / (float)_numberOfParticles-1 ) ;
		particles[i].SetFixed(false);
		particles[i].SetMass(10.0f);
		particles[i].SetDampingCoEfficient(0.9f);
		particles[i].SetMassInv(1.0f / particles[i].GetMass());
		particles[i].SetGravity(SGD::Vector{ 0.0f, 200.0f});
		particles[i].SetSumForces(SGD::Vector{ 0.0f, 0.0f });
		particles[i].SetWeight(particles[i].GetGravity()*particles[i].GetMass());
		particles[i].AddForce(particles[i].GetWeight());
		particles[i].SetAcceleration(SGD::Vector{ 0.0, 0.0f });
		particles[i].SetCurrPosition(SGD::Vector{ x, 0.0f }+location);
		particles[i].SetPrevPosition(particles[i].GetCurrPosition());
	}

	//particles[0].SetFixed(true);
	particles[links.size()].SetFixed(true);
	this->topAnchor = GetParticleAt(0)->GetCurrPosition();
	this->bottomAnchor = GetParticleAt(links.size())->GetCurrPosition();
	for (unsigned int i = 0; i < links.size(); i++)
	{
		if (i < (unsigned int)GetNumberOfParticles() - 1)
		{
			//CreateLink(&particles[i], &particles[i + 1]);
			CreateLink(GetParticleAt(i), GetParticleAt(i + 1));
		}
	}
}

ParticleMass* Rope::GetParticleAt(int x)
{
	return &particles[x];
}

Link* Rope::GetLink(int x)
{
	return &links[x - 1];
}
void Rope::CreateLink(ParticleMass* particle1, ParticleMass* particle2)
{
	links.push_back(Link(particle1, particle2));
}

void Rope::Update(float dt)
{
	std::vector<Link>::iterator ropeLink;
	std::vector<ParticleMass>::iterator ropeParticle;
	const int num_Of_Iterations = 15;

	for (ropeParticle = particles.begin(); ropeParticle != particles.end(); ropeParticle++)
	{
		ropeParticle->Update(dt);
	}
	for (int i = 0; i < num_Of_Iterations; i++)
	{
		for (ropeLink = links.begin(); ropeLink != links.end(); ropeLink++)
		{
			ropeLink->SetStiffness(GameplayState::GetInstance()->stiffnessValue);
			ropeLink->SolveDistanceConstraint(num_Of_Iterations);
		}
	}
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		SGD::Rectangle rect;
		if (i == GetNumberOfParticles()-1)
			 rect = { SGD::Point(particles[i].GetCurrPosition().x, particles[i].GetCurrPosition().y), SGD::Size(96.0f, 12.0f) };
		else
			 rect = { SGD::Point(particles[i].GetCurrPosition().x, particles[i].GetCurrPosition().y), SGD::Size(10.0f, 10.0f) };
		particles[i].SetRectangle(rect);
	}
}

void Rope::Render(float dt)
{
	//Update(dt);
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		/*float x = particles[i].GetCurrPosition().x;
		float y = particles[i].GetCurrPosition().y;*/
		SGD::Rectangle rect;

		if (i == particles.size() - 1)
		{
			rect = { SGD::Point{ particles[i].GetCurrPosition().x - Game::GetInstance()->GetCameraPosition().x, particles[i].GetCurrPosition().y - Game::GetInstance()->GetCameraPosition().y }, SGD::Size{ 96.0f, 12.0f } };
			SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 0, 120, 180 });
		}
		else
		{
			rect = { SGD::Point{ particles[i].GetCurrPosition().x - Game::GetInstance()->GetCameraPosition().x, particles[i].GetCurrPosition().y - Game::GetInstance()->GetCameraPosition().y }, SGD::Size{ 10.0f, 10.0f } };
			SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 0, 0, 255 });
		}
	}
	for (unsigned int j = 0; j < links.size(); j++)
	{
		if (j < (unsigned int)GetNumberOfParticles() - 1)
			SGD::GraphicsManager::GetInstance()->DrawLine(SGD::Point{ (particles[j].GetCurrPosition().x+5.0f) - Game::GetInstance()->GetCameraPosition().x, (particles[j].GetCurrPosition().y+5.0f) - Game::GetInstance()->GetCameraPosition().y }, SGD::Point{ (particles[j+1].GetCurrPosition().x+5.0f) - Game::GetInstance()->GetCameraPosition().x,( particles[j + 1].GetCurrPosition().y+5.0f) - Game::GetInstance()->GetCameraPosition().y }, SGD::Color{ 255, 255, 0, 0 });
	}
}




