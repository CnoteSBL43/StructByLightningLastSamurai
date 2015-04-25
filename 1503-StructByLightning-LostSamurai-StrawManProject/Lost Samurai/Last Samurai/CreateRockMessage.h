#pragma once
#include "../SGD Wrappers/SGD_Message.h"
#include "FallingRockTrap.h"
class CreateRockMessage : public SGD::Message
{
	FallingRockTrap* Owner = nullptr;
public:
	//CreateRockMessage() = default;
	CreateRockMessage(FallingRockTrap*);
	~CreateRockMessage();
	FallingRockTrap* GetOwner()const { return Owner; }
};

