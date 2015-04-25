#include "FinalDoor.h"
#include "Game.h"

FinalDoor::FinalDoor()
{
}


FinalDoor::~FinalDoor()
{
}

void	FinalDoor::Update(float elapsedTime)
{

}
void	FinalDoor::Render(void)
{
	SGD::Point pt = GetPosition();
	pt.x -= Game::GetInstance()->GetCameraPosition().x;
	pt.y -= Game::GetInstance()->GetCameraPosition().y;
	SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt);
}
SGD::Rectangle FinalDoor::GetRect(void)	const
{
	SGD::Rectangle rect = { GetPosition(), GetSize() };
	return rect;
}
void	FinalDoor::HandleCollision(IEntity* pOther)
{

}