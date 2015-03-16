#pragma once
#include "Actor.h"
#include"../SGD Wrappers/SGD_GraphicsManager.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Utilities.h"
class Player :
	public Actor
{
public:
	Player();
	~Player();
	// Entity Types:
	enum EntityType { ENT_BASE, ENT_FATHER, ENT_SON, ENT_SWORDSMAN };




	void	Update(float elapsedTime)	=0;
	void	Render(void)				=0;

	int		GetType(void)	const			override	{ return ENT_BASE; }
	SGD::Rectangle GetRect(void)	const			=0;
	void	HandleCollision(const IEntity* pOther)	=0;

private:
	int m_Stamina;
	int m_JumpHeight;
	bool m_Hanging;
	bool m_BackPack;
	bool m_OnGround;
	int m_CurrentCharacter;
	unsigned int	m_unRefCount = 1;	// calling new gives the 'prime' reference

	
};

