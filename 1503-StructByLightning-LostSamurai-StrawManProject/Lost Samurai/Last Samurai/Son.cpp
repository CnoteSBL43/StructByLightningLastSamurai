#include "Son.h"
#include "Game.h"
#include "Father.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "GameplayState.h"
#include "TileSystem.h"
#include"AutoLockingDoor.h"
Son::Son()
{
	m_Timestamp.SetCurrAnim("SonIdle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
	//SetPosition(SGD::Point{ 100.0f, 200.0f });
	//CreateFrames();
	SGD::IListener::RegisterForEvent("Death");
	SetStamina(50);
}



Son::~Son()
{
}

void	 Son::Update(float elapsedTime)
{
	if (m_Timestamp.GetCurrAnim() != "SonDeath")
	{
		if (GetCurrCharacter())
		{
			if (GetBackPack())
				m_vtVelocity.y = 0.0f;
			if (!GetOnGround() && !upArrow  && !GetBackPack() && !lrArrow)
				m_vtVelocity.y = 512.0f;
			if (cannotJump)
				m_vtVelocity.y = 512.0f;
			if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow) && letRight)
			{
				m_FacingtoRight = true;
				m_vtVelocity.x = 512.0f;
				if (GetBackPack())
					lrArrow = true;
				letLeft = true;
				if (frameswitch >= 0.1f)
				{
					direction++;
					frameswitch = 0.0f;
				}
				if (direction >= 4)
				{
					direction = 0;
				}
				m_Timestamp.SetCurrAnim("SonRunning");
				m_Timestamp.SetCurrFrame(direction);
				m_Timestamp.SetElapsedTime(elapsedTime);
			}
			else if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::LeftArrow) && letLeft)
			{
				m_FacingtoRight = false;
				m_vtVelocity.x = -512.0f;
				if (GetBackPack())
					lrArrow = true;
				letRight = true;
				if (frameswitch >= 0.1f)
				{
					direction++;
					frameswitch = 0.0f;
				}
				if (direction >= 4)
				{
					direction = 0;
				}
				m_Timestamp.SetCurrAnim("SonRunning");
				m_Timestamp.SetCurrFrame(direction);
				m_Timestamp.SetElapsedTime(elapsedTime);
			}
			else
			{
				m_vtVelocity.x = 0.0f;
				direction = 0;
				m_Timestamp.SetCurrAnim("SonIdle");
				m_Timestamp.SetCurrFrame(direction);
				m_Timestamp.SetElapsedTime(elapsedTime);
			}
			if (lrArrow)
			{
				SetBackPack(false);
				m_vtVelocity.y += 4.9f;
			}
			//Jump
			if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && !cannotJump)
			{
				if (GetStamina() >= 10)
				{
					if (GetOnGround())
					{
						SetStamina(GetStamina() - 10);
						previousPosY = m_ptPosition.y;
						SetOnGround(false);
						upArrow = true;
						m_vtVelocity.y = -1024.0f;
					}
					if (GetBackPack())
					{
						SetStamina(GetStamina() - 10);
						previousPosY = m_ptPosition.y;
						m_vtVelocity.y = -512.0f;
						SetBackPack(false);
						upArrow = true;
					}
					//grounded = true;
				}
			}
			if (GetOnGround())
			{
				upArrow = false;
			}
			if (!GetOnGround() && upArrow == true)
			{
				m_vtVelocity.y += 2.0f;
			}
			frameswitch += elapsedTime;
			Actor::Update(elapsedTime);
		}
		else if (!GetCurrCharacter() && !GetBackPack())
		{
			m_vtVelocity.x = 0.0f;
			direction = 0;
			m_Timestamp.SetCurrAnim("SonIdle");
			m_Timestamp.SetCurrFrame(direction);
			m_Timestamp.SetElapsedTime(elapsedTime);
			Actor::Update(elapsedTime);
			if (!GetOnGround() && upArrow == true)//ground level -100
			{
				m_vtVelocity.y += 2.0f;
			}
			if (GetOnGround())
			{
				upArrow = false;
			}
		}
		else if (!GetCurrCharacter() && GetBackPack())
		{
			m_vtVelocity.x = 0.0f;
			m_vtVelocity.y = 0.0f;
			direction = 0;
			m_Timestamp.SetCurrAnim("SonIdle");
			m_Timestamp.SetCurrFrame(direction);
			m_Timestamp.SetElapsedTime(elapsedTime);
			Actor::Update(elapsedTime);
		}
	}
	else
	{
		frameswitch = 0;
		direction = 0;
		m_Timestamp.SetCurrAnim("SonIdle");
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(elapsedTime);
	}
	if (GetStamina() < 0)
	{
		SetStamina(0);
	}
	if (GetStamina() >= 50)
	{
		SetStamina(50);
	}
	if (GetStamina() <= 33)
	{
		isFlashing = false;
		m_staminastate.green = 168;
		m_staminastate.blue = 168;
	}
	if (GetStamina() <= 17)
	{
		isFlashing = true;
		m_staminastate.green = 0;
		m_staminastate.blue = 0;
	}
	if (GetStamina() == 50)
	{
		isFlashing = false;
		m_staminastate.green = 255;
		m_staminastate.blue = 255;
	}
	else
	{
		if (GetOnGround())
			SetStamina((GetStamina() + 0.06f));
	}
	if (isFlashing)
	{
		if (FlashTimer >= FlashNow)
		{
			FlashTimer = 0.0f;
			if (m_staminastate.alpha == 0)
				m_staminastate.alpha = 255;
			else if (m_staminastate.alpha == 255)
				m_staminastate.alpha = 0;
		}
		FlashTimer += elapsedTime;
	}
	else
		FlashTimer = 0.0f;
	if (GetStamina() >= 33)
		isFlashing = false;

	if (GetCurrCharacter() == false && !isFlashing)
		m_staminastate.alpha = 128;
	else if (GetCurrCharacter() == true && !isFlashing)
		m_staminastate.alpha = 255;

	frameswitch += elapsedTime;
	AnimationSystem::GetInstance()->Update((int)elapsedTime, m_Timestamp);
}

void	 Son::Render(void)
{
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });

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
		SGD::Rectangle re = GetRect();
		re.left -= Game::GetInstance()->GetCameraPosition().x;
		re.right -= Game::GetInstance()->GetCameraPosition().x;
		re.top -= Game::GetInstance()->GetCameraPosition().y;
		re.bottom -= Game::GetInstance()->GetCameraPosition().y;
		SGD::GraphicsManager::GetInstance()->DrawRectangle(re, SGD::Color{ 255, 255, 0, 0 });
	}
	SGD::Point p = m_ptPosition;
	p.x -= Game::GetInstance()->GetCameraPosition().x + GetRect().ComputeWidth() / 2;
	p.y -= Game::GetInstance()->GetCameraPosition().y + GetRect().ComputeHeight() - 3.0f;
	if (!GetCurrCharacter())
	{
		SGD::Rectangle r = { Game::GetInstance()->GetScreenSize().width / 2 + 37.5f, 70, Game::GetInstance()->GetScreenSize().width / 2 + GetStamina() + 37.5f / 2, 77.5 };
		if (GetStamina() > 0 && !r.IsEmpty())
			SGD::GraphicsManager::GetInstance()->DrawRectangle(r, SGD::Color(0, 255, 0));
	}
	else
	{
		SGD::Rectangle r = { p.x, p.y - 50.0f, p.x + GetStamina() / 2, p.y - 42.5f };
		if (GetStamina() > 0 && !r.IsEmpty())
			SGD::GraphicsManager::GetInstance()->DrawRectangle(r, SGD::Color(0, 255, 0));
	}

	if (m_FacingtoRight)
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, SGD::Size{ -0.5f, 0.5f });
	else
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, SGD::Size{ 0.5f, 0.5f });
}

SGD::Rectangle  Son::GetRect(void)	const
{
	SGD::Point p = m_ptPosition;
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, (int)p.x, (int)p.y, SGD::Size{ 0.5f, 0.5f });
}
void Son::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_FATHER && this->GetBackPack())
	{
		this->SetOnGround(false);
		this->SetCurrCharacter(false);
		SGD::Event* event = new SGD::Event("Backpacking", nullptr, this);
		event->QueueEvent();
	}
	if (pOther->GetType() == ENT_SWORDSMAN)
	{
		SGD::Event *event = new SGD::Event("SON_DIED", nullptr, this);
		event->QueueEvent();
	}
	if (pOther->GetType() == ENT_TILES)
	{
		SetCollisionRect(true);
		SGD::Rectangle Rect;
		Rect = this->GetRect().ComputeIntersection(pOther->GetRect());
		if (Rect.ComputeHeight() < GetRect().ComputeHeight())
		{
			if (Rect.left >= this->GetRect().left && Rect.right <= this->GetRect().right)
			{
				letLeft = true;
				letRight = true;
				if (Rect.top == GetRect().top)
				{
					cannotJump = true;
					SetCollisionRect(false);
				}
				else if (Rect.bottom == GetRect().bottom)
				{
					if (Rect.ComputeWidth() < 7.0f)
					{
						SetOnGround(false);
						SetCollisionRect(false);
						cannotJump = false;
						upArrow = false;
						lrArrow = false;
					}
					else
					{
						//set him on the floor and set ground to true
						SetOnGround(true);
						cannotJump = false;
						upArrow = false;
						lrArrow = false;
						m_vtVelocity.y = 0.0f;
						float op = GetRect().bottom - GetPosition().y;
						m_ptPosition.y = Rect.top - op;
						/*if (grounded)
						{
						SGD::Event* event = new SGD::Event("Grounded", nullptr, this);
						event->QueueEvent();
						grounded = false;
						}*/
					}
				}
			}
		}
		if (Rect.ComputeWidth() < this->GetRect().ComputeWidth())
		{
			if (Rect.top >= this->GetRect().top && Rect.bottom <= this->GetRect().bottom)
			{
				m_vtVelocity.x = 0.0f;
				if (GetRect().left == Rect.left)
					letLeft = false;
				else if (GetRect().right == Rect.right)
					letRight = false;
			}
		}
	}
	if (pOther->GetType() == ENT_AUTO_LOCK_DOOR && !dynamic_cast<AutoLockingDoor*>(pOther)->GetOpen())
	{
		SGD::Rectangle Rect;
		Rect = this->GetRect().ComputeIntersection(pOther->GetRect());
		if (Rect.ComputeWidth() < this->GetRect().ComputeWidth())
		{
			if (Rect.top >= this->GetRect().top && Rect.bottom <= this->GetRect().bottom)
			{
				m_vtVelocity.x = 0.0f;
				if (GetRect().left == Rect.left)
					letLeft = false;
				else if (GetRect().right == Rect.right)
					letRight = false;

			}
		}
	}
}
void Son::HandleEvent(const SGD::Event* pEvent)
{


	if (pEvent->GetEventID() == "Death")
	{
		//direction = 0;
		m_Timestamp.SetCurrAnim("SonDeath");
		SetStamina(50);
		//m_Timestamp.SetCurrFrame(direction);
		SGD::Event* event = new SGD::Event("DEATH", nullptr, this);
		event->QueueEvent();
		this->SetPosition(SGD::Point{ (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().left, (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().top });
	}

}
