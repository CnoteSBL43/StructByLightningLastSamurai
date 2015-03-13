#include "CreditState.h"

CreditState* CreditState::GetInstance()
{
	static CreditState m_Instance;
	return &m_Instance;
}

void CreditState::Enter()
{

}

void CreditState::Exit()
{

}

bool CreditState::Update(float _ElapsedTime)
{
	return true;
}

void CreditState::Render(float _ElapsedTime)
{

}
