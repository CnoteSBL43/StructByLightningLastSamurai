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
#include <queue>
#include <list>

class Particle;

class Emitter
{
	SGD::HTexture m_sprite = SGD::INVALID_HANDLE;
	std::string m_name;
	bool m_continuous;
	unsigned int m_maximumParticles;
	unsigned int m_spawnRate;
	unsigned long m_ulGameTime = 0;
	int m_width;
	int m_height;
	SGD::Point m_position;
	SGD::Size m_spread;
	ParticleFlyweight m_attributes;

	float m_spawnTime;
	std::list<Particle*> aliveList;
	std::queue<Particle*> deadQueue;


	float ToRadians(float degree)
	{
		return (float)(SGD::PI / 180) * degree;
	}

	/*void UpdateRotation(float elapsedTime);
	void UpdateScale(float elapsedTime);
	void UpdateMove(float elapsedTime);
	void UdpateColor(float elapsedTime);*/

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
	const char* GetSprite() const { return m_name.c_str(); }
	int GetWidth() const { return m_width; }
	int GetHeight() const { return m_height; }
	bool GetContinuous() const { return m_continuous; }

	// Mutators
	void SetFlyweight(ParticleFlyweight _attributes) { m_attributes = _attributes; }
	void SetMaxParticles(unsigned int _maxParticles) { m_maximumParticles = _maxParticles; }
	void SetSpawnRate(int _spawn) { m_spawnRate = _spawn ; }
	void SetPosition(SGD::Point _pos) { m_position = _pos; }
	void SetSpread(SGD::Size _spread) { m_spread = _spread; }
	void SetImage(SGD::HTexture _sprite) { m_sprite = _sprite; }
	void SetSprite(const char* _name) { m_name = _name; }
	void SetWidth(int _width) { m_width = _width; }
	void SetHeight(int _height) { m_height = _height; }
	void SetContinuous(bool _continuous) { m_continuous = _continuous; }

	void Update(float _elapsedTime);
	void Render();

	void CreateParticles();
	//void DeadParticles(std::list<Particle*>::iterator& _iter);

	void Clear();
};

