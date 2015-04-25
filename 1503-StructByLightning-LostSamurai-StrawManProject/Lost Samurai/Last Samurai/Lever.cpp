#include "Lever.h"


Lever::Lever()
{


}


Lever::~Lever()
{


}

void Lever::Update(float elapsedTime)
{
}

void Lever::Render(void)
{
	SGD::Rectangle rect = GetRect();
	rect.top -= Game::GetInstance()->GetCameraPosition().y;
	rect.left -= Game::GetInstance()->GetCameraPosition().x;
	rect.bottom -= Game::GetInstance()->GetCameraPosition().y;
	rect.right -= Game::GetInstance()->GetCameraPosition().x;

	SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 255, 0, 255 });
}

SGD::Rectangle Lever::GetRect(void) const
{
	SGD::Rectangle rect = { GetPosition(), GetSize() };
	return rect;
}

void Lever::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_FATHER )
	{
		SGD::Event* event = new SGD::Event("Levers", nullptr, this);
		event->QueueEvent();
	}
	if (pOther->GetType() == ENT_SON)
	{
		SGD::Event* event = new SGD::Event("Levers", nullptr, this);
		event->QueueEvent();
	}
}
