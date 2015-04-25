//*********************************************************************//
//	File:		ParticleFlyweight.h
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	This class is mainly getter and setters and handles additional
//				functionality that will affect all the particles within an emitter.
//*********************************************************************//
#pragma once

class ParticleFlyweight
{
	float m_maxLife;
	float m_minLife;
	float m_colorAlphaStart;
	float m_colorRedStart;
	float m_colorBlueStart;
	float m_colorGreenStart;
	float m_colorAlphaEnd;
	float m_colorRedEnd;
	float m_colorBlueEnd;
	float m_colorGreenEnd;
	float m_scaleStart;
	float m_scaleEnd;
	float m_velXPos;
	float m_velXNeg;
	float m_velYPos;
	float m_velYNeg;
	float m_rotationStart;
	float m_rotationEnd;
	//float m_gravity;
	//bool m_sticky;
	//bool m_noDeath;
	//float m_changeTimer;

public:
	ParticleFlyweight() = default;
	~ParticleFlyweight() = default;

	// Accessors
	float GetMaxLife() const { return m_maxLife; }
	float GetMinLife() const { return m_minLife; }
	float GetAlphaStart() const { return m_colorAlphaStart; };
	float GetRedStart() const { return m_colorRedStart; };
	float GetBlueStart() const { return m_colorBlueStart; };
	float GetGreenStart() const { return m_colorGreenStart; };
	float GetAlphaEnd() const { return m_colorAlphaEnd; };
	float GetRedEnd() const { return m_colorRedEnd; };
	float GetBlueEnd() const { return m_colorBlueEnd; };
	float GetGreenEnd() const { return m_colorGreenEnd; };
	float GetScaleStart() const { return m_scaleStart; }
	float GetScaleEnd() const { return m_scaleEnd; }
	float GetVelocityXPos() const { return m_velXPos; }
	float GetVelocityXNeg() const { return m_velXNeg; }
	float GetVelocityYPos() const { return m_velYPos; }
	float GetVelocityYNeg() const { return m_velXNeg; }
	float GetRotationStart() const { return m_rotationStart; }
	float GetRotationEnd() const { return m_rotationEnd; }
	/*float GetGravity() { return m_gravity; }
	bool GetSticky() { return m_sticky; }
	bool GetDeath() { return m_noDeath; }
	float GetTimer() { return m_changeTimer; }*/


	// Mutators
	void SetMaxLife(float _maxLife) { m_maxLife = _maxLife; }
	void SetMinLife(float _minLife) { m_minLife = _minLife; }
	void SetAlphaStart(float _alpha) { m_colorAlphaStart = _alpha; };
	void SetRedStart(float _red) { m_colorRedStart = _red; };
	void SetBlueStart(float _blue) { m_colorBlueStart = _blue; };
	void SetGreenStart(float _green) { m_colorGreenStart = _green; };
	void SetAlphaEnd(float _alpha) { m_colorAlphaEnd = _alpha; };
	void SetRedEnd(float _red) { m_colorRedEnd = _red; };
	void SetBlueEnd(float _blue) { m_colorBlueEnd = _blue; };
	void SetGreenEnd(float _green) { m_colorGreenEnd = _green; };
	void SetScaleStart(float _scale) { m_scaleStart = _scale; }
	void SetScaleEnd(float _scale) { m_scaleEnd = _scale; }
	void SetVelocityXPos(float _velocity) { m_velXPos = _velocity; }
	void SetVelocityXNeg(float _velocity) { m_velXNeg = _velocity; }
	void SetVelocityYPos(float _velocity) { m_velYPos = _velocity; }
	void SetVelocityYNeg(float _velocity) { m_velYNeg = _velocity; }
	void SetRotationStart(float _rotation) { m_rotationStart = _rotation; }
	void SetRotationEnd(float _rotation) { m_rotationEnd = _rotation; }
	/*void GetGravity(float _gravity) { m_gravity = _gravity; }
	void GetSticky(bool _sticky) { m_sticky = _sticky; }
	void GetDeath(bool _death) { m_noDeath = _death; }
	void GetTimer(float _timer) { m_changeTimer = _timer; }*/

};

