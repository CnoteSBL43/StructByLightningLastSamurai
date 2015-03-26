//*********************************************************************//
//	File:		ParticleManager.h
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	
//*********************************************************************//
#pragma once
#include "Emitter.h"
#include <vector>
#include <map>


class ParticleManager
{
	std::vector<Emitter> activeEmitters;
	std::map<std::string, Emitter> loadedEmitters;

public:
	ParticleManager() = default;
	~ParticleManager() = default;

	void LoadEmitter(char * _fileName);
	void UnLoadEmitter(std::string _emitterName);

	void CreateEmitter(std::string _emitterName);
	void FreeEmitter(unsigned int _emitterID);
	void ClearActiveEmitters();

	void UpdateEmitter(unsigned int _emitterID, float _elapsedTime);
	void RenderEmitter(unsigned int _emitterID);
};

