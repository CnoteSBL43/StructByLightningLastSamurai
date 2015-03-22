//*********************************************************************//
//	File:		Particle.h
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	This class is used to define a single particle within the
//				game, this class is only setter and getters to keep track 
//				the current attributes the particles is rendering to the screen.
//*********************************************************************//


#pragma once
#include "Particle.h"
#include "ParticleFlyweight.h"
#include <queue>
#include <list>




class Emitter
{
	unsigned int m_spawnRate;
	int m_width;
	int m_height;
	int m_maxSpread;
	int m_minSpread;
	Point m_position;
	ParticleFlyweight m_attributes;
	std::list<Particle*> aliveList;
	std::queue<Particle*> deadQueue;

	void UpdateRotation(float elapsedTime);
	void UpdateScale(float elapsedTime);
	void UpdateMove(float elapsedTime);
	void UdpateColor(float elapsedTime);

public:
	Emitter();
	~Emitter();

	// Accessors
	unsigned int GetSpawnRate() { return m_spawnRate; }
	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }
	int GetMaxSpread() { return m_maxSpread; }
	int GetMinSpread() { return m_minSpread; }

	// Mutators
	void GetSpawnRate(int _spawn) { m_spawnRate = _spawn ; }
	void GetWidth(int _width) { m_width = _width; }
	void GetHeight(int _height) { m_height = _height; }
	void GetMaxSpread(int _maxSpread) { m_maxSpread = _maxSpread; }
	void GetMinSpread(int _minSpread) { m_minSpread = _minSpread; }


	void Update(float elapsedTime);
	void Render();

	void CreateParticles();
	void DeadParticles(std::list<Particle*>::iterator& _iter);

	void Clear();
};

