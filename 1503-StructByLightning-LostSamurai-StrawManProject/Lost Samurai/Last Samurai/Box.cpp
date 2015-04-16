#include "Box.h"


Box::Box()
{
}


Box::~Box()
{
}

void Box::CalculateVelocity(SGD::Vector v)
{
	//if (isHeavy)
	//	SetVelocity({ v.x *0.5f ,v.y}) ;
	//else
	//	SetVelocity({ v.x *0.75f, v.y });

}

void Box::Update(float elapsedTime)
{

}

void Box::Render(void)
{

}
SGD::Rectangle Box::GetRect(void)	const
{
	 SGD::Rectangle rect = {0.0f,0.0f,10.0f,10.0f};
	 return rect;
}
void Box::HandleCollision(IEntity* pOther)
{

}