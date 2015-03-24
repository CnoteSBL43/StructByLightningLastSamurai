#pragma once
#include <string>

class AnimationTimestamp
{
private:
	
	std::string m_CurrentAnimation;
	int			m_CurrentFrame;
	float		m_TimeElapsedOnFrame;
public:
	//Ctor and Dtor
	AnimationTimestamp() = default;
	~AnimationTimestamp() = default;

	//Accessors
	std::string		GetCurrAnim() const			{ return m_CurrentAnimation; }
	int				GetCurrFrame() const		{ return m_CurrentFrame; }
	float			GetTimeOnFrame() const		{ return m_TimeElapsedOnFrame; }

	//Mutators
	void			SetCurrAnim(std::string _string)		{ m_CurrentAnimation = _string; }
	void			SetCurrFrame(int _FrameID)				{ m_CurrentFrame = _FrameID; }
	void			SetElapsedTime(float _Time)				{ m_TimeElapsedOnFrame = _Time; }

};

