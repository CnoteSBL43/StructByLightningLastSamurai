#pragma once
#include "GameObjects.h"
#include "AnimationSystem.h"

class PressurePlate : public GameObjects
{
private:
	bool isHeavy;
	float totalWeights;
	AnimationTimestamp m_Timestamp;
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

	int GetType() const { return ENT_PRESSURE_PLATE; }

	bool check = false;
};

