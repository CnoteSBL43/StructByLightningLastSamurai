#include "GameplayState.h"
#include"Father.h"
#include "Game.h"
#include "Son.h"
#include "Actor.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include"MainMenuState.h"
#include "EntityManager.h"
GameplayState* GameplayState::GetInstance()
{
	static GameplayState m_Instance;
	return &m_Instance;
}

Actor* GameplayState::CreateFather(void)
{
		Player* father = new Father;
		father->SetPosition(SGD::Point{ 100.0f, 480.0f });
		father->SetAlive(true);
		father->SetImage(m_FatherImage);
		father->SetSize(SGD::Size{ -1.5f,1.5f });
		father->SetVelocity({ 0.0f, 0.0f });
		return father;
}

Actor* GameplayState::CreateSon(void)
{
	Player* son = new Son;
	son->SetPosition(SGD::Point{ 700.0f, 480.0f });
	son->SetAlive(true);
	son->SetImage(m_FatherImage);
	son->SetSize(SGD::Size{ -0.5f, 0.5f });
	son->SetVelocity({ 0.0f, 0.0f });
	return son;
}
void GameplayState::Enter()
{
	m_BgImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/bg.jpg");
	m_FatherImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Father.png");
	m_pEntities = new EntityManager;
	father = CreateFather();
	m_pEntities->AddEntity(father, 0);
	son = CreateSon();
	m_pEntities->AddEntity(son, 0);
//	Game::GetInstance()->SetCameraPosition({ father->GetPosition().x, father->GetPosition().y });
}


void GameplayState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_BgImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherImage);
	father->Release();
	father = nullptr;
	son->Release();
	son = nullptr;
	if (m_pEntities != nullptr)
	{
		m_pEntities->RemoveAll();
		delete m_pEntities;
		m_pEntities = nullptr;
	}
}

bool GameplayState::Update(float _ElapsedTime)
{
	

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::J))
	{
		if (dynamic_cast<Father*>(father)->GetCurrCharacter())
		{
			dynamic_cast<Father*>(father)->SetCurrCharacter(false);
			dynamic_cast<Son*>(son)->SetCurrCharacter(true);
		}
		else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
		{
			dynamic_cast<Father*>(father)->SetCurrCharacter(true);
			dynamic_cast<Son*>(son)->SetCurrCharacter(false);
		}
	}
	m_pEntities->UpdateAll(_ElapsedTime);
	if (dynamic_cast<Father*>(father)->GetCurrCharacter())
	{
		Game::GetInstance()->SetCameraPosition(SGD::Point{ father->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, father->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

	}
	else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
	{
		Game::GetInstance()->SetCameraPosition(SGD::Point{ son->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, son->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

	}
	return true;
}


void GameplayState::Render(float _ElapsedTime)
{
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_BgImage,
		SGD::Point{ 0 - Game::GetInstance()->GetCameraPosition().x, 0 - Game::GetInstance()->GetCameraPosition().y });
	m_pEntities->RenderAll();
}
