#include "RespawnFatherMessage.h"
#include "MessageID.h"

RespawnFatherMessage::RespawnFatherMessage(Actor* _father) : Message(MessageID::MSG_DIED)
{
	father = _father;
}


RespawnFatherMessage::~RespawnFatherMessage()
{
	if (father != nullptr)
	{
		father->Release();
		father = nullptr;
	}
}

void RespawnFatherMessage::RespawnFather()
{
	father->SetPosition(SGD::Point{ 300.0f, 466.0f });
}
