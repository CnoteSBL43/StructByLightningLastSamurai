#include "GameplayState.h"
#include"Father.h"
#include "Game.h"
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
		father->SetSize(SGD::Size{ -1.5f, 1.5f });
		father->SetVelocity({ 0.2f, 0.0f });
		return father;
}

void GameplayState::Enter()
{
	m_FatherImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Father.png");
	m_pEntities = new EntityManager;
	m_player = CreateFather();
	m_pEntities->AddEntity(m_player,0);
	m_player->Release();
}


void GameplayState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherImage);
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
	m_pEntities->UpdateAll(_ElapsedTime);
	return true;
}


void GameplayState::Render(float _ElapsedTime)
{
	m_pEntities->RenderAll();
}
