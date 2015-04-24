#pragma once
#include "Spike.h"
#include "AnimationSystem.h"
class PopUpSpikes : public Spike
{
private:
	float m_ActivateTime = 5.0f;
	float m_ActivationTimer = 0.0f;
	float m_ActiveTimer = 0.0f;
	float m_DeactivateTime = 5.0f;
	bool isActive = true;
	AnimationTimestamp m_Timestamp;
public:
	PopUpSpikes();
	~PopUpSpikes();
	void Render();
	void Update(float _elapsedtime);
	void	HandleCollision(IEntity* pOther);
	int GetType() const { return ENT_POPUPSPIKES; }
	SGD::Rectangle GetRect() const;
	unsigned int currframe = 0;
	float frametimer = 0.0f;
protected:
	//SGD::Rectangle rect;
	bool Debug = false;
};

