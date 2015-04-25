//*********************************************************************//
//	File:		ParticleManager.cpp
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	
//*********************************************************************//

#include "ParticleManager.h"
#include "ParticleFlyweight.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../resource/TinyXML/tinystr.h"
#include "../resource/TinyXML/tinyxml.h"
#include "AnimationSystem.h"
#include "Father.h"
#include "Son.h"
#include "Game.h"

ParticleManager::ParticleManager()
{
	SGD::IListener::RegisterForEvent("StepParticles");
}


void ParticleManager::LoadEmitter(char* _fileName)
{
	ParticleFlyweight flyweight;
	double emit, fly;

	TiXmlDocument doc;
	if (doc.LoadFile(_fileName) == false)
		return;

	TiXmlElement* root = doc.RootElement();
	std::string name = root->Attribute("Name");

	TiXmlElement* children = root->FirstChildElement("Emitter");

	TiXmlElement* emitterElements = children->FirstChildElement("Sprite");
	std::string imgName = "../resource/graphics/";
	imgName += emitterElements->Attribute("Name");
	SGD::HTexture image = SGD::GraphicsManager::GetInstance()->LoadTexture(imgName.c_str());
	loadedEmitters[name].SetImage(image);

	emitterElements = emitterElements->NextSiblingElement("SpriteWidth");
	emitterElements->Attribute("Width", &emit);
	loadedEmitters[name].SetWidth((int)emit);
	emitterElements = emitterElements->NextSiblingElement("SpriteHeight");
	emitterElements->Attribute("Height", &emit);
	loadedEmitters[name].SetHeight((int)emit);

	SGD::Point pt;
	emitterElements = emitterElements->NextSiblingElement("PositionX");
	emitterElements->Attribute("X", &emit);
	pt.x = 0.0f;
	emitterElements = emitterElements->NextSiblingElement("PositionY");
	emitterElements->Attribute("Y", &emit);
	pt.y = 0.0f;
	loadedEmitters[name].SetPosition(pt);

	SGD::Size sz;
	emitterElements = emitterElements->NextSiblingElement("SpreadWidth");
	emitterElements->Attribute("SWidth", &emit);
	sz.width = (float)emit;
	emitterElements = emitterElements->NextSiblingElement("SpreadHeight");
	emitterElements->Attribute("SHeight", &emit);
	sz.height = (float)emit;
	loadedEmitters[name].SetSpread(sz);

	emitterElements = emitterElements->NextSiblingElement("SpawnRate");
	emitterElements->Attribute("Rate", &emit);
	loadedEmitters[name].SetSpawnRate((int)emit);

	emitterElements = emitterElements->NextSiblingElement("MaximumParticles");
	emitterElements->Attribute("Max", &emit);
	loadedEmitters[name].SetMaxParticles((int)emit);

	children = children->NextSiblingElement("Flyweight");

	TiXmlElement* flyweightElements = children->FirstChildElement("Continuous");
	flyweightElements->Attribute("Bool", &fly);
	bool cont;
	if (fly == 1)
		cont = true;
	else
		cont = false;
	loadedEmitters[name].SetContinuous(cont);

	flyweightElements = flyweightElements->NextSiblingElement("VelXPos");
	flyweightElements->Attribute("XPos", &fly);
	flyweight.SetVelocityXPos((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("VelXNeg");
	flyweightElements->Attribute("XNeg", &fly);
	flyweight.SetVelocityXNeg((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("VelYPos");
	flyweightElements->Attribute("YPos", &fly);
	flyweight.SetVelocityYPos((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("VelYNeg");
	flyweightElements->Attribute("YNeg", &fly);
	flyweight.SetVelocityYNeg((float)fly);

	flyweightElements = flyweightElements->NextSiblingElement("ScaleStart");
	flyweightElements->Attribute("ScaleS", &fly);
	flyweight.SetScaleStart((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("ScaleEnd");
	flyweightElements->Attribute("ScaleE", &fly);
	flyweight.SetScaleEnd((float)fly);

	flyweightElements = flyweightElements->NextSiblingElement("RotationStart");
	flyweightElements->Attribute("RotS", &fly);
	flyweight.SetRotationStart((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("RotationEnd");
	flyweightElements->Attribute("RotE", &fly);
	flyweight.SetRotationEnd((float)fly);

	flyweightElements = flyweightElements->NextSiblingElement("LifeMin");
	flyweightElements->Attribute("Min", &fly);
	flyweight.SetMinLife((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("LifeMax");
	flyweightElements->Attribute("Max", &fly);
	flyweight.SetMaxLife((float)fly);

	flyweightElements = flyweightElements->NextSiblingElement("StartAlpha");
	flyweightElements->Attribute("StartA", &fly);
	flyweight.SetAlphaStart((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("StartRed");
	flyweightElements->Attribute("StartR", &fly);
	flyweight.SetRedStart((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("StartGreen");
	flyweightElements->Attribute("StartG", &fly);
	flyweight.SetGreenStart((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("StartBlue");
	flyweightElements->Attribute("StartB", &fly);
	flyweight.SetBlueStart((float)fly);

	flyweightElements = flyweightElements->NextSiblingElement("EndAlpha");
	flyweightElements->Attribute("EndA", &fly);
	flyweight.SetAlphaEnd((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("EndRed");
	flyweightElements->Attribute("EndR", &fly);
	flyweight.SetRedEnd((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("EndGreen");
	flyweightElements->Attribute("EndG", &fly);
	flyweight.SetGreenEnd((float)fly);
	flyweightElements = flyweightElements->NextSiblingElement("EndBlue");
	flyweightElements->Attribute("EndB", &fly);
	flyweight.SetBlueEnd((float)fly);

	loadedEmitters[name].SetFlyweight(flyweight);
}

ParticleManager::~ParticleManager()
{
	ClearActiveEmitters();
	std::map<std::string, Emitter>::iterator iter = loadedEmitters.begin();

	while (iter != loadedEmitters.end())
	{
		iter = UnLoadEmitter(iter->first);
	}
}

std::map<std::string, Emitter>::iterator ParticleManager::UnLoadEmitter(std::string _emitterName)
{
	std::map<std::string, Emitter>::iterator iter = loadedEmitters.find(_emitterName);

	SGD::GraphicsManager::GetInstance()->UnloadTexture(loadedEmitters[_emitterName].GetImage());
	return loadedEmitters.erase(iter);
}


void ParticleManager::CreateEmitter(std::string _emitterName)
{
	Emitter* emitter = new Emitter;
	*emitter = loadedEmitters[_emitterName];
	activeEmitters.push_back(emitter);
}

void ParticleManager::FreeEmitter(unsigned int _emitterID)
{
	if (_emitterID < activeEmitters.size())
	{
		std::vector<Emitter*>::iterator iter = activeEmitters.begin();

		int count = 0;

		while (iter != activeEmitters.end())
		{
			if (count == _emitterID)
			{
				(*iter)->Clear();
				delete *iter;
				iter = activeEmitters.erase(iter);
				break;
			}
			else
			{
				iter++;
				count++;
			}
		}
	}
}

void ParticleManager::ClearActiveEmitters()
{
	for (size_t i = 0; i < activeEmitters.size(); i++)
	{
		activeEmitters[i]->Clear();
		delete activeEmitters[i];
	}
	activeEmitters.clear();
}


void ParticleManager::UpdateEmitter(float _elapsedTime)
{
	for (size_t i = 0; i < activeEmitters.size(); i++)
	{
		activeEmitters[i]->Update(_elapsedTime);
		if (activeEmitters[i]->GetDelete())
			FreeEmitter(i);
	}
}

void ParticleManager::RenderEmitter()
{
	for (size_t i = 0; i < activeEmitters.size(); i++)
	{
		activeEmitters[i]->Render();
	}
}

void ParticleManager::HandleEvent(const SGD::Event* _Event)
{
	if (_Event->GetEventID() == "StepParticles")
	{
		if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_FATHER)
		{
			Father* entity = reinterpret_cast<Father*>(_Event->GetSender());
			loadedEmitters["StepParticles"].SetPosition(entity->GetPosition());
			CreateEmitter("StepParticles");
		}
		else if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_SON)
		{
			Son* entity = reinterpret_cast<Son*>(_Event->GetSender());
			loadedEmitters["StepParticles"].SetPosition(entity->GetPosition());
			CreateEmitter("StepParticles");
		}
	}
}

