#include "Son.h"
#include "Game.h"
#include "Father.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "GameplayState.h"
#include "TileSystem.h"
#include"AutoLockingDoor.h"
#include "Box.h"
Son::Son()
{
	m_Timestamp.SetCurrAnim("SonIdle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
	//SetPosition(SGD::Point{ 100.0f, 200.0f });
	//CreateFrames();
	SGD::IListener::RegisterForEvent("Death");
	SetStamina(100);
	m_SonJump = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/Jump.wav");
	SonLanding = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/Land.wav");
	SonStaimadrained = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/staminabeingdrained.wav");
	SonOutOfstamina = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/ranoutofstamina.wav");
	LowStamina = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/lowstamina.wav");
	RegeneratingStamina = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/regeneratingstamina.wav");
	PushBoxSound = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/movecrate.mp3");
	ClimbLadder = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/movingacrossledgeandclimbingladderandropetension.wav");
}



Son::~Son()
{
}

void	 Son::Update(float elapsedTime)
{
	if (m_Timestamp.GetCurrAnim() != "SonDeath")
	{
		SGD::Event* event = new SGD::Event("THREAT", nullptr, this);
		event->QueueEvent();
		if (GetCurrCharacter())
		{
			if (GetBackPack())
				m_vtVelocity.y = 0.0f;
			if ((SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow) || SGD::InputManager::GetInstance()->IsDPadDown(0, SGD::DPad::Right)) && letRight && !GameplayState::GetInstance()->GetMovementOff())
			{
				SetFacing(true);
				m_vtVelocity.x = 128.0f;
				if (GetBackPack())
					lrArrow = true;
				letLeft = true;
				if (GetHanging() == false && GetonLadder() == false)
				{
					if (frameswitch >= 0.07f)
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
					if (frameswitch >= 0.1f)
					{
						direction++;
					}
					if (direction >= 1)
					{
						direction = 0;
					}
				}
			}
			else if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::LeftArrow) && letLeft || SGD::InputManager::GetInstance()->IsDPadDown(0, SGD::DPad::Left) && letRight && !GameplayState::GetInstance()->GetMovementOff())
			{
				SetFacing(false);
				m_vtVelocity.x = -128.0f;
				if (GetBackPack())
					lrArrow = true;
				letRight = true;
				if (GetHanging() == false && GetonLadder() == false)
				{
					if (frameswitch >= 0.07f)
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
					if (frameswitch >= 0.1f)
					{
						direction++;
					}
					if (direction >= 1)
					{
						direction = 0;
					}
				}
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
			if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && !GameplayState::GetInstance()->GetMovementOff() || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && !cannotJump  && !GameplayState::GetInstance()->GetMovementOff())
			{
				SGD::AudioManager::GetInstance()->PlayAudio(m_SonJump);
				Landing = true;
				if (GetStamina() >= 10)
				{
					if (GetHanging())
					{
						SetStamina(GetStamina() - 10);
						previousPosY = m_ptPosition.y;
						SetOnGround(false);
						upArrow = true;
						m_vtVelocity.y = -800.0f;
						SetHanging(false);
						SetjumpOffLedge(true);
					}
					if (GetOnGround())
					{
						SetStamina(GetStamina() - 10);
						previousPosY = m_ptPosition.y;
						SetOnGround(false);
						upArrow = true;
						SetjumpOffLedge(false);
						SetHanging(false);
						m_vtVelocity.y = -800.0f;
					}
					if (GetBackPack())
					{
						SetStamina(GetStamina() - 10);
						previousPosY = m_ptPosition.y;
						m_vtVelocity.y = -400.0f;
						SetBackPack(false);
						upArrow = true;
					}
					//grounded = true;
				}
			}
			if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && GetonLadder() && !GameplayState::GetInstance()->GetMovementOff())
			{
				previousPosY = m_ptPosition.y;
				m_vtVelocity.y = 512.0f;
				upArrow = false;
			}
			if (GetOnGround() && GetonLadder())
			{
				if (m_ptPosition.y <= previousPosY - 32.0f && upArrow)
				{
					m_vtVelocity.y = 0.0f;
					upArrow = false;
				}
				if (m_ptPosition.y >= previousPosY + 32.0f && !upArrow)
				{
					m_vtVelocity.y = 0.0f;
					upArrow = false;
				}
			}
			if (!GetOnGround() && upArrow == true && !GetHanging() && !GetonLadder())
			{
				if (m_vtVelocity.y < 0)
					m_vtVelocity.y += 24.0f;
				else if (m_vtVelocity.y >= 0 && m_vtVelocity.y < 512.0f)
					m_vtVelocity.y += 36.0f;
				else
					m_vtVelocity.y = 512.0f;
			}

			if (!GetOnGround() && cannotJump == true)
			{
				m_vtVelocity.y = 512.0f;
				cannotJump = false;
			}
			if (m_vtVelocity.y > 0 && GetjumpOffLedge())
				SetjumpOffLedge(false);

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
				if (m_vtVelocity.y < 0)
					m_vtVelocity.y += 24.0f;
				else if (m_vtVelocity.y >= 0 && m_vtVelocity.y < 512.0f)
					m_vtVelocity.y += 36.0f;
				else
					m_vtVelocity.y = 512.0f;
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
	if (GetStamina() >= 100)
	{
		SetStamina(100);
	}
	if (GetStamina() <= 66)
	{
		isFlashing = false;
		m_staminastate.green = 168;
		m_staminastate.blue = 168;
	}
	if (GetStamina() <= 33)
	{
		isFlashing = true;
		m_staminastate.green = 0;
		m_staminastate.blue = 0;
		if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(LowStamina))
		{
			SGD::AudioManager::GetInstance()->PlayAudio(LowStamina);
		}
	}
	if (GetStamina() == 100)
	{
		isFlashing = false;
		m_staminastate.green = 255;
		m_staminastate.blue = 255;
	}
	else
	{
		if (GetOnGround())
		{
			SetStamina((GetStamina() + 0.06f));
			if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(RegeneratingStamina))
			{
				SGD::AudioManager::GetInstance()->PlayAudio(RegeneratingStamina);
			}
		}

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
	if (GetHanging() == true || GetonLadder() == true)
	{
		direction = 0;
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(0);
		m_Timestamp.SetCurrAnim("SonClimbing");
	}
	if (!GetOnGround() && !GetHanging())
	{
		direction = 0;
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(0);
		m_Timestamp.SetCurrAnim("SonJump");
	}
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
	p.y -= Game::GetInstance()->GetCameraPosition().y + GetRect().ComputeHeight() - 14.0f;
	SGD::Rectangle r = { p.x, p.y - 50.0f, p.x + GetStamina() / 2, p.y - 42.5f };
	if (!GetCurrCharacter())
	{
		SGD::Rectangle r = { Game::GetInstance()->GetScreenSize().width / 2 + 37.5f, 70, Game::GetInstance()->GetScreenSize().width / 2 + GetStamina() / 4 + 37.5f, 77.5 };
		if (GetStamina() > 0 && !r.IsEmpty())
			SGD::GraphicsManager::GetInstance()->DrawRectangle(r, SGD::Color(255, 255, 0));
	}
	else
	{
		SGD::Rectangle r = { p.x, p.y - 50.0f, p.x + GetStamina() / 4, p.y - 42.5f };
		if (GetStamina() > 0 && !r.IsEmpty())
			SGD::GraphicsManager::GetInstance()->DrawRectangle(r, SGD::Color(255, 255, 0));
	}
	if (GetBackPack() == false)
	{
		if (GetFacing())
			AnimationSystem::GetInstance()->Render(m_Timestamp, p.x, p.y, SGD::Size{ -0.5f, 0.5f });
		else
			AnimationSystem::GetInstance()->Render(m_Timestamp, p.x, p.y, SGD::Size{ 0.5f, 0.5f });
	}
}

SGD::Rectangle  Son::GetRect(void)	const
{
	SGD::Point p = m_ptPosition;
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, p.x, p.y, SGD::Size{ 0.5f, 0.5f });

}
void Son::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_LADDER)
	{
		SGD::Rectangle Rect;
		Rect = this->GetRect().ComputeIntersection(pOther->GetRect());
		if (Rect.ComputeWidth() == GetRect().ComputeWidth())
		{
			SetonLadder(true);
			//m_ptPosition.y = Rect.top;
			SetOnGround(true);
			if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(ClimbLadder))
			{
				SGD::AudioManager::GetInstance()->PlayAudio(ClimbLadder);
			}

		}
		if (Rect.ComputeHeight() <= 32.0f)
		{
			SetonLadder(false);
			SetOnGround(false);
		}


	}
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
	if (pOther->GetType() == ENT_LEDGE && !GetjumpOffLedge())
	{
		SGD::Rectangle Rect = this->GetRect().ComputeIntersection(pOther->GetRect());
		letLeft = true;
		letRight = true;
		if (Rect.ComputeWidth() > 7.0f)
		{
			if (GetStamina() > 5)
			{
				previousPosY = m_ptPosition.y;
				m_ptPosition.y = pOther->GetRect().bottom + 20.0f;
				m_vtVelocity.y = 0.0f;
				SetOnGround(false);
				SetHanging(true);
				if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(SonStaimadrained))
				{
					SGD::AudioManager::GetInstance()->PlayAudio(SonStaimadrained);
				}
			}
		}
	}
	if (pOther->GetType() == ENT_TILES && !GetHanging())
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
						int op = (int)GetRect().bottom - (int)GetPosition().y;
						int s = (int)pOther->GetRect().top - op;
						m_ptPosition.y = (float)s;
						if (Landing)
						{
							SGD::AudioManager::GetInstance()->PlayAudio(SonLanding);
							Landing = false;
						}
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
	if (pOther->GetType() == ENT_BOX)
	{
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
					//set him on the floor and set ground to true
					if (Rect.ComputeWidth() < 7.0f)
					{
						SetOnGround(false);
						SetCollisionRect(false);
						cannotJump = false;
						upArrow = false;
					}
					else
					{
						cannotJump = false;
						upArrow = false;
						m_vtVelocity.y = 0.0f;
						float op = GetRect().bottom - GetPosition().y;
						m_ptPosition.y = pOther->GetRect().top - op;
						SetOnGround(true);
						if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(PushBoxSound))
						{
							SGD::AudioManager::GetInstance()->PlayAudio(PushBoxSound);
						}

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
				{
					if (!dynamic_cast<Box*>(pOther)->GetHeavy())
					{
						SetVelocity({ -128.0f, 0.0f });
						dynamic_cast<Box*>(pOther)->CalculateVelocity(GetVelocity());
						SetVelocity(dynamic_cast<Box*>(pOther)->GetVelocity());
					}
					letLeft = false;
				}
				else if (GetRect().right == Rect.right)
				{
					if (!dynamic_cast<Box*>(pOther)->GetHeavy())
					{
						SetVelocity({ 128.0f, 0.0f });
						dynamic_cast<Box*>(pOther)->CalculateVelocity(GetVelocity());
						SetVelocity(dynamic_cast<Box*>(pOther)->GetVelocity());
					}
					letRight = false;
				}

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
		//this->SetPosition(SGD::Point{ (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().left, (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().top });
		//SetPosition(SGD::Point{ (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().left - 380, (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[0]->GetRect().top - 300 });
	}

}
