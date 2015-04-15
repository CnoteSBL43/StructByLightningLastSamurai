#include "Tile.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "Game.h"
Tile::Tile()
{
}


Tile::~Tile()
{
}


void Tile::Render()
{
	if (Debug)
	{


		//camera offest
		SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
		SGD::Size screen = Game::GetInstance()->GetScreenSize();
		//the render rect after the offest
		SGD::Point pt = { (GetPosition().x - screen.width / 2)- PositionOffset.x
			, GetPosition().y - PositionOffset.y };

		//render rect
		SGD::Rectangle draw = rect;

		draw.left = pt.x;
		draw.right = draw.left + rect.ComputeWidth();
		draw.top = pt.y;
		draw.bottom = draw.top + rect.ComputeHeight();

		//draw rect
		SGD::GraphicsManager::GetInstance()->DrawRectangle(draw, SGD::Color{ 255, 0, 0, 0 }, {}, 3);
		//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 0, 255, 255, 255 }, { 255, 255, 255, 255 }, 3);
	}
}

void Tile::HandleCollision(IEntity* pOther)
{

	if (pOther->GetType() == ENT_FATHER && this->GetType() == ENT_TRIGGER)
	{

		SGD::Event* FatherDeath = new SGD::Event("Death", nullptr, this);
		FatherDeath->SendEventNow(pOther);
		delete FatherDeath;

	}
	if (pOther->GetType() == ENT_SON && this->GetType() == ENT_TRIGGER)
	{

		SGD::Event* SonDeath = new SGD::Event("Death", nullptr, this);
		SonDeath->SendEventNow(pOther);
		delete SonDeath;
	}


}

int Tile::GetType(void)	const
{

	return _Type;

}

SGD::Rectangle Tile::GetRect() const
{
	//camera offest
	//SGD::Point PositionOffset = Game::GetInstance()->GetCameraPosition();
	SGD::Size screen = Game::GetInstance()->GetScreenSize();
	//the render rect after the offest
	SGD::Point pt = { GetPosition().x - screen.width / 2, GetPosition().y};

	//render rect
	SGD::Rectangle draw = rect;

	draw.left = pt.x;
	draw.right = draw.left + rect.ComputeWidth();
	draw.top = pt.y;
	draw.bottom = draw.top + rect.ComputeHeight();

	return draw;
}

void Tile::Update(float _elapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false)
		Debug = true;

	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true)
		Debug = false;

}
