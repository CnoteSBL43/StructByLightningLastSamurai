#include "AnimationTimestamp.h"
void AnimationTimestamp::SetOwner(IEntity* _owner)
{
	m_Owner = _owner; 
	_owner->AddRef();
}
AnimationTimestamp::AnimationTimestamp()
{

}

AnimationTimestamp::~AnimationTimestamp()
{
	m_Owner->Release();
}