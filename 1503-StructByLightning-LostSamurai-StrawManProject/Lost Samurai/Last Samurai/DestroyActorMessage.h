#pragma once
#include "../SGD Wrappers/SGD_Message.h"
class Actor;
class DestroyActorMessage: public SGD::Message
{
public:
	DestroyActorMessage(Actor* _Destroy);
	~DestroyActorMessage();
	Actor* GetEntityMessage() const { return ActorMessage; }

private:
	Actor* ActorMessage;
};

