#include "CreateRockMessage.h"
#include "MessageID.h"

CreateRockMessage::CreateRockMessage(FallingRockTrap* _FRT) : Message(MessageID::MSG_ROCK)
{
	Owner = _FRT;
	Owner->AddRef();
}


CreateRockMessage::~CreateRockMessage()
{
	Owner->Release();
}
