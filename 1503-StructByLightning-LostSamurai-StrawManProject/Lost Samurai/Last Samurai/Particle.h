#pragma once
//*********************************************************************//
//	File:		Particle.h
//	Author:		Jacob Keffer
//	Course:		SGP - 1501
//	Purpose:	This class is used to define a single particle within the
//				game, this class is only setter and getters to keep track 
//				the current attributes the particles is rendering to the screen.
//*********************************************************************//


// Structure: Point
// Purpose: Basic structure to store the point in 
// which a single particle is displayed on screen.
struct Point
{
	int X, Y;
};

class Particle
{
	float m_maxLife;
	float m_minLife;
	float m_currLife;
	Point m_point;
	float m_colorAlphaCurr;
	float m_colorRedCurr;
	float m_colorBlueCurr;
	float m_colorGreenCurr;
	float m_scaleCurr;
	Point m_velCurr;
	float m_rotationCurr;


public:
	Particle() = default;
	~Particle() = default;
	

	// Accessors
	float GetMaxLife(){ return m_maxLife; }
	float GetMinLife(){ return m_minLife; }
	float GetCurrLife() { return m_currLife; }
	Point GetPosition(){ return m_point; }
	float GetAlphaCurr(){ return m_colorAlphaCurr; }
	float GetRedCurr(){ return m_colorRedCurr; }
	float GetGreenCurr(){ return m_colorGreenCurr; }
	float GetBlueCurr(){ return m_colorBlueCurr; }
	float GetScaleCurr(){ return m_scaleCurr; }
	Point GetVelocityCurr(){ return m_velCurr; }
	float GetRotationCurr(){ return m_rotationCurr; }

	// Mutators
	void SetMaxLife(float _maxLife){ m_maxLife = _maxLife; }
	void SetMinLife(float _minLife){ m_minLife = _minLife; }
	void SetCurrLife(float _currLife) { m_currLife = _currLife; }
	void SetPosition(Point _pos){ m_point = _pos; }
	void SetAlphaCurr(float _alpha){ m_colorAlphaCurr = _alpha; }
	void SetRedCurr(float _red){ m_colorRedCurr = _red; }
	void SetGreenCurr(float _green){ m_colorGreenCurr = _green; }
	void SetBlueCurr(float _blue){ m_colorBlueCurr = _blue; }
	void SetScaleCurr(float _scale){ m_scaleCurr = _scale; }
	Point SetVelocityCurr(Point _velocity){ m_velCurr = _velocity; }
	void SetRotationCurr(float _rotation){ m_rotationCurr = _rotation; }

};

