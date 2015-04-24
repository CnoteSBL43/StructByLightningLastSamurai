#pragma once
#include "../SGD Wrappers/SGD_Message.h"
#include "Actor.h"
class CreateArrowMessage :public SGD::Message
{
public:
	CreateArrowMessage(Actor*);
	~CreateArrowMessage();
	Actor* GetDartCannonOwner() const { return m_DartCannon; }

private:
	Actor* m_DartCannon = nullptr;
};

