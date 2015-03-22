#pragma once

#include "../SGD Wrappers/SGD_Geometry.h"	// Rectangle type
#include "../SGD Wrappers/SGD_Handle.h"

//*********************************************************************//
// IEntity class
//	- interface base class:
//		- virtual methods for children classes to override
//		- no data members
class IEntity
{
public:
	//*****************************************************************//
	// Interface:
	//	- pure virtual methods MUST be overridden in the child class


	virtual void	Update			( float elapsedTime )		= 0;
	virtual void	Render			( void )					= 0;
	
	virtual int		GetType			( void )	const			= 0;
	virtual SGD::Rectangle GetRect	( void )	const			= 0;
	virtual void	HandleCollision	(  IEntity* pOther )	= 0;

	//*****************************************************************//
	// Reference Counting:
	//	- keep the object in memory as long as there is a pointer
	//	  to the object
	virtual void	AddRef			( void )					= 0;
	virtual void	Release			( void )					= 0;

protected:
	//*****************************************************************//
	// Destructor MUST be virtual
	IEntity( void )				= default;
	virtual ~IEntity( void )	= default;		// protected to force reference counting
	////*****************************************************************//
	//// Accessors:
	//SGD::HTexture	GetImage(void) const			{ return m_hImage; }
	//SGD::Point		GetPosition(void) const			{ return m_ptPosition; }
	//SGD::Vector		GetVelocity(void) const			{ return m_vtVelocity; }
	//SGD::Size		GetSize(void) const			{ return m_szSize; }
	//float			GetRotation(void) const			{ return m_fRotation; }

	//// Mutators:
	//void			SetImage(SGD::HTexture	img)	{ m_hImage = img; }
	//void			SetPosition(SGD::Point	pos) 	{ m_ptPosition = pos; }
	//void			SetVelocity(SGD::Vector	vel) 	{ m_vtVelocity = vel; }
	//void			SetSize(SGD::Size		size) 	{ m_szSize = size; }
	//void			SetRotation(float			rad)	{ m_fRotation = rad; }
	//void			SetAlive(bool _alive)				{ m_Alive = _alive; }
	////*****************************************************************//
	//// Shared members:
	//SGD::HTexture	m_hImage = SGD::INVALID_HANDLE;	// image handle
	//SGD::Point		m_ptPosition = SGD::Point{ 0, 0 };	// 2D position
	//SGD::Vector		m_vtVelocity = SGD::Vector{ 0, 0 };	// 2D velocity
	//SGD::Size		m_szSize = SGD::Size{ 0, 0 };	// 2D size
	//float			m_fRotation = 0.0f;
	//bool			m_Alive = false;

};
