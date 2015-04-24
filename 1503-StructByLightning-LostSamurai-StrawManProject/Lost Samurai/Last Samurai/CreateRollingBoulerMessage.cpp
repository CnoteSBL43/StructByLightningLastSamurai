#include "CreateRollingBoulerMessage.h"


CreateRollingBoulerMessage::CreateRollingBoulerMessage(Actor* _player) : Message(MessageID::MSG_BOULDER)
{
	player = _player;
	player->AddRef();
}


CreateRollingBoulerMessage::~CreateRollingBoulerMessage()
{
	if (player != nullptr)
	{
		player->Release();
		player = nullptr;
	}
}
