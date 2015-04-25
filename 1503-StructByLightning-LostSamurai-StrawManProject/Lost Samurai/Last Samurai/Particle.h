//*********************************************************************//
//	File:		Particle.h
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	This class is used to define a single particle within the
//				game, this class is only setter and getters to keep track 
//				the current attributes the particles is rendering to the screen.
//*********************************************************************//
#pragma once

#include "../SGD Wrappers/SGD_GraphicsManager.h"

// Structure: Point
// Purpose: Basic structure to store the point in 
// which a single particle is displayed on screen.
//struct Point
//{
//	int X, Y;
//};

class Particle
{
	float m_maxLife;
	float m_currLife;
	SGD::Point m_point;
	float m_colorAlphaCurr;
	float m_colorRedCurr;
	float m_colorBlueCurr;
	float m_colorGreenCurr;
	float m_scaleCurr;
	SGD::Point m_velCurr;
	float m_rotationCurr;


public:
	Particle() = default;
	~Particle() = default;
	

	// Accessors
	float GetMaxLife() const { return m_maxLife; }
	float GetCurrLife() const { return m_currLife; }
	SGD::Point GetPosition() const { return m_point; }
	float GetAlphaCurr() const { return m_colorAlphaCurr; }
	float GetRedCurr() const { return m_colorRedCurr; }
	float GetGreenCurr() const { return m_colorGreenCurr; }
	float GetBlueCurr() const { return m_colorBlueCurr; }
	float GetScaleCurr()const { return m_scaleCurr; }
	SGD::Point GetVelocityCurr() const { return m_velCurr; }
	float GetRotationCurr() const { return m_rotationCurr; }

	// Mutators
	void SetMaxLife(float _maxLife){ m_maxLife = _maxLife; }
	void SetCurrLife(float _currLife) { m_currLife = _currLife; }
	void SetPosition(SGD::Point _pos){ m_point = _pos; }
	void SetAlphaCurr(float _alpha){ m_colorAlphaCurr = _alpha; }
	void SetRedCurr(float _red){ m_colorRedCurr = _red; }
	void SetGreenCurr(float _green){ m_colorGreenCurr = _green; }
	void SetBlueCurr(float _blue){ m_colorBlueCurr = _blue; }
	void SetScaleCurr(float _scale){ m_scaleCurr = _scale; }
	void SetVelocityCurr(SGD::Point _velocity){ m_velCurr = _velocity; }
	void SetRotationCurr(float _rotation){ m_rotationCurr = _rotation; }

};

