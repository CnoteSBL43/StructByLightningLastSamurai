#pragma once
#include "Spike.h"
class PopUpSpikes : public Spike
{
private:
	float m_ActivateTime = 5.0f;
	float m_ActivationTimer = 0.0f;
	float m_ActiveTimer = 0.0f;
	float m_DeactivateTime = 5.0f;
	bool isActive = true;
	SGD::Point m_currentpos = { m_ptPosition.x, 68 };
	SGD::Point bottom = { m_ptPosition.x, m_ptPosition.y + (150.0f) };

public:
	PopUpSpikes();
	~PopUpSpikes();
	void Render();
	void Update(float _elapsedtime);
	void	HandleCollision(IEntity* pOther);
	int GetType() const { return ENT_POPUPSPIKES; }
	SGD::Rectangle GetRect() const;
protected:
	//SGD::Rectangle rect;
	bool Debug = false;
};

