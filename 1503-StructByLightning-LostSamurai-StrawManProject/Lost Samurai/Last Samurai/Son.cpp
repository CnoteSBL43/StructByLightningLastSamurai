#include "Son.h"
#include "Game.h"
#include "Father.h"
Son::Son()
{
	m_Timestamp.SetCurrAnim("Idle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
	//SetPosition(SGD::Point{ 100.0f, 200.0f });
	//CreateFrames();
}


Son::~Son()
{
}

void	 Son::Update(float elapsedTime)
{
	//if (GetCurrCharacter() )
	//{
	//	if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow))
	//	{
	//		m_FacingtoRight = true;
	//		m_vtVelocity.x = 64.0f;
	//		if (GetBackPack())
	//			lrArrow = true;
	//		if (frameswitch >= 0.07f)
	//		{
	//			direction++;
	//			frameswitch = 0.0f;
	//		}
	//	}
	//	else if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::LeftArrow))
	//	{
	//		m_FacingtoRight = false;
	//		m_vtVelocity.x = -64.0f;
	//		if (GetBackPack())
	//			lrArrow = true;
	//		if (frameswitch >= 0.07f)
	//		{
	//			direction++;
	//			frameswitch = 0.0f;
	//		}
	//	}
	//	else
	//		m_vtVelocity.x = 0.0f;
	//	//Jump
	//	if (lrArrow)
	//	{
	//		SetBackPack(false);
	//		m_vtVelocity.y += GetGravity();
	//	}
	//	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow))
	//	{	
	//		if (GetOnGround())
	//		{
	//			SetOnGround(false);
	//		}
	//		m_vtVelocity.y = -256.0f; 
	//		if (GetBackPack())
	//		{
	//			SetBackPack(false);
	//			upArrow = true;
	//		}
	//	}
	//	if (m_ptPosition.y<=440 && upArrow==false)//ground level -100
	//	{
	//		m_vtVelocity.y += GetGravity();
	//	}
	//	else if (m_ptPosition.y <= 364 && upArrow)//ground level -100
	//	{
	//		m_vtVelocity.y += GetGravity();
	//	}
	//	if (m_ptPosition.y>540 && !GetOnGround())
	//	{
	//		m_ptPosition.y = 540;
	//		m_vtVelocity.y = 0;
	//		SetOnGround(true);
	//		lrArrow = false;
	//		upArrow = false;
	//		if (GetBackPack())
	//			SetBackPack(false);
	//	}
	//	if (direction > 4)
	//		direction = 0;
	//	frameswitch += elapsedTime;

	//	Actor::Update(elapsedTime);
	//}
	//else if (!GetCurrCharacter() && !GetBackPack() && !GetOnGround())
	//{
	//	m_vtVelocity.x = 0.0f;
	//	Actor::Update(elapsedTime);
	//	if (m_ptPosition.y <= 440)//ground level -100
	//	{
	//		m_vtVelocity.y += GetGravity();

	//	}
	//	if (m_ptPosition.y>540 && !GetOnGround())
	//	{
	//		m_ptPosition.y = 540;
	//		m_vtVelocity.y = 0;
	//		SetOnGround(true);
	//	}
	//}

	if (GetCurrCharacter())
	{
		if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow))
		{
			m_FacingtoRight = true;
			m_vtVelocity.x = 64.0f;
			if (GetBackPack())
				lrArrow = true;
			if (AnimationSystem::GetInstance()->GetLoaded()["Running"].CheckIfLooping())
			{
				if (frameswitch > 0.1f)
				{
					direction++;
					frameswitch = 0.0f;
				}
				if (direction >= 5)
					direction = 4;
			}
			else
			{
				if (frameswitch >= 0.10f)
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
		}
		else if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::LeftArrow))
		{
			m_FacingtoRight = false;
			m_vtVelocity.x = -64.0f;
			if (GetBackPack())
				lrArrow = true;
			if (AnimationSystem::GetInstance()->GetLoaded()["Running"].CheckIfLooping())
			{

			}
			else
			{
				if (frameswitch >= 0.10f)
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
		}
		else
		{
			m_vtVelocity.x = 0.0f;
			direction = 0;
			m_Timestamp.SetCurrAnim("Idle");
			m_Timestamp.SetCurrFrame(direction);
			m_Timestamp.SetElapsedTime(elapsedTime);
		}
		//Jump
		if (lrArrow)
		{
			SetBackPack(false);
			m_vtVelocity.y += GetGravity();
		}
		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow))
		{
			if (GetOnGround())
			{
				SetOnGround(false);
				m_vtVelocity.y = -256.0f;
			}

			if (GetBackPack())
			{
				SetBackPack(false);
				upArrow = true;
				m_vtVelocity.y = -256.0f;
			}
		}
		if (m_ptPosition.y <= 440 && upArrow == false)//ground level -100
		{
			m_vtVelocity.y += GetGravity();
		}
		else if (m_ptPosition.y <= 364 && upArrow)//ground level -100
		{
			m_vtVelocity.y += GetGravity();
		}
		if (m_ptPosition.y > 540 && !GetOnGround())
		{
			m_ptPosition.y = 540;
			m_vtVelocity.y = 0;
			SetOnGround(true);
			lrArrow = false;
			upArrow = false;
			if (GetBackPack())
				SetBackPack(false);
		}
		frameswitch += elapsedTime;

		Actor::Update(elapsedTime);
	}
	else if (!GetCurrCharacter() && !GetBackPack() && !GetOnGround())
	{
		m_vtVelocity.x = 0.0f;
		direction = 0;
		m_Timestamp.SetCurrAnim("Idle");
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(elapsedTime);
		Actor::Update(elapsedTime);
		if (m_ptPosition.y <= 440)//ground level -100
		{
			m_vtVelocity.y += GetGravity();

		}
		if (m_ptPosition.y > 540 && !GetOnGround())
		{
			m_ptPosition.y = 540;
			m_vtVelocity.y = 0;
			SetOnGround(true);
		}
	}
	else if (!GetCurrCharacter())
	{
		direction = 0;
		m_Timestamp.SetCurrAnim("Idle");
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(elapsedTime);
	}
	AnimationSystem::GetInstance()->Update((int)elapsedTime, m_Timestamp);
}
void	 Son::Render(void)
{
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });

	if (m_FacingtoRight)
	{
		SGD::Point p = m_ptPosition;
		p.x -= Game::GetInstance()->GetCameraPosition().x;
		p.y -= Game::GetInstance()->GetCameraPosition().y;
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, GetSize());

	}
	else
	{
		SGD::Point p = m_ptPosition;
		p.x -= Game::GetInstance()->GetCameraPosition().x + 64.0f;
		p.y -= Game::GetInstance()->GetCameraPosition().y;
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, SGD::Size{ -GetSize().width, GetSize().height });
	}
}

SGD::Rectangle  Son::GetRect(void)	const
{
	return AnimationSystem::GetInstance()->GetSonRect();
}
void Son::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_FATHER && dynamic_cast<Son*>(this)->GetBackPack())
	{
		dynamic_cast<Son*>(this)->SetOnGround(false);
		dynamic_cast<Son*>(this)->SetCurrCharacter(false);
	}

}
