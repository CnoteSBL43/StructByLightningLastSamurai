#pragma once
//*********************************************************************//
//	File:		ParticleFlyweight.h
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	This class is mainly getter and setters and handles additional
//				functionality that will affect all the particles within an emitter.
//*********************************************************************//


class ParticleFlyweight
{
	float m_maxLife;
	float m_minLife;
	float m_colorAlphaStart;
	float m_colorRedStart;
	float m_colorBlueStart;
	float m_colorGreenStart;
	float m_colorAlphaChange;
	float m_colorRedChange;
	float m_colorBlueChange;
	float m_colorGreenChange;
	float m_colorAlphaEnd;
	float m_colorRedEnd;
	float m_colorBlueEnd;
	float m_colorGreenEnd;
	float m_scaleStart;
	float m_scaleChange;
	float m_scaleEnd;
	float m_velStart;
	float m_velChange;
	float m_velEnd;
	float m_rotationStart;
	float m_rotationChange;
	float m_rotationEnd;
	float m_gravity;
	bool m_sticky;
	bool m_noDeath;
	float m_changeTimer;

public:
	ParticleFlyweight() = default;
	~ParticleFlyweight() = default;

	// Accessors
	float GetMaxLife() { return m_maxLife; }
	float GetMinLife() { return m_minLife; }
	float GetAlphaStart() { return m_colorAlphaStart; };
	float GetRedStart() { return m_colorRedStart; };
	float GetBlueStart() { return m_colorBlueStart; };
	float GetGreenStart() { return m_colorGreenStart; };
	float GetAlphaChange() { return m_colorAlphaChange; };
	float GetRedChange() { return m_colorRedChange; };
	float GetBlueChange() { return m_colorBlueChange; };
	float GetGreenChange() { return m_colorGreenChange; };
	float GetAlphaEnd() { return m_colorAlphaEnd; };
	float GetRedEnd() { return m_colorRedEnd; };
	float GetBlueEnd() { return m_colorBlueEnd; };
	float GetGreenEnd() { return m_colorGreenEnd; };
	float GetScaleStart() { return m_scaleStart; }
	float GetScaleChange() { return m_scaleChange; }
	float GetScaleEnd() { return m_scaleEnd; }
	float GetVelocityStart() { return m_velStart; }
	float GetVelocityChange() { return m_velChange; }
	float GetVelocityEnd() { return m_velEnd; }
	float GetRotationStart() { return m_rotationStart; }
	float GetRotationChange() { return m_rotationChange; }
	float GetRotationEnd() { return m_rotationEnd; }
	float GetGravity() { return m_gravity; }
	bool GetSticky() { return m_sticky; }
	bool GetDeath() { return m_noDeath; }
	float GetTimer() { return m_changeTimer; }


	// Mutators
	void GetMaxLife(float _maxLife) { m_maxLife = _maxLife; }
	void GetMinLife(float _minLife) { m_minLife = _minLife; }
	void GetAlphaStart(float _alpha) { m_colorAlphaStart = _alpha; };
	void GetRedStart(float _red) { m_colorRedStart = _red; };
	void GetBlueStart(float _blue) { m_colorBlueStart = _blue; };
	void GetGreenStart(float _green) { m_colorGreenStart = _green; };
	void GetAlphaChange(float _alpha) { m_colorAlphaChange = _alpha; };
	void GetRedChange(float _red) { m_colorRedChange = _red; };
	void GetBlueChange(float _blue) { m_colorBlueChange = _blue; };
	void GetGreenChange(float _green) { m_colorGreenChange = _green; };
	void GetAlphaEnd(float _alpha) { m_colorAlphaEnd = _alpha; };
	void GetRedEnd(float _red) { m_colorRedEnd = _red; };
	void GetBlueEnd(float _blue) { m_colorBlueEnd = _blue; };
	void GetGreenEnd(float _green) { m_colorGreenEnd = _green; };
	void GetScaleStart(float _scale) { m_scaleStart = _scale; }
	void GetScaleChange(float _scale) { m_scaleChange = _scale; }
	void GetScaleEnd(float _scale) { m_scaleEnd = _scale; }
	void GetVelocityStart(float _velocity) { m_velStart = _velocity; }
	void GetVelocityChange(float _velocity) { m_velChange = _velocity; }
	void GetVelocityEnd(float _velocity) { m_velEnd = _velocity; }
	void GetRotationStart(float _rotation) { m_rotationStart = _rotation; }
	void GetRotationChange(float _rotation) { m_rotationChange = _rotation; }
	void GetRotationEnd(float _rotation) { m_rotationEnd = _rotation; }
	void GetGravity(float _gravity) { m_gravity = _gravity; }
	void GetSticky(bool _sticky) { m_sticky = _sticky; }
	void GetDeath(bool _death) { m_noDeath = _death; }
	void GetTimer(float _timer) { m_changeTimer = _timer; }

};

