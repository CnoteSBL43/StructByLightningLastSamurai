#include "CreateSwordMan.h"

CreateSwordMan::CreateSwordMan(Actor* _player) :Message(MessageID::MSG_CREATESWORDMAN)
{
	player = _player;
	player->AddRef();
}


CreateSwordMan::~CreateSwordMan()
{
	if (player != nullptr)
	{
		player->Release();
		player = nullptr;
	}
}
