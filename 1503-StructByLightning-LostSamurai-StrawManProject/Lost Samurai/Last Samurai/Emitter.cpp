#include "Emitter.h"


Emitter::Emitter()
{
	m_spawnRate = 0;
	m_width = 0;
	m_height = 0;
	m_maxSpread = 0;
	m_minSpread = 0;
	m_position.X = 0;
	m_position.Y = 0;
}


Emitter::~Emitter()
{



}

void Emitter::UdpateColor(float elapsedTime)
{


}

void Emitter::UpdateScale(float elapsedTime)
{


}

void Emitter::UpdateRotation(float elapsedTime)
{


}

void Emitter::UpdateMove(float elapsedTime)
{
	

}

void Emitter::Clear()
{
	std::list<Particle*>::iterator iter = aliveList.begin();

	while (iter != aliveList.end())
	{
		delete *iter;
		aliveList.erase(iter);
	}
	
}

void Emitter::Update(float elapsedTime)
{
	std::list<Particle*>::iterator iter = aliveList.begin();

	while (iter != aliveList.end())
	{
		(*iter)->SetCurrLife((*iter)->GetCurrLife() + elapsedTime);
		if ((*iter)->GetCurrLife() >= (*iter)->GetMaxLife())
		{

		}
		else
		{
			Point pt;
			pt.X = (*iter)->GetPosition().X + (*iter)->GetVelocityCurr().X;
			pt.Y = (*iter)->GetPosition().Y + (*iter)->GetVelocityCurr().Y;
			(*iter)->SetPosition(pt);
		}

		iter++;
	}
}


void Emitter::Render()
{
	std::list<Particle*>::iterator iter = aliveList.begin();

	while (iter != aliveList.end())
	{


		iter++;
	}
}

void Emitter::CreateParticles()
{
	if (deadQueue.size() >= GetSpawnRate())
	{


	}
	else
	{
		Particle* particle = new Particle();
		Point position;
		int maxLife;

		position.X = (rand() % GetMaxSpread()) + m_position.X;
		position.Y = (rand() % GetMaxSpread()) + m_position.Y;
		particle->SetPosition(position);
		maxLife = (int)m_attributes.GetMinLife() * 10 - (rand() % ((int)m_attributes.GetMaxLife() * 10 + (int)m_attributes.GetMinLife() * 10));
		particle->SetMaxLife((float)maxLife / 10);
		particle->SetCurrLife(0);

		aliveList.push_back(particle);
	}
}

void Emitter::DeadParticles(std::list<Particle*>::iterator& _iter)
{
	//deadQueue.push((*_iter));
	//aliveList.erase(_iter);
}
