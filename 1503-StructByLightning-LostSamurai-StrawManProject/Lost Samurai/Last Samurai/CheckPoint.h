#pragma once
#include "GameObjects.h"
class CheckPoint :
	public GameObjects
{
public:
	CheckPoint();
	~CheckPoint();

	void	Update(float elapsedTime);
	void	Render(void);

	SGD::Rectangle GetRect(void)	const;
	void	HandleCollision(IEntity* pOther);
};

