#include "Ladder.h"


Ladder::Ladder()
{
}


Ladder::~Ladder()
{
}


void Ladder::Update(float elapsedTime)
{


}

void Ladder::Render(void)
{
	//SGD::Rectangle rect = GetRect();
	//rect.top -= Game::GetInstance()->GetCameraPosition().y;
	//rect.left -= Game::GetInstance()->GetCameraPosition().x;
	//rect.bottom -= Game::GetInstance()->GetCameraPosition().y;
	//rect.right -= Game::GetInstance()->GetCameraPosition().x;
	SGD::Point pt = GetPosition();
	pt.x -= Game::GetInstance()->GetCameraPosition().x;
	pt.y -= Game::GetInstance()->GetCameraPosition().y;
	SGD::GraphicsManager::GetInstance()->DrawTexture(GetImage(), pt);
}

SGD::Rectangle Ladder::GetRect(void) const
{
	SGD::Rectangle rect = { GetPosition(), GetSize() };
	return rect;
}


void Ladder::HandleCollision(IEntity* pOther)
{


}
