#pragma once
#include "../SGD Wrappers/SGD_Geometry.h"
#include <string>
#include <vector>
class Frame
{
	//Data Members
private:
	SGD::Rectangle	m_DrawFrame;
	SGD::Rectangle	m_CollisionRect;
	SGD::Point		m_AnchorPoint;
	std::vector<SGD::Point>		m_ParticlePoint;
	std::string m_EventType;
	std::string m_EventName;
	float m_Timer;
public:

	//Ctor and Dtor
	Frame() = default;
	~Frame() = default;

	//Accessors 
	SGD::Rectangle	GetDrawFrame() const					{ return m_DrawFrame; }
	SGD::Rectangle	GetCollisionRect() const				{ return m_CollisionRect; }
	SGD::Point		GetAnchorPt() const						{ return m_AnchorPoint; }
	std::vector<SGD::Point>&		GetParticlePt() 		{ return m_ParticlePoint; }
	float			GetTimer() const						{ return m_Timer; }
	std::string		GetTriggerType() const					{ return m_EventType; }
	std::string		GetTriggerName() const					{ return m_EventName; }


	//Mutators
	void			SetDrawFrame(SGD::Rectangle _rect)							{ m_DrawFrame = _rect; }
	void			SetCollisionRect(SGD::Rectangle _rect)						{ m_CollisionRect = _rect; }
	void			SetAnchorPt(SGD::Point _pt)									{ m_AnchorPoint = _pt; }
	void			AddParticlePoint(SGD::Point _pt)							{ m_ParticlePoint.push_back(_pt);}
	void			SetTimer(float _timer)										{ m_Timer = _timer; }
	void			SetTriggerType(std::string _eventtype)						{ m_EventType = _eventtype; }
	void			SetTriggerName(std::string _eventname)						{ m_EventName = _eventname; }

};

