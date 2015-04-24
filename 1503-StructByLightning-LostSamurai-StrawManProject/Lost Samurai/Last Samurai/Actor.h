#pragma once

#include "IEntity.h"						// IEntity type
#include "../SGD Wrappers/SGD_Handle.h"		// HTexture type
#include "../SGD Wrappers/SGD_Geometry.h"	// Point & Vector type


//*********************************************************************//
// Entity class
//	- parent class of all game entities, stores the shared data members
//	- velocity-based movement
class Actor : public IEntity
{
	//*****************************************************************//
	// Destructor MUST be virtual for upcasted objects
	//		Entity* ptr = new Ship;
	//		delete ptr;
public:		Actor(void) = default;
protected:	virtual ~Actor(void) = default;		// protected to force reference counting


public:
	//*****************************************************************//
	// Entity Types:
	enum EntityType 
	{
		ENT_BASE, ENT_PLAYER, ENT_FATHER, ENT_SON, ENT_TILES,
		ENT_SWORDSMAN, ENT_TRIGGER, ENT_CANNONBALL, ENT_ARROW, ENT_BOX, ENT_POPUPSPIKES,
		ENT_LEDGE, ENT_GAMEOBJECT, ENT_DOOR, ENT_AUTO_LOCK_DOOR, ENT_BOWMAN, ENT_SMASHING_COLUMNS, ENT_FALLING_ROCK,
		ENT_ROLLING_BOULDER, ENT_DART_TRAP,ENT_LEVERS, ENT_PRESSURE_PLATE
	};

	//*****************************************************************//
	// Facing Direction
	//enum DIRECTION {F_LEFT, F_RIGHT};

	//*****************************************************************//
	// Interface:
	//	- virtual functions for children classes to override
	virtual void	Update(float elapsedTime)	override;
	virtual void	Render(void)				override;

	virtual int		GetType(void)	const			override	{ return ENT_BASE; }
	virtual SGD::Rectangle GetRect(void)	const			override;
	virtual void	HandleCollision(IEntity* pOther)	override;


	//*****************************************************************//
	// Reference Counting:
	virtual void	AddRef(void)				final;
	virtual void	Release(void)				final;


	//*****************************************************************//
	// Accessors:
	SGD::HTexture	GetImage(void) const			{ return m_hImage; }
	SGD::Point		GetPosition(void) const			{ return m_ptPosition; }
	SGD::Vector		GetVelocity(void) const			{ return m_vtVelocity; }
	SGD::Size		GetSize(void) const			{ return m_szSize; }
	float			GetRotation(void) const			{ return m_fRotation; }
	bool			GetAlive(void) const			{ return m_Alive; }

	float			GetWeight() const					{ return m_Weight; }
	// Mutators:
	void			SetImage(SGD::HTexture	img)	{ m_hImage = img; }
	void			SetPosition(SGD::Point	pos) 	{ m_ptPosition = pos; }
	void			SetVelocity(SGD::Vector	vel) 	{ m_vtVelocity = vel; }
	void			SetSize(SGD::Size		size) 	{ m_szSize = size; }
	void			SetRotation(float			rad)	{ m_fRotation = rad; }
	void			SetAlive(bool _alive)				{ m_Alive = _alive; }
	void			SetWeight(float _weight)			{ m_Weight = _weight; }
protected:
	//*****************************************************************//
	// Shared members:
	SGD::HTexture	m_hImage = SGD::INVALID_HANDLE;	// image handle
	SGD::Point		m_ptPosition = SGD::Point{ 0, 0 };	// 2D position
	SGD::Vector		m_vtVelocity = SGD::Vector{ 0, 0 };	// 2D velocity
	SGD::Size		m_szSize = SGD::Size{ 0, 0 };	// 2D size
	float			m_fRotation = 0.0f;
	bool			m_Alive = false;
private:
	//*****************************************************************//
	// reference count
	unsigned int	m_unRefCount = 1;	// calling new gives the 'prime' reference
	float m_Weight;
};
