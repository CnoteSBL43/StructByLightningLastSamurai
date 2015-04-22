#include "CheckPoint.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "Father.h"
#include "Son.h"


CheckPoint::CheckPoint()
{
}


CheckPoint::~CheckPoint()
{
}


void CheckPoint::Update(float elapsedTime)
{

}

void CheckPoint::Render(void)
{
	SGD::Rectangle rect = GetRect();
	rect.top -= Game::GetInstance()->GetCameraPosition().y;
	rect.left -= Game::GetInstance()->GetCameraPosition().x;
	rect.bottom -= Game::GetInstance()->GetCameraPosition().y;
	rect.right -= Game::GetInstance()->GetCameraPosition().x;

	SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 255, 0, 255 });
}

SGD::Rectangle CheckPoint::GetRect(void) const
{
	SGD::Rectangle rect = { GetPosition(), GetSize() };
	return rect;
}

void CheckPoint::HandleCollision(IEntity* pOther)
{

	if (pOther->GetType() == ENT_FATHER)
	{
		dynamic_cast<Father*>(pOther)->SetCheckPoint(GetPosition());
		SGD::Event* event = new SGD::Event("Walking", nullptr, this);
		event->QueueEvent();
	}
}
