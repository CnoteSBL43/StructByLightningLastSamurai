//*********************************************************************//
//	File:		Emitter.cpp
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	
//*********************************************************************//
#include "Emitter.h"
#include "Particle.h"
#include "Game.h"


Emitter::Emitter()
{
	m_spawnRate = 0;
	m_width = 0;
	m_height = 0;
	m_spread.width = 0;
	m_spread.height = 0;
	m_position.x = 0;
	m_position.y = 0;
	m_spawnTime = .100f;
}


Emitter::~Emitter()
{
	Clear();
}


void Emitter::Clear()
{
	std::list<Particle*>::iterator iter = aliveList.begin();

	while (iter != aliveList.end())
	{
		delete *iter;
		iter = aliveList.erase(iter);
	}
	aliveList.clear();
}

void Emitter::Update(float _elapsedTime)
{
	m_spawnTime -= _elapsedTime;

	if (aliveList.size() < GetMaxParticles())
		CreateParticles();

	std::list<Particle*>::iterator iter = aliveList.begin();

	while (iter != aliveList.end())
	{
		(*iter)->SetCurrLife((*iter)->GetCurrLife() - _elapsedTime);
		if ((*iter)->GetCurrLife() <= 0)
		{
			delete *iter;
			iter = aliveList.erase(iter);
		}
		else
		{
			SGD::Point pt;
			pt.x = ((*iter)->GetPosition().x + (*iter)->GetVelocityCurr().x * _elapsedTime);
			pt.y = ((*iter)->GetPosition().y + (*iter)->GetVelocityCurr().y * _elapsedTime);
			(*iter)->SetPosition(pt);

			float partLifeProg = (*iter)->GetMaxLife() - (*iter)->GetCurrLife() / (*iter)->GetMaxLife();

			(*iter)->SetScaleCurr(((GetFlyweight().GetScaleEnd() - GetFlyweight().GetScaleStart()) *partLifeProg) + GetFlyweight().GetScaleStart());
			(*iter)->SetRotationCurr(ToRadians(((GetFlyweight().GetRotationEnd() - GetFlyweight().GetRotationStart()) *partLifeProg) + GetFlyweight().GetRotationStart()));

			(*iter)->SetAlphaCurr(((GetFlyweight().GetAlphaEnd() - GetFlyweight().GetAlphaStart()) *partLifeProg) + GetFlyweight().GetAlphaStart());
			(*iter)->SetRedCurr(((GetFlyweight().GetRedEnd() - GetFlyweight().GetRedStart()) *partLifeProg) + GetFlyweight().GetRedStart());
			(*iter)->SetGreenCurr(((GetFlyweight().GetGreenEnd() - GetFlyweight().GetGreenStart()) *partLifeProg) + GetFlyweight().GetGreenStart());
			(*iter)->SetBlueCurr(((GetFlyweight().GetBlueEnd() - GetFlyweight().GetBlueStart()) *partLifeProg) + GetFlyweight().GetBlueStart());

			iter++;
		}
	}
}


void Emitter::Render()
{
	std::list<Particle*>::iterator iter = aliveList.begin();

	while (iter != aliveList.end())
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_sprite, (*iter)->GetPosition(), (*iter)->GetRotationCurr(),
			SGD::Vector((float)GetWidth() / 2, (float)GetHeight() / 2), SGD::Color((unsigned char)(*iter)->GetAlphaCurr(), 
			(unsigned char)(*iter)->GetRedCurr(), (unsigned char)(*iter)->GetGreenCurr(), (unsigned char)(*iter)->GetBlueCurr()), 
			SGD::Size((*iter)->GetScaleCurr(), (*iter)->GetScaleCurr()));

		iter++;
	}
}

void Emitter::CreateParticles()
{
	/*if (deadQueue.size() >= GetSpawnRate())
	{


	}
	else*/
	if (m_spawnTime <= 0)
	{
		for (size_t i = 0; i < GetSpawnRate(); i++)
		{
			Particle* particle = new Particle();
			SGD::Point position;
			int maxLife;

			position.x = (rand() % (int)GetSpread().width) + m_position.x;
			position.y = (rand() % (int)GetSpread().height) + m_position.y;
			particle->SetPosition(position);
			maxLife = (int)m_attributes.GetMinLife() * 10 - (rand() % ((int)m_attributes.GetMaxLife() * 10 + (int)m_attributes.GetMinLife() * 10));
			particle->SetMaxLife((float)maxLife / 10);
			particle->SetCurrLife(particle->GetMaxLife());
			particle->SetScaleCurr(GetFlyweight().GetScaleStart());
			particle->SetRotationCurr(0);
			particle->SetAlphaCurr(GetFlyweight().GetAlphaStart());
			particle->SetRedCurr(GetFlyweight().GetRedStart());
			particle->SetGreenCurr(GetFlyweight().GetGreenStart());
			particle->SetBlueCurr(GetFlyweight().GetBlueStart());

			SGD::Point randXY;
			randXY.x = ((rand() % (int)(GetFlyweight().GetVelocityXPos() + (GetFlyweight().GetVelocityXNeg() * -1))) + 1) + GetFlyweight().GetVelocityXNeg();
			randXY.y = ((rand() % (int)(GetFlyweight().GetVelocityYPos() + (GetFlyweight().GetVelocityYNeg() * -1))) + 1) + GetFlyweight().GetVelocityYNeg();

			particle->SetVelocityCurr(randXY);

			aliveList.push_back(particle);
		}
		m_spawnTime = .100f;
	}
}

//void Emitter::DeadParticles(std::list<Particle*>::iterator& _iter)
//{
//	//deadQueue.push((*_iter));
//	//aliveList.erase(_iter);
//}
