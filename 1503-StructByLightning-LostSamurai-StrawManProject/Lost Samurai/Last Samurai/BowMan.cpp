#include "BowMan.h"
#include "Game.h"
#include "../SGD Wrappers/SGD_Event.h"
#include "../SGD Wrappers/SGD_EventManager.h"
#include "../SGD Wrappers/SGD_IListener.h"
#include "CreateArrowMessage.h"
#include "../SGD Wrappers/SGD_MessageManager.h"
BowMan::BowMan()
{
	m_Timestamp.SetCurrAnim("ArcherIdle");
	m_Timestamp.SetCurrFrame(0);
	m_Timestamp.SetElapsedTime(0);
	m_Timestamp.SetOwner(this);
	SGD::IListener::RegisterForEvent("THREAT");
	m_AlertedImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/alerted.png");

}


BowMan::~BowMan()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_AlertedImage);
}


void BowMan::Render(void)
{
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

	SGD::Point pt = GetPosition();
	pt.x -= Game::GetInstance()->GetCameraPosition().x;
	pt.y -= Game::GetInstance()->GetCameraPosition().y;
	if (m_Target != nullptr)
	{
		SGD::GraphicsManager::GetInstance()->DrawLine(pt, { m_Target->GetPosition().x - Game::GetInstance()->GetCameraPosition().x, m_Target->GetPosition().y - Game::GetInstance()->GetCameraPosition().y - 32 });
	}
	else
	{
		SGD::GraphicsManager::GetInstance()->DrawLine(pt, { m_Wander.x - Game::GetInstance()->GetCameraPosition().x, m_Wander.y - Game::GetInstance()->GetCameraPosition().y });
	}


	if (isAlerted)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_AlertedImage, { pt.x, pt.y - 170.0f });
	}

	if (m_facingRight == true)
		AnimationSystem::GetInstance()->Render(m_Timestamp, pt.x, pt.y, { -1, 1 });
	else
		AnimationSystem::GetInstance()->Render(m_Timestamp, pt.x, pt.y, { 1, 1 });


}
void BowMan::Update(float _elapsedtime)
{
	SGD::Vector Differnt;
	SGD::Point temp;
	temp.x = 600;
	temp.y = 250;
	if (m_Target != nullptr)
	{
		SGD::Vector EnemyDistance = m_ptPosition - GetEnemyTarget()->GetPosition();
		if (EnemyDistance.ComputeLength() > 300)
		{
			SetTarget(nullptr);
			SGD::Event* event = new SGD::Event("UntargetedByBowman", nullptr, this);
			event->QueueEvent();
			AlertTimer = 4.0f;
			ChangeFaceTimer = 1.0f;
			isAlerted = true;
			m_ptPosition = temp;
		}
		if (EnemyDistance.ComputeLength() <= 100)
		{
			m_vtVelocity.x -= 2.0f;
			if (EnemyDistance.x <= 0)
				m_vtVelocity.x = 0.0f;
			if (m_Timer <= 0)
			{
				CreateArrowMessage* m_Cannonball = new CreateArrowMessage(reinterpret_cast<DartCannon*>(this));
				SGD::MessageManager::GetInstance()->QueueMessage(m_Cannonball);
				m_Cannonball = nullptr;
				m_Timer = 3.0;
			}
		}
	}
	if (isAlerted == true)
	{
		AlertTimer -= _elapsedtime;
		ChangeFaceTimer -= _elapsedtime;
		if (AlertTimer <= 0.0f)
		{
			AlertTimer = 4.0f;
			isAlerted = false;
		}
		if (ChangeFaceTimer <= 0.0f)
		{
			ChangeFaceTimer = 1.0f;
			m_facingRight = !m_facingRight;
		}
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
	m_Timer -= _elapsedtime;
	Actor::Update(_elapsedtime);
}



SGD::Rectangle BowMan::GetRect()const
{
	return AnimationSystem::GetInstance()->GetRect(m_Timestamp, m_ptPosition.x, m_ptPosition.y, { 1, 1 });
}

int	 BowMan::GetType(void)	const
{
	return ENT_BOWMAN;
}

void BowMan::HandleCollision(IEntity* pOther)
{


}


void BowMan::HandleEvent(const SGD::Event* pEvent)
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