#pragma once
#include "GameObjects.h"


class PressurePlate : public GameObjects
{
	bool isHeavy;
	float totalWeights;

public:
	PressurePlate();
	~PressurePlate();

	bool GetHeavy() { return isHeavy; }
	float GetTotalWeight() { return totalWeights; }

	void SetHeavy(bool _heavy) { isHeavy = _heavy; }
	void SetTotalWeight(float _weight) { totalWeights = _weight; }

	void Update(float elapsedTime);
	void Render(void);

	SGD::Rectangle GetRect(void)	const;
	void HandleCollision(IEntity* pOther);

	bool check = false;
};

