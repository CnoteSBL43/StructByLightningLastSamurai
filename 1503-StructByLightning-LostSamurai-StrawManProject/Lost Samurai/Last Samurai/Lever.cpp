#include "Lever.h"


Lever::Lever()
{


}


Lever::~Lever()
{


}

void Lever::Update(float elapsedTime)
{

	if (playerNear)
	{
		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::E) && !GetIsTriggered())
		{
			SetTriggered(true);
		}
	}
	playerNear = false;
}

void Lever::Render(void)
{
	SGD::Rectangle rect = GetRect();
	rect.top -= Game::GetInstance()->GetCameraPosition().y;
	rect.left -= Game::GetInstance()->GetCameraPosition().x;
	rect.bottom -= Game::GetInstance()->GetCameraPosition().y;
	rect.right -= Game::GetInstance()->GetCameraPosition().x;

	SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 255, 0, 255 });

	if (GetIsTriggered())
		Game::GetInstance()->GetFont().Draw("Worked", SGD::Point{ 125.0f, 400.0f }, 0.50f);
}

SGD::Rectangle Lever::GetRect(void) const
{
	SGD::Rectangle rect = { GetPosition(), GetSize() };
	return rect;
}

void Lever::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_FATHER)
	{
		playerNear = true;
	}
	if (pOther->GetType() == ENT_SON)
	{
		playerNear = true;
	}

}
