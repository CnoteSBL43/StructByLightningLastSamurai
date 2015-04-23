#include "Swordsman.h"
#include "Game.h"
#include "Son.h"
#include <sstream>
//#include "AnimationSystem.h"
Swordsman::Swordsman()
{
	m_Timestamp.SetCurrAnim("SwordsmanIdle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
	//CreateFrames();
	SGD::IListener::RegisterForEvent("THREAT");
	m_AlertedImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/alerted.png");

}


Swordsman::~Swordsman()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_AlertedImage);
}

void	 Swordsman::Update(float elapsedTime)
{

	if (m_Target != nullptr)
	{
		SGD::Vector EnemyDistance = m_ptPosition - GetEnemyTarget()->GetPosition();


		if (m_Target->GetPosition().x < m_ptPosition.x)
		{
			m_facingRight = false;
			m_vtVelocity.x = -128.0f;
		}
		else if (m_Target->GetPosition().x > m_ptPosition.x)
		{
			m_facingRight = true;
			m_vtVelocity.x = 128.0f;
		}

		if (EnemyDistance.ComputeLength() > 300)
		{
			SetTarget(nullptr);
			SGD::Event* event = new SGD::Event("UntargetedByBowman", nullptr, this);
			event->QueueEvent();
			AlertTimer = 4.0f;
			ChangeFaceTimer = 1.0f;
			isAlerted = true;
			//m_ptPosition = m_Original;

			if (EnemyDistance.ComputeLength() <= 20)
			{
				m_vtVelocity.x -= 2.0f;
				if (EnemyDistance.x <= 0)
				{
					m_vtVelocity.x = 0.0f;
					m_Timestamp.SetCurrAnim("SwordsmanAttack");
				}
			}
		}
	}

	if (isAlerted == true)
	{
		m_Timestamp.SetCurrAnim("SwordsmanIdle");
		AlertTimer -= elapsedTime;
		ChangeFaceTimer -= elapsedTime;
		if (AlertTimer <= 0.0f)
		{
			AlertTimer = 4.0f;
			isAlerted = false;
			if (m_facingRight)
			{
				toRight = true;
				toLeft = false;
			}
			else
			{
				toRight = false;
				toLeft = true;
			}

		}
		if (ChangeFaceTimer <= 0.0f)
		{
			ChangeFaceTimer = 1.0f;
			m_facingRight = !m_facingRight;
		}
		m_vtVelocity.x = 0;
	}
	else
	{
		if (m_Target == nullptr)
		{
			if (toRight)
			{
				SetDestination(m_ptPosition.x + 256.0f);
				m_vtVelocity.x = 64.0f;
				toRight = false;
			}
			if (m_ptPosition.x >= destination && !toLeft)
			{
				m_facingRight = false;
				m_vtVelocity.x = -64.0f;
				SetDestination(GetDestination() - 256.0f);
				toLeft = true;
			}
			if (toRight == false && toLeft && m_ptPosition.x <= destination)
			{
				m_facingRight = true;
				toRight = true;
				toLeft = false;
				m_vtVelocity.x = 64.0f;
			}
		}
	}
	//SGD::GraphicsManager::GetInstance()->DrawLine(SGD::Point{m_ptPosition.x,destination},)
	frameswitch += elapsedTime;
	Actor::Update(elapsedTime);
}

void	 Swordsman::Render(void)
{


	//SGD::Rectangle frame = frames[direction].rFrame;
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false)
		Debug = true;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true)
		Debug = false;
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
	p.x -= Game::GetInstance()->GetCameraPosition().x;
	p.y -= Game::GetInstance()->GetCameraPosition().y;

	if (isAlerted)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_AlertedImage, { p.x, p.y - 170.0f });
	}

	if (m_Target != nullptr)
	{
		SGD::GraphicsManager::GetInstance()->DrawLine(p, { m_Target->GetPosition().x - Game::GetInstance()->GetCameraPosition().x, m_Target->GetPosition().y - Game::GetInstance()->GetCameraPosition().y - 32 });
	}
	if (m_facingRight)
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, { -1, 1 });
	else
		AnimationSystem::GetInstance()->Render(m_Timestamp, (int)p.x, (int)p.y, { 1, 1 });
}

SGD::Rectangle  Swordsman::GetRect(void)	const
{
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, (int)m_ptPosition.x, (int)m_ptPosition.y, { 1, 1 });//SGD::Rectangle(SGD::Point{ m_ptPosition.x - Game::GetInstance()->GetCameraPosition().x - 54.0f, m_ptPosition.y - Game::GetInstance()->GetCameraPosition().y + 6.0f }, SGD::Size{ 45, 99 });
}

void Swordsman::HandleCollision(IEntity* pOther)
{
	if (pOther->GetType() == ENT_SON || pOther->GetType() == ENT_FATHER)
	{

	}
}

void Swordsman::HandleEvent(const SGD::Event* pEvent)
{
	if (pEvent->GetEventID() == "THREAT")
	{
		if (m_Target == nullptr)
		{
			SGD::Vector NewThreat = reinterpret_cast<Player*>(pEvent->GetSender())->GetPosition() - this->GetPosition();
			if (NewThreat.ComputeLength() < 150)
			{
				SetTarget(reinterpret_cast<Player*>(pEvent->GetSender()));
				SGD::Event* event = new SGD::Event("TargetedByBowman", nullptr, this);
				event->QueueEvent();
			}
		}


	}

}