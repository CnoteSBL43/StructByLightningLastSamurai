#pragma once
#include "../SGD Wrappers/SGD_Geometry.h"

class Frame
{
	//Data Members
private:
	SGD::Rectangle	m_DrawFrame;
	SGD::Rectangle	m_CollisionRect;
	SGD::Point		m_AnchorPoint;
	SGD::Point		m_ParticlePoint;
	float m_Timer;
public:

	//Ctor and Dtor
	Frame() = default;
	~Frame() = default;

	//Accessors 
	SGD::Rectangle	GetDrawFrame() const		{ return m_DrawFrame; }
	SGD::Rectangle	GetCollisionRect() const	{ return m_CollisionRect; }
	SGD::Point		GetAnchorPt() const			{ return m_AnchorPoint; }
	SGD::Point		GetParticlePt() const		{ return m_ParticlePoint; }
	float			GetTimer() const			{ return m_Timer; }

	//Mutators
	void			SetDrawFrame(SGD::Rectangle _rect)		{ m_DrawFrame = _rect; }
	void			SetCollisionRect(SGD::Rectangle _rect)	{ m_CollisionRect = _rect; }
	void			SetAnchorPt(SGD::Point _pt)				{ m_AnchorPoint = _pt; }
	void			SetParticlePt(SGD::Point _pt)			{ m_ParticlePoint = _pt; }
	void			SetTimer(float _timer)					{ m_Timer = _timer; }
};

