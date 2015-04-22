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
#include "GameplayState.h"
#include "TileSystem.h"



ParticleManager::ParticleManager()
{
	SGD::IListener::RegisterForEvent("Walking");
	/*SGD::IListener::RegisterForEvent("Grounded");
	SGD::IListener::RegisterForEvent("Backpacking");
	SGD::IListener::RegisterForEvent("DEATH");*/
	//SGD::IListener::RegisterForEvent("Jump");
}


void ParticleManager::LoadEmitter(char* _fileName)
{
	//Game::GetInstance()->GetFont().Draw("Loading", { Game::GetInstance()->GetScreenSize().width / 2, Game::GetInstance()->GetScreenSize().height / 2 }, 1, { 255, 255, 255, 255 });
	Emitter *emitter = new Emitter();
	//Emitter emitter;
	ParticleFlyweight flyweight;

	double emit, fly;

	TiXmlDocument doc;
	if (doc.LoadFile(_fileName) == false)
		return;

	TiXmlElement* root = doc.RootElement();

	TiXmlElement* children = root->FirstChildElement("Emitter");

	TiXmlElement* emitterElements = children->FirstChildElement("Sprite");
	std::string imgName = "../resource/graphics/";
	imgName += emitterElements->Attribute("Name");
	SGD::HTexture image = SGD::GraphicsManager::GetInstance()->LoadTexture(imgName.c_str());
	emitter->SetImage(image);

	emitterElements = emitterElements->NextSiblingElement("SpriteWidth");
	emitterElements->Attribute("Width", &emit);
	emitter->SetWidth((int)emit);
	emitterElements = emitterElements->NextSiblingElement("SpriteHeight");
	emitterElements->Attribute("Height", &emit);
	emitter->SetHeight((int)emit);

	SGD::Point pt;
	emitterElements = emitterElements->NextSiblingElement("PositionX");
	emitterElements->Attribute("X", &emit);
	pt.x = 100.0f;
	emitterElements = emitterElements->NextSiblingElement("PositionY");
	emitterElements->Attribute("Y", &emit);
	pt.y = 450.0f;
	emitter->SetPosition(pt);

	SGD::Size sz;
	emitterElements = emitterElements->NextSiblingElement("SpreadWidth");
	emitterElements->Attribute("SWidth", &emit);
	sz.width = (float)emit;
	emitterElements = emitterElements->NextSiblingElement("SpreadHeight");
	emitterElements->Attribute("SHeight", &emit);
	sz.height = (float)emit;
	emitter->SetSpread(sz);

	emitterElements = emitterElements->NextSiblingElement("SpawnRate");
	emitterElements->Attribute("Rate", &emit);
	emitter->SetSpawnRate((int)emit);

	emitterElements = emitterElements->NextSiblingElement("MaximumParticles");
	emitterElements->Attribute("Max", &emit);
	emitter->SetMaxParticles((int)emit);

	children = children->NextSiblingElement("Flyweight");

	TiXmlElement* flyweightElements = children->FirstChildElement("Continuous");
	flyweightElements->Attribute("Bool", &fly);
	bool stuff;
	if (fly == 1)
		stuff = true;
	else
		stuff = false;
	emitter->SetContinuous(stuff);

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


	emitter->SetFlyweight(flyweight);
	activeEmitters.push_back(emitter);
}

ParticleManager::~ParticleManager()
{
	for (size_t i = 0; i < activeEmitters.size(); i++)
	{
		delete activeEmitters[i];
	}
	activeEmitters.clear();
}

void ParticleManager::UnLoadEmitter(std::string _emitterName)
{


}


void ParticleManager::CreateEmitter(std::string _emitterName)
{


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
				//delete *iter;
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
	activeEmitters.clear();
}


void ParticleManager::UpdateEmitter(unsigned int _emitterID, float _elapsedTime)
{
	for (size_t i = 0; i < activeEmitters.size(); i++)
	{
		activeEmitters[i]->Update(_elapsedTime);
	}
}

void ParticleManager::RenderEmitter(unsigned int _emitterID)
{
	for (size_t i = 0; i < activeEmitters.size(); i++)
	{
		activeEmitters[i]->Render();
	}
}

