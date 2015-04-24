#include "Father.h"
#include "Game.h"
#include "Son.h"
#include "AnimationSystem.h"
#include <sstream>
#include "MessageID.h"
#include "CreateSwordMan.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "TileSystem.h"
#include "Box.h"
#include "AutoLockingDoor.h"
#include "BowMan.h"
#include "CreateRollingBoulerMessage.h"
#include "Swordsman.h"
Father::Father()
{
	m_Timestamp.SetOwner(this);
	m_Timestamp.SetCurrAnim("FatherIdle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	SGD::IListener::RegisterForEvent("Death");
	SGD::IListener::RegisterForEvent("Death1");
	SGD::IListener::RegisterForEvent("TargetedByBowman");
	SGD::IListener::RegisterForEvent("UntargetedByBowman");
	SetStamina(200);
	m_RegenStamina = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/staminaregen.wav");
}


Father::~Father()
{
	SGD::AudioManager::GetInstance()->UnloadAudio(m_RegenStamina);
}



void	 Father::Update(float elapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::M))
		spawn = true;
	SGD::Event* event1 = new SGD::Event("THREAT", nullptr, this);
	event1->QueueEvent();
	float x = m_ptPosition.x;
	float y = m_ptPosition.y;
	SGD::Event* event = new SGD::Event("Grounded", nullptr, this);
	event->QueueEvent();
	if (m_Timestamp.GetCurrAnim() != "FatherDeath")
	{
		if (m_ptPosition.x >= 250.0f && !enemy)
		{
			enemy = true;
			CreateSwordMan* pCreateMsg = new CreateSwordMan(this);
			pCreateMsg->QueueMessage();
			pCreateMsg = nullptr;
		}
		if (m_ptPosition.x >= 1200.0f && spawn)
		{
			spawn = false;
			CreateRollingBoulerMessage* pMSG = new CreateRollingBoulerMessage(this);
			pMSG->QueueMessage();
			pMSG = nullptr;
		}
		if (GetCurrCharacter())
		{
			if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::RightArrow) && letRight  && !GameplayState::GetInstance()->GetMovementOff())
			{
				SetFacing(true);
				m_vtVelocity.x = 512.0f;
				letLeft = true;
				if (frameswitch >= 0.07f)
				{
					direction++;
					frameswitch = 0.0f;
				}
				if (direction >= 4)
				{
					direction = 0;
				}
				m_Timestamp.SetCurrAnim("FatherRunning");
				m_Timestamp.SetCurrFrame(direction);
				m_Timestamp.SetElapsedTime(elapsedTime);
			}
			else if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::LeftArrow) && letLeft  && !GameplayState::GetInstance()->GetMovementOff())
			{
				SetFacing(false);
				m_vtVelocity.x = -512.0f;
				letRight = true;
				if (frameswitch >= 0.07f)
				{
					direction++;
					frameswitch = 0.0f;
				}
				if (direction >= 4)
				{
					direction = 0;
				}
				m_Timestamp.SetCurrAnim("FatherRunning");
				m_Timestamp.SetCurrFrame(direction);
				m_Timestamp.SetElapsedTime(elapsedTime);
			}
			else
			{
				direction = 0;
				m_vtVelocity.x = 0.0f;
				m_Timestamp.SetCurrAnim("FatherIdle");
				m_Timestamp.SetCurrFrame(direction);
				m_Timestamp.SetElapsedTime(elapsedTime);
			}
			//Jump
			if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && !GameplayState::GetInstance()->GetMovementOff())
			{
				if (GetStamina() >= 10)
				{
					if (GetOnGround() || GetHanging())
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

					//grounded = true;
				}
			}
			if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && GetonLadder() && !GameplayState::GetInstance()->GetMovementOff())
			{
				previousPosY = m_ptPosition.y;
				m_vtVelocity.y = 512.0f;
				upArrow = false;
			}

			if (GetOnGround())//ground level -100
			{
				upArrow = false;
				if (timeinair >= 3.5f)
				{
					SGD::Event* CannonBallHit = new SGD::Event("Death1", nullptr, this);
					CannonBallHit->QueueEvent();
				}
				timeinair = 0.0f;
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
			if (GetOnGround() && GetonLadder())
			{
				if (m_ptPosition.y <= previousPosY - 50.0f && upArrow)
					SetVelocity({ 0.0f, 0.0f });
				if (m_ptPosition.y >= previousPosY + 50.0f && !upArrow)
					SetVelocity({ 0.0f, 0.0f });
			}

			if (!GetOnGround() && cannotJump == true)
			{
				m_vtVelocity.y = 512.0f;
				cannotJump = false;
			}
			if (m_vtVelocity.y > 0 && GetjumpOffLedge())
				SetjumpOffLedge(false);
			//frameswitch += elapsedTime;
		}
		else if (!GetCurrCharacter())
		{
			m_vtVelocity.x = 0.0f;
			direction = 0;
			m_Timestamp.SetCurrAnim("FatherIdle");
			m_Timestamp.SetCurrFrame(direction);
			m_Timestamp.SetElapsedTime(elapsedTime);
			if (!GetOnGround() && upArrow == true)//ground level -100
			{
				if (m_vtVelocity.y < 0)
					m_vtVelocity.y += 2.0f;
				else
					m_vtVelocity.y = 128.0f;
			}
			if (GetOnGround())
			{
				upArrow = false;
			}
		}
	}
	else
	{
		direction = 0;
		m_Timestamp.SetCurrAnim("FatherIdle");
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(elapsedTime);
	}
	if (GetStamina() < 0)
	{
		SetHanging(false);
		SetStamina(0);
	}
	if (GetStamina() >= 200)
		SetStamina(200);
	else
	{
		if (GetOnGround())
		{
			SetStamina(GetStamina() + 0.6f);
			if (GetStamina() < 100 && !SGD::AudioManager::GetInstance()->IsAudioPlaying(m_RegenStamina))
			{
				SGD::AudioManager::GetInstance()->PlayAudio(m_RegenStamina);
			}

		}
		else
		{
			SGD::AudioManager::GetInstance()->StopAudio(m_RegenStamina);
		}
	}
	if (GetHanging() && GetOnGround() == false)
		SetStamina(GetStamina() - 0.5f);
	if (GetStamina() <= 75)
	{
		m_staminastate.green = 168;
		m_staminastate.blue = 168;
	}
	if (GetStamina() <= 25)
	{
		isFlashing = true;
		m_staminastate.green = 0;
		m_staminastate.blue = 0;
	}
	if (GetStamina() == 100)
	{
		isFlashing = false;
		m_staminastate.green = 255;
		m_staminastate.blue = 255;
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
	if (GetStamina() >= 75)
		isFlashing = false;

	if (GetCurrCharacter() == false && !isFlashing)
		m_staminastate.alpha = 128;
	else if (GetCurrCharacter() == true && !isFlashing)
		m_staminastate.alpha = 255;
	frameswitch += elapsedTime;
	if (GetOnGround() == false && GetHanging() == false)
	{
		direction = 0;
		m_Timestamp.SetCurrAnim("FatherJump");
		m_Timestamp.SetCurrFrame(direction);
		m_Timestamp.SetElapsedTime(elapsedTime);
		timeinair += elapsedTime;
	}
	Actor::Update(elapsedTime);
	AnimationSystem::GetInstance()->Update((int)elapsedTime, m_Timestamp);
}

