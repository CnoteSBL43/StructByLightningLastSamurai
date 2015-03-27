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
#include "../SGD Wrappers/SGD_Event.h"
#include "../SGD Wrappers/SGD_IListener.h"


class ParticleManager : public SGD::IListener
{
	std::vector<Emitter> activeEmitters;
	std::map<std::string, Emitter> loadedEmitters;

public:
	ParticleManager();
	~ParticleManager() = default;

	void LoadEmitter(char * _fileName);
	void UnLoadEmitter(std::string _emitterName);

	void CreateEmitter(std::string _emitterName);
	void FreeEmitter(unsigned int _emitterID);
	void ClearActiveEmitters();

	void UpdateEmitter(unsigned int _emitterID, float _elapsedTime);
	void RenderEmitter(unsigned int _emitterID);

	void HandleEvent(const SGD::Event* _Event);
};