void ParticleManager::HandleEvent(const SGD::Event* _Event)
{
	if (_Event->GetEventID() == "Walking")
	{
		if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_FATHER)
		{
			Father* entity = reinterpret_cast<Father*>(_Event->GetSender());
			//SGD::Size sz = Game::GetInstance()->GetScreenSize();
			//SGD::Point pt = Game::GetInstance()->GetCameraPosition();
			//SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x - (int)pt.x, (int)entity->GetPosition().y - (int)pt.y, 0);
			activeEmitters[0]->SetPosition(SGD::Point{ (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().left - 400, (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().top - 300 });
			activeEmitters[0]->SetSpawning(true);
		}
		else if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_SON)
		{
			Son* entity = reinterpret_cast<Son*>(_Event->GetSender());
			//SGD::Size sz = Game::GetInstance()->GetScreenSize();
			SGD::Point pt = Game::GetInstance()->GetCameraPosition();
			SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x - (int)pt.x, (int)entity->GetPosition().y - (int)pt.y, 0);
			activeEmitters[0]->SetPosition(point);
			activeEmitters[0]->SetSpawning(true);
		}
	}
	else if (_Event->GetEventID() == "Grounded")
	{
		if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_FATHER)
		{
			Father* entity = reinterpret_cast<Father*>(_Event->GetSender());
			//SGD::Size sz = Game::GetInstance()->GetScreenSize();
			SGD::Point pt = { -100, 600 };
			//SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x , (int)entity->GetPosition().y);
			activeEmitters[1]->SetPosition(pt);
			activeEmitters[1]->SetSpawning(true);
		}
		else if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_SON)
		{
			Son* entity = reinterpret_cast<Son*>(_Event->GetSender());
			//SGD::Size sz = Game::GetInstance()->GetScreenSize();
			SGD::Point pt = Game::GetInstance()->GetCameraPosition();
			SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x - (int)pt.x, (int)entity->GetPosition().y - (int)pt.y, 0);
			activeEmitters[1]->SetPosition(point);
			activeEmitters[1]->SetSpawning(true);
		}
	}
	else if (_Event->GetEventID() == "Backpacking")
	{
		Son* entity = reinterpret_cast<Son*>(_Event->GetSender());
		//SGD::Size sz = Game::GetInstance()->GetScreenSize();
		SGD::Point pt = Game::GetInstance()->GetCameraPosition();
		SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x - (int)pt.x, (int)entity->GetPosition().y - (int)pt.y, 0);
		activeEmitters[2]->SetPosition(point);
		activeEmitters[2]->SetSpawning(true);

	}
	else if (_Event->GetEventID() == "DEATH")
	{
		if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_FATHER)
		{
			Father* entity = reinterpret_cast<Father*>(_Event->GetSender());
			//SGD::Size sz = Game::GetInstance()->GetScreenSize();
			SGD::Point pt = Game::GetInstance()->GetCameraPosition();
			SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x - (int)pt.x, (int)entity->GetPosition().y - (int)pt.y, 0);
			activeEmitters[3]->SetPosition(point);
			activeEmitters[3]->SetSpawning(true);
		}
		else if (reinterpret_cast<Player*>(_Event->GetSender())->GetType() == Actor::ENT_SON)
		{
			Son* entity = reinterpret_cast<Son*>(_Event->GetSender());
			//SGD::Size sz = Game::GetInstance()->GetScreenSize();
			SGD::Point pt = Game::GetInstance()->GetCameraPosition();
			SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x - (int)pt.x, (int)entity->GetPosition().y - (int)pt.y, 0);
			activeEmitters[3]->SetPosition(point);
			activeEmitters[3]->SetSpawning(true);
		}

	}
	//else if (_Event->GetEventID() == "Jump")
	//{
	//	Son* entity = reinterpret_cast<Son*>(_Event->GetSender());
	//	//SGD::Size sz = Game::GetInstance()->GetScreenSize();
	//	SGD::Point pt = Game::GetInstance()->GetCameraPosition();
	//	entity->GetTimeStamp().SetCurrFrame(0);
	//	SGD::Point point = AnimationSystem::GetInstance()->GetParticlePt(entity->GetTimeStamp(), (int)entity->GetPosition().x - (int)pt.x, (int)entity->GetPosition().y - (int)pt.y);
	//	activeEmitters[0]->SetPosition(point);
	//	activeEmitters[0]->SetSpawning(true);

	//}

}

