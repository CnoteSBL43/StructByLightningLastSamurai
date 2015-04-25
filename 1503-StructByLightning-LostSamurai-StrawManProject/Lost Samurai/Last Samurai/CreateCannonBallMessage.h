#pragma once
class Cannon;
#include "../SGD Wrappers/SGD_Message.h"
class CreateCannonBallMessage: public SGD::Message
{
public:
	CreateCannonBallMessage(Cannon*);
	~CreateCannonBallMessage();
	Cannon* GetCannonOwner() const { return m_Cannon; }


private:

	Cannon* m_Cannon;

};

