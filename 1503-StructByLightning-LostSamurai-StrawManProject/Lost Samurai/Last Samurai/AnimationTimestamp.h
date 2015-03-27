#pragma once
#include <string>
#include "IEntity.h"
class AnimationTimestamp
{
private:
	
	std::string m_CurrentAnimation;
	int			m_CurrentFrame;
	float		m_TimeElapsedOnFrame;
	IEntity*	m_Owner;
public:
	//Ctor and Dtor
	AnimationTimestamp() = default;
	~AnimationTimestamp() = default;

	//Accessors
	std::string		GetCurrAnim() const			{ return m_CurrentAnimation; }
	int				GetCurrFrame() const		{ return m_CurrentFrame; }
	float			GetTimeOnFrame() const		{ return m_TimeElapsedOnFrame; }
	IEntity*		GetOwner() const			{ return m_Owner; }

	//Mutators
	void			SetCurrAnim(std::string _string)		{ m_CurrentAnimation = _string; }
	void			SetCurrFrame(int _FrameID)				{ m_CurrentFrame = _FrameID; }
	void			SetElapsedTime(float _Time)				{ m_TimeElapsedOnFrame = _Time; }
	void			SetOwner(IEntity* _owner)				{ m_Owner = _owner; }
};

