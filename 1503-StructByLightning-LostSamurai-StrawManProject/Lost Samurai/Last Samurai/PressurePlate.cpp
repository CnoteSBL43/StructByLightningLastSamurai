#include "PressurePlate.h"
#include "Father.h"
#include "Son.h"
#include "Box.h"
#include "../SGD Wrappers/SGD_EventManager.h"

PressurePlate::PressurePlate()
{
	m_Timestamp.SetCurrAnim("PressurePlate");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
}


PressurePlate::~PressurePlate()
{
}


void PressurePlate::Update(float elapsedTime)
{
	if (GetHeavy())
		SetWeight(100.0f);
	else
		SetWeight(50.0f);
//	check = false;
}

void PressurePlate::Render(void)
{
	//SGD::Rectangle rect = GetRect();
	/*rect.top -= Game::GetInstance()->GetCameraPosition().y;
	rect.left -= Game::GetInstance()->GetCameraPosition().x;
	rect.bottom -= Game::GetInstance()->GetCameraPosition().y;
	rectright -= Game::GetInstance()->GetCameraPosition().x;
	*/
	SGD::Point pt = m_ptPosition;
	pt.x -= Game::GetInstance()->GetCameraPosition().x;
	pt.y -= Game::GetInstance()->GetCameraPosition().y;
	SGD::Point pt = m_ptPosition;
	pt.x -= Game::GetInstance()->GetCameraPosition().x;
	pt.y -= Game::GetInstance()->GetCameraPosition().y;

	SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 255, 0, 255 });
	if (!check)
		AnimationSystem::GetInstance()->Render(m_Timestamp, pt.x, pt.y);
	//if (check)
	//	Game::GetInstance()->GetFont().Draw("Worked", SGD::Point{ 125.0f, 400.0f }, 0.50f);
}

SGD::Rectangle PressurePlate::GetRect(void)	const
{

	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, m_ptPosition.x, m_ptPosition.y);
}

void PressurePlate::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_FATHER)
	{
		if (GetWeight() == dynamic_cast<Father*>(pOther)->GetWeight())
		{

		}
	}
	if (pOther->GetType() == ENT_SON)
	{
		if (GetWeight() == dynamic_cast<Son*>(pOther)->GetWeight())
		{
			
		}

	}
	if (pOther->GetType() == ENT_BOX)
	{
		if (GetWeight() == dynamic_cast<Box*>(pOther)->GetWeight())
		{
			SGD::Event* event = new SGD::Event("Plates", nullptr, this);
			event->QueueEvent();
		}
	}
}
