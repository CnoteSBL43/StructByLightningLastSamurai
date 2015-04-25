//*********************************************************************//
//	File:		Emitter.h
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	
//*********************************************************************//
#pragma once

#include "ParticleFlyweight.h"
#include "../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include <list>

class Particle;

class Emitter
{
	SGD::HTexture m_sprite = SGD::INVALID_HANDLE;
	bool m_continuous;
	unsigned int m_maximumParticles;
	unsigned int m_spawnRate;
	int m_width;
	int m_height;
	SGD::Point m_position;
	SGD::Size m_spread;
	ParticleFlyweight m_attributes;

	float m_spawnTime;
	bool m_spawning;
	bool m_delete;
	std::list<Particle*> aliveList;

	float ToRadians(float degree)
	{
		return (float)(SGD::PI / 180) * degree;
	}

public:
	Emitter();
	~Emitter();

	// Accessors
	ParticleFlyweight GetFlyweight() { return m_attributes; }
	unsigned int GetMaxParticles() const { return m_maximumParticles; }
	unsigned int GetSpawnRate() const { return m_spawnRate; }
	SGD::Point GetPosition() const { return m_position; }
	SGD::Size GetSpread() const { return m_spread; }
	SGD::HTexture GetImage() const { return m_sprite; }
	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }
	bool GetContinuous() const { return m_continuous; }
	bool GetSpawning() const { return m_spawning; }
	bool GetDelete() const { return m_delete; }

	// Mutators
	void SetFlyweight(ParticleFlyweight _attributes) { m_attributes = _attributes; }
	void SetMaxParticles(unsigned int _maxParticles) { m_maximumParticles = _maxParticles; }
	void SetSpawnRate(int _spawn) { m_spawnRate = _spawn ; }
	void SetPosition(SGD::Point _pos) { m_position = _pos; }
	void SetSpread(SGD::Size _spread) { m_spread = _spread; }
	void SetImage(SGD::HTexture _sprite) { m_sprite = _sprite; }
	void SetWidth(int _width) { m_width = _width; }
	void SetHeight(int _height) { m_height = _height; }
	void SetContinuous(bool _continuous) { m_continuous = _continuous; }
	void SetSpawning(bool _spawning) { m_spawning = _spawning; }
	void SetDelete(bool _delete) { m_delete = _delete; }

	void Update(float _elapsedTime);
	void Render();

	void CreateParticles();

	void Clear();
};

