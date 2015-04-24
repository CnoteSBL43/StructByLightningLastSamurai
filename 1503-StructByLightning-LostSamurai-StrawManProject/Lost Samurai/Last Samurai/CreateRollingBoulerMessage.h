#pragma once
#include "../SGD Wrappers/SGD_Message.h"
#include "Actor.h"
#include "MessageID.h"
class CreateRollingBoulerMessage : public SGD::Message
{
private:
	Actor* player = nullptr;
public:
	CreateRollingBoulerMessage(Actor* player);
	~CreateRollingBoulerMessage();
	Actor* GetPlayer() const{ return player; }
};

