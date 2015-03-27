#include "Father.h"
#include "Game.h"
#include "Son.h"
#include "AnimationSystem.h"
#include <sstream>
Father::Father()
{
	m_Timestamp.SetOwner(this);
	m_Timestamp.SetCurrAnim("Idle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);

}


Father::~Father()
{
}



void	 Father::Update(float elapsedTime)
{
	if (GetCurrCharacter())
	{
		if (!GetOnGround() && !upArrow && !GameplayState::GetInstance()->GetK())
			m_vtVelocity.y = 64.0f;
		
		if (cannotJump)
			m_vtVelocity.y = 64.0f;

		if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow) && letRight)
		{
			m_FacingtoRight = true;
			m_vtVelocity.x = 128.0f;

			letLeft = true;
			if (frameswitch >= 0.07f)
			{
				direction++;
				frameswitch = 0.0f;
			}
			if (direction >= 5)
				direction = 0;

			m_Timestamp.SetCurrAnim("Running");
			m_Timestamp.SetCurrFrame(direction);
			m_Timestamp.SetElapsedTime(elapsedTime);

		}

		else if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::LeftArrow) && letLeft)
		{
			m_FacingtoRight = false;
			m_vtVelocity.x = -128.0f;

			letRight = true;
			if (frameswitch >= 0.07f)
			{
				direction++;
				frameswitch = 0.0f;
			}
			if (direction >= 5)
				direction = 0;

			m_Timestamp.SetCurrAnim("Running");
			m_Timestamp.SetCurrFrame(direction);
			m_Timestamp.SetElapsedTime(elapsedTime);

		}
		else
			m_vtVelocity.x = 0.0f;

		//Jump
		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow)&& !cannotJump )
		{
			if (GetOnGround())
			{
				previousPosY = m_ptPosition.y;
				SetOnGround(false);
				upArrow = true;
				m_vtVelocity.y = -256.0f;
			}
		}
		if (m_ptPosition.y <= previousPosY - 200)//ground level -100
		{
			upArrow = false;
			m_vtVelocity.y += 4.9f;
		}


		frameswitch += elapsedTime;
		Actor::Update(elapsedTime);
	}
	else if (!GetCurrCharacter())
	{
		m_vtVelocity.x = 0.0f;
		direction = 0;
		m_Timestamp.SetCurrAnim("Idle");
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(elapsedTime);
		Actor::Update(elapsedTime);
		if (m_ptPosition.y <= 380)//ground level -100
		{
			m_vtVelocity.y += GetGravity();

		}
		if (m_ptPosition.y > 480 && !GetOnGround())
		{
			m_ptPosition.y = 480;
			m_vtVelocity.y = 0;
			SetOnGround(true);
		}
	}

	AnimationSystem::GetInstance()->Update((int)elapsedTime, m_Timestamp);
}
void	 Father::Render(void)
{
	//SGD::Rectangle frame = frames[direction].rFrame;
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });
#pragma region This Region is For Debug Mode Use F3 To see the Collision Rect
	//SGD::Rectangle frame = frames[direction].rFrame;
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false)
	{
		Debug = true;

	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true)
	{
		Debug = false;
	}

	if (Debug)
	{
		SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });
	}

#pragma endregion

	if (m_FacingtoRight)
	{
		SGD::Point p = m_ptPosition;

		p.x -= Game::GetInstance()->GetCameraPosition().x;
		p.y -= Game::GetInstance()->GetCameraPosition().y;

		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, SGD::Size{ -1, 1 });
		//SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage, p,
		//	frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ GetSize().width, GetSize().height });
	}
	else
	{
		SGD::Point p = m_ptPosition;
		p.x -= Game::GetInstance()->GetCameraPosition().x;
		p.y -= Game::GetInstance()->GetCameraPosition().y;
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, SGD::Size{ 1, 1 });
		//SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage,
		//{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x - 64.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y },
		//frame, 0.0f, {}, { 255, 255, 255 }, SGD::Size{ -GetSize().width, GetSize().height });
	}
	/*std::wostringstream s1,s2;
	s1 << GetRect().top;
	s2 << GetRect().bottom;
	SGD::GraphicsManager::GetInstance()->DrawString(s1.str().c_str(), SGD::Point{ 20, 20 });
	SGD::GraphicsManager::GetInstance()->DrawString(s2.str().c_str(), SGD::Point{ 50, 20 });
	*/

}

SGD::Rectangle  Father::GetRect(void)	const
{
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, (int)m_ptPosition.x, (int)m_ptPosition.y);
}
void Father::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_SON)
	{
		this->SetCurrCharacter(true);
		dynamic_cast<Son*>(pOther)->SetBackPack(true);
	}
	if (pOther->GetType() == ENT_TILES)
	{	
		SetCollisionRect(true);
		GameplayState::GetInstance()->SetK(true);
		SGD::Rectangle Rect;
		Rect = this->GetRect().ComputeIntersection(pOther->GetRect());
		if (this->GetRect().ComputeHeight() == Rect.ComputeHeight()*2)
		{
			if ( this->GetRect().left == Rect.left)//colliding with rect on the left
			{
				//set x psoition to the right of rect or pOther rect
			//	m_ptPosition.x = pOther->GetRect().right;
				m_vtVelocity.x = 0.0f;
				letLeft = false;
			}
			else if ( this->GetRect().right == Rect.right)//colliding with rect on right
			{
			
				//set x position to the left of rect or pOther rect
				letRight = false;
				m_vtVelocity.x = 0.0f;
			}
		}
		else //(this->GetRect().ComputeWidth() == Rect.ComputeWidth())
		{
			if (this->GetRect().top < pOther->GetRect().bottom && this->GetRect().top == Rect.top)//player colliding with a collision rect on top of him
			{
				//a  bool so that he cant jump or cannot press Up arrow
				cannotJump = true;
				letLeft = true;
				letRight = true;
				m_vtVelocity.y = 0.0f;
				SetCollisionRect(false);
				GameplayState::GetInstance()->SetK(false);
			}
			else if (this->GetRect().bottom >= pOther->GetRect().top && this->GetRect().bottom == Rect.bottom)//player colliding with a collision rect below him
			{
				//set him on the floor and set ground to true
				cannotJump = false;
				SetOnGround(true);
				upArrow = false;
				m_vtVelocity.y = 0.0f;

			}
		}	

	}
}
