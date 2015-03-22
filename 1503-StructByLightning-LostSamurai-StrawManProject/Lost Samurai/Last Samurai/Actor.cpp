//*********************************************************************//
//	File:		Entity.cpp
//	Author:		Cory Saunders
//	Course:		SGD - 1501
//	Purpose:	Entity class is the base moving-object entity,
//				storing shared members for children classes
//*********************************************************************//

#include "Actor.h"

#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Utilities.h"


//*********************************************************************//
// Update
//	- move the entity by its velocity
//	  (given that velocity is the rate of change in pixels-per-second)
/*virtual*/ void Actor::Update( float elapsedTime )	/*override*/
{
	m_ptPosition += m_vtVelocity * elapsedTime;
}

//*********************************************************************//
// Render
//	- draw the entity's image at its position
/*virtual*/ void Actor::Render(void)		/*override*/
{
	// Validate the image
	SGD_ASSERT( m_hImage != SGD::INVALID_HANDLE, 
		"Actor::Render - image was not set!" );
	
	// HACK: rotate
	//m_fRotation += 0.001f;
	
	// Draw the image
	SGD::GraphicsManager::GetInstance()->DrawTexture( 
		m_hImage, m_ptPosition,
		m_fRotation, m_szSize / 2 );
}


//*********************************************************************//
// GetRect
//	- calculate the entity's bounding rectangle
/*virtual*/ SGD::Rectangle Actor::GetRect(void) const	/*override*/
{
	return SGD::Rectangle{ m_ptPosition, m_szSize };
}


//*********************************************************************//
// HandleCollision
//	- respond to collision between entities
/*virtual*/ void Actor::HandleCollision( IEntity* pOther)	/*override*/
{
	/* DO NOTHING */
	(void)pOther;		// unused parameter
}


//*********************************************************************//
// AddRef
//	- increase the reference count
/*virtual*/ void Actor::AddRef(void)		/*final*/
{
	SGD_ASSERT( m_unRefCount != 0xFFFFFFFF, 
		"Actor::AddRef - maximum reference count has been exceeded" );

	++m_unRefCount;
}

//*********************************************************************//
// Release
//	- decrease the reference count
//	- self-destruct when no references remain
/*virtual*/ void Actor::Release(void)	/*final*/
{
	--m_unRefCount;

	if( m_unRefCount == 0 )
		delete this;
}
