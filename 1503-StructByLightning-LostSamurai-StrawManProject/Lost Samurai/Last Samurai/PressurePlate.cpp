#include "PressurePlate.h"
#include "Father.h"
#include "Son.h"
#include "Box.h"

PressurePlate::PressurePlate()
{
}


PressurePlate::~PressurePlate()
{
}


void PressurePlate::Update(float elapsedTime)
{
	if (GetHeavy())
		SetWeight(150.0f);
	else
		SetWeight(50.0f);
	check = false;
}

void PressurePlate::Render(void)
{
	SGD::Rectangle rect = GetRect();
	rect.top -= Game::GetInstance()->GetCameraPosition().y;
	rect.left -= Game::GetInstance()->GetCameraPosition().x;
	rect.bottom -= Game::GetInstance()->GetCameraPosition().y;
	rect.right -= Game::GetInstance()->GetCameraPosition().x;

	SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 255, 0, 255 });

	if (check)
		Game::GetInstance()->GetFont().Draw("Worked", SGD::Point{ 125.0f, 400.0f }, 0.50f);
}

SGD::Rectangle PressurePlate::GetRect(void)	const
{
	SGD::Rectangle rect = { GetPosition(), GetSize() };
	return rect;
}

void PressurePlate::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_FATHER)
	{
		if (GetWeight() == dynamic_cast<Father*>(pOther)->GetWeight())
			check = true;
	}
	if (pOther->GetType() == ENT_SON)
	{
		if (GetWeight() == dynamic_cast<Son*>(pOther)->GetWeight())
			check = true;
	}
	if (pOther->GetType() == ENT_BOX)
	{
		if (GetWeight() == dynamic_cast<Box*>(pOther)->GetWeight())
			check = true;
	}
}
