#include "DestroyActorMessage.h"
#include "Actor.h"
#include "MessageID.h"
#include "../SGD Wrappers/SGD_Message.h"

DestroyActorMessage::DestroyActorMessage(Actor* _Destroy) :SGD::Message(MessageID::MSG_DESTORY_ACTOR)
{
	ActorMessage = _Destroy;
	ActorMessage->AddRef();
}


DestroyActorMessage::~DestroyActorMessage()
{
	ActorMessage->Release();
}