void	 Father::Render(void)
{
	//SGD::Rectangle frame = frames[direction].rFrame;
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });
#pragma region This Region is For Debug Mode Use F3 To see the Collision Rect
	//SGD::Rectangle frame = frames[direction].rFrame;
	//SGD::GraphicsManager::GetInstance()->DrawTextureSection(m_hImage, SGD::Point{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y }, {0,0,64,64});
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
	//SGD::GraphicsManager::GetInstance()->DrawRectangle(GetRect(), SGD::Color{ 255, 255, 0, 0 });

#pragma endregion
	SGD::Point p = m_ptPosition;
	p.x -= Game::GetInstance()->GetCameraPosition().x;
	p.y -= Game::GetInstance()->GetCameraPosition().y;
	//int x = Game::GetInstance()->GetScreenSize().width / 2;
	//int x2 = p.x;
	//int ri = Game::GetInstance()->GetScreenSize().width / 2 + GetStamina() - 25.0f;
	//int ri2 = p.x + GetStamina();
	if (!GetCurrCharacter())
	{
		SGD::Rectangle r = { Game::GetInstance()->GetScreenSize().width / 2 - 25.0f, 70, Game::GetInstance()->GetScreenSize().width / 2 + GetStamina()/4 - 25.0f, 77.5 };
		if (GetStamina() > 0 && !r.IsEmpty())
			SGD::GraphicsManager::GetInstance()->DrawRectangle(r, SGD::Color(255, 255, 0));
	}
	else
	{
		SGD::Rectangle r = { p.x, p.y - 80.0f, p.x + GetStamina()/4, p.y - 72.5f };
		if (GetStamina() > 0 && !r.IsEmpty())
			SGD::GraphicsManager::GetInstance()->DrawRectangle(r, SGD::Color(255, 255, 0));
	}
	if (GetFacing())
		AnimationSystem::GetInstance()->Render(m_Timestamp, p.x, p.y, SGD::Size{ -1, 1 });
	else
		AnimationSystem::GetInstance()->Render(m_Timestamp, p.x, p.y, SGD::Size{ 1, 1 });
}

