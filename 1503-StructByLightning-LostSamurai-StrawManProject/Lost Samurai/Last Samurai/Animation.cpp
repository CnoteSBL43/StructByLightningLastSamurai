#include "Animation.h"

Animation::~Animation()
{
	Clear();
}

void Animation::AddFrames(Frame _frame)
{
	m_Frames.push_back(_frame);
}

void Animation::Clear()
{
	m_Frames.clear();
}

bool Animation::CheckIfLooping() const
{
	if (IsLooping == true)
		return true;
	else
		return false;
}