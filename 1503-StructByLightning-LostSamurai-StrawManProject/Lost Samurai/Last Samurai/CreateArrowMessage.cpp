#include "CreateArrowMessage.h"
#include "MessageID.h"
#include "DartCannon.h"

CreateArrowMessage::CreateArrowMessage(DartCannon* _DartCannon) :Message(MessageID::MSG_ARROW)
{
	m_DartCannon = _DartCannon;
	m_DartCannon->AddRef();

}


CreateArrowMessage::~CreateArrowMessage()
{
	m_DartCannon->Release();
}