SGD::Rectangle  Father::GetRect(void)	const
{
	SGD::Point p = m_ptPosition;
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, p.x, p.y);
}

void Father::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_SON)
	{
		this->SetCurrCharacter(true);
		dynamic_cast<Son*>(pOther)->SetBackPack(true);
	}
	if (pOther->GetType() == ENT_LEDGE && dynamic_cast<Ledges*>(pOther)->isBig && !GetjumpOffLedge())
	{
		SGD::Rectangle Rect = this->GetRect().ComputeIntersection(pOther->GetRect());
		letLeft = true;
		letRight = true;
		if (Rect.ComputeWidth() > 14.0f)
		{
			if (GetStamina() > 5)
			{
				previousPosY = m_ptPosition.y;
				m_ptPosition.y = pOther->GetRect().bottom;
				m_vtVelocity.y = 0.0f;
				SetOnGround(false);
				SetHanging(true);
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
					SetVelocity({ -128.0f, 0.0f });
					dynamic_cast<Box*>(pOther)->CalculateVelocity(GetVelocity());
					SetVelocity(dynamic_cast<Box*>(pOther)->GetVelocity());
					letLeft = false;
				}
				else if (GetRect().right == Rect.right)
				{
					SetVelocity({ 128.0f, 0.0f });
					dynamic_cast<Box*>(pOther)->CalculateVelocity(GetVelocity());
					SetVelocity(dynamic_cast<Box*>(pOther)->GetVelocity());
					letRight = false;
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
						SetOnGround(true);
						cannotJump = false;
						upArrow = false;
						m_vtVelocity.y = 0.0f;
						int op = (int)GetRect().bottom - (int)GetPosition().y;
						int s = (int)pOther->GetRect().top - op;
						m_ptPosition.y = (float)s;
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
	if (pOther->GetType() == ENT_LADDER)
	{
		SGD::Rectangle Rect;
		Rect = this->GetRect().ComputeIntersection(pOther->GetRect());
		if (Rect.ComputeWidth() > 15.0f)
		{
			//bool k = letRight;
			SetonLadder(true);
			//m_ptPosition.y = Rect.top;
			SetOnGround(true);
		}
	}

}

void Father::HandleEvent(const SGD::Event* pEvent)
{
	if (pEvent->GetEventID() == "Death")
	{
		direction = 0;
		SetStamina(100);
		m_Timestamp.SetCurrAnim("FatherDeath");
		SGD::Event* event = new SGD::Event("DEATH", nullptr, this);
		event->QueueEvent();
		SetPosition(GetCheckPoint());
		//m_Timestamp.SetCurrFrame(direction);

	}
	if (pEvent->GetEventID() == "Death1")
	{
		direction = 0;
		SetStamina(100);
		m_Timestamp.SetCurrAnim("FatherDeath");
		SGD::Event* event = new SGD::Event("DEATH", nullptr, this);
		event->QueueEvent();
		//		SetPosition(SGD::Point{ (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[1]->GetRect().left - 400, (float)GameplayState::GetInstance()->GetTileSystem()->m_CheckPoints[1]->GetRect().top - 300 });
		//m_Timestamp.SetCurrFrame(direction);

	}

	if (pEvent->GetEventID() == "TargetedByBowman")
	{
		if (reinterpret_cast<Actor*>(pEvent->GetSender())->GetType() == ENT_BOWMAN)
		{
			if (reinterpret_cast<BowMan*>(pEvent->GetSender())->GetEnemyTarget()->GetType() == ENT_FATHER)
			{
				Targeted = true;
			}
		}
		if (reinterpret_cast<Actor*>(pEvent->GetSender())->GetType() == ENT_SWORDSMAN)
		{
			if (reinterpret_cast<Swordsman*>(pEvent->GetSender())->GetEnemyTarget()->GetType() == ENT_FATHER)
			{
				Targeted = true;
			}
		}
	}
	if (pEvent->GetEventID() == "UntargetedByBowman")
	{
		Targeted = false;
	}

}