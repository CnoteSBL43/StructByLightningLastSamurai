#pragma once
#include "Actor.h"
#include "../SGD Wrappers/SGD_Message.h"
class RespawnFatherMessage:public SGD::Message
{
public:
	RespawnFatherMessage(Actor* _father);
	~RespawnFatherMessage();
	
	void RespawnFather();
	Actor* GetFather()const
	{
		return father;
	}
private:
	Actor *father;
};

