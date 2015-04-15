#pragma once
#include "MessageID.h"
#include "../SGD Wrappers/SGD_Message.h"
#include "Actor.h"
class CreateSwordMan :public SGD::Message
{
public:
	CreateSwordMan(Actor* player);
	~CreateSwordMan();

	Actor* GetPlayer() const
	{
		return player;
	}
private:
	Actor* player;
};

