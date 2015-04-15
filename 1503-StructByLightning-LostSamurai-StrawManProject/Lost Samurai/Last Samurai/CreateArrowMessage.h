#pragma once
#include "../SGD Wrappers/SGD_Message.h"
class DartCannon;
class CreateArrowMessage:public SGD::Message
{
public:
	CreateArrowMessage(DartCannon*);
	~CreateArrowMessage();
	DartCannon* GetDartCannonOwner() const { return m_DartCannon; }

private:
	DartCannon* m_DartCannon;
};

