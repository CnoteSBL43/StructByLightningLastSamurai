#include "Ledges.h"
#include "Game.h"

Ledges::Ledges()
{
}


Ledges::~Ledges()
{
}

void Ledges::Update(float elapsedTime)
{


}
void Ledges::Render(void)
{
	SGD::Point pt=GetPosition();
	pt.x -= Game::GetInstance()->GetCameraPosition().x;
	pt.y -= Game::GetInstance()->GetCameraPosition().y;
	SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt);
}

SGD::Rectangle Ledges::GetRect(void)	const
{
	SGD::Rectangle rect = { GetPosition(), GetSize() };
	return rect;
}

void Ledges::HandleCollision(IEntity* pOther)
{


}
