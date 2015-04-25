#pragma once
#include "GameObjects.h"


class PressurePlate : public GameObjects
{
	bool isHeavy;
	float totalWeights;
	int ID;
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
	int	GetType(void) const	{ return ENT_PLATES; }
	void SetID(int _id){ ID = _id; }
	int GetID() const { return ID; }
	//bool check = false;
};

