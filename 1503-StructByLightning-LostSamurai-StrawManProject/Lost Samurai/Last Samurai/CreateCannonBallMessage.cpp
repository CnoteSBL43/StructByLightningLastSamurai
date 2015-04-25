#include "CreateCannonBallMessage.h"
#include "Cannon.h"
#include "MessageID.h"

CreateCannonBallMessage::CreateCannonBallMessage(Cannon* _Cannon):Message(MessageID::MSG_CANNON_BALL)
{
	m_Cannon = _Cannon;
	m_Cannon->AddRef();
}


CreateCannonBallMessage::~CreateCannonBallMessage()
{
	m_Cannon->Release();
}
