#include "GameplayState.h"
#include"Father.h"
#include "Game.h"
#include "Son.h"
#include "Swordsman.h"
#include "Actor.h"
#include "SaveGameState.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Message.h"
#include"MainMenuState.h"
#include "Message.h"
#include "EntityManager.h"
#include"../Last Samurai/TileSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include "AnimationSystem.h"


GameplayState* GameplayState::GetInstance()
{
	static GameplayState m_Instance;
	return &m_Instance;
}



Actor* GameplayState::CreateFather(void)
{
	Player* father = new Father;
	//father->SetPosition(SGD::Point{ 500.0f, 480.0f });
	father->SetAlive(true);
	//father->SetImage(m_FatherImage);
	father->SetSize(SGD::Size{ 64.0f, 64.0f });
	father->SetVelocity({ 0.0f, 0.0f });
	return father;
}

Actor* GameplayState::CreateSon(void)
{
	Player* son = new Son;
	son->SetPosition(SGD::Point{ 600.0f, 540.0f });
	son->SetAlive(true);
	son->SetImage(m_FatherImage);
	son->SetSize(SGD::Size{ 32.0f, 32.0f });
	son->SetVelocity({ 0.0f, 0.0f });
	return son;
}
Actor* GameplayState::CreateSwordsman(void)
{
	Player* swordsman = new Swordsman;
	swordsman->SetPosition(SGD::Point{ 100.0f, 540.0f });
	swordsman->SetAlive(true);
	swordsman->SetImage(m_FatherImage);
	swordsman->SetSize(SGD::Size{ -1.5f, 1.5f });
	swordsman->SetVelocity({ 64.0f, 0.0f });
	return swordsman;
}
void GameplayState::Enter()
{
	

	m_FatherImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Father.png");
	m_PauseImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Pause.png");
	m_PointerImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Finger.png");
	m_pEntities = new EntityManager;
	m_ParticleManager = new ParticleManager;
	AnimationSystem::GetInstance()->Load("../anim.xml");
	//AnimationSystem::GetInstance()->Load("../anim2.xml");
	father = CreateFather();
	father->SetPosition({ 200, 540 });
	m_pEntities->AddEntity(father, 0);
	son = CreateSon();
	m_pEntities->AddEntity(son, 1);
	swordsman = CreateSwordsman();
	m_pEntities->AddEntity(swordsman, 2);
	Load = new TileSystem();
	Load->LoadTileXml();
}


void GameplayState::Exit()
{
	AnimationSystem::GetInstance()->Exit();
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_PointerImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_PauseImage);

	m_Pause = false;
	cursorPos = 0;
	father->Release();
	father = nullptr;
	son->Release();
	son = nullptr;
	swordsman->Release();
	swordsman = nullptr;
	delete m_ParticleManager;
	if (m_pEntities != nullptr)
	{
		m_pEntities->RemoveAll();
		delete m_pEntities;
		m_pEntities = nullptr;
		delete Load;
	}
}

bool GameplayState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		if (!m_Pause)
			m_Pause = true;
		else
			m_Pause = false;
	}
	if (m_Pause)
		Pause();
	else
	{
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
		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::K) && dynamic_cast<Father*>(father)->GetCurrCharacter() && !dynamic_cast<Father*>(father)->GetBackPack())
		{
			m_pEntities->CheckCollisions(0, 1);
		}
		if (dynamic_cast<Father*>(father)->GetCurrCharacter())
		{
			Game::GetInstance()->SetCameraPosition(SGD::Point{ father->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, father->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

		}
		else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
		{
			Game::GetInstance()->SetCameraPosition(SGD::Point{ son->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, son->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

		}
		//replace son after backpacing is activated
		if (dynamic_cast<Son*>(son)->GetBackPack())
		{
			dynamic_cast<Son*>(son)->SetFacing(dynamic_cast<Father*>(father)->GetFacing());
			dynamic_cast<Son*>(son)->SetPosition(SGD::Point{ dynamic_cast<Father*>(father)->GetPosition().x - 16.0f, dynamic_cast<Father*>(father)->GetPosition().y - 16.0f });
		}

		m_pEntities->UpdateAll(_ElapsedTime);
		m_pEntities->CheckCollisions(0, 2);//handle collision between father and swordsman
		m_pEntities->CheckCollisions(1, 2);//handle collision between son and swordsman

	}
	return true;
}


void GameplayState::Render(float _ElapsedTime)
{
	for (int X = 0; X < Load->m_Grid->m_GridWidth; X++)
	{
		for (int Y = 0; Y < Load->m_Grid->m_GridHeight; Y++)
		{
			/*SGD::Rectangle DestinationRectangle;
			DestinationRectangle.top = X * Load->m_Tile->m_TileWidth;
			DestinationRectangle.left = Y * Load->m_Tile->m_TileHeight;
			DestinationRectangle.right = DestinationRectangle.left + Load->m_Grid->m_GridWidth;
			DestinationRectangle.bottom = DestinationRectangle.top + Load->m_Grid->m_GridHeight;*/
			//SGD::GraphicsManager::GetInstance()->DrawRectangle(DestinationRectangle, SGD::Color{ 255, 0, 255, 255 }, SGD::Color{ 255, 255, 0, 0 }, 5);

			SGD::Rectangle SourceRectangle;
			SourceRectangle.left = (float)(Load->Map[X][Y]->m_TileID % (int)(Load->Map[X][Y]->m_Image.width / Load->Map[X][Y]->m_TileWidth) * Load->Map[X][Y]->m_TileWidth);
			SourceRectangle.top = (float)(Load->Map[X][Y]->m_TileID / (int)(Load->Map[X][Y]->m_Image.height / Load->Map[X][Y]->m_TileHeight) * Load->Map[X][Y]->m_TileHeight);


			SourceRectangle.right = SourceRectangle.left + Load->Map[X][Y]->m_TileHeight;
			SourceRectangle.bottom = SourceRectangle.top + Load->Map[X][Y]->m_TileWidth;
			SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x, (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y }, SourceRectangle);
			//SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ 0, 0}, SGD::Rectangle(Load->Map[X][Y]->m_TileID % (512 / Load->m_Tile->m_TileWidth), Load->Map[X][Y]->m_TileID % (512 / Load->m_Tile->m_TileWidth), 32, 32));


		}
	}
	m_pEntities->RenderAll();
	if (m_Pause)
		RenderPause();
}
void GameplayState::MessageProc(const SGD::Message* pMsg)
{
	/* Show warning when a Message ID enumerator is not handled */
#pragma warning( push )
#pragma warning( 1 : 4061 )


	// What type of message?
	switch (pMsg->GetMessageID())
	{
	case MessageID::MSG_BACKPACK:
		SGD_PRINT(L"BackPack Done");
		break;
	case MessageID::MSG_UNKNOWN:
		SGD_PRINT(L"GameplayState::MessageProc - unknown message id\n");
		break;
	default:
		break;
	}


	/* Restore previous warning levels */
#pragma warning( pop )
}

void GameplayState::Pause(void)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow))
	{
		cursorPos++;
		if (cursorPos > 4)
			cursorPos = 0;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow))
	{
		;
		cursorPos--;
		if (cursorPos < 0)
			cursorPos = 4;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 0)
	{
		m_Pause = false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 1)
	{
		Game::GetInstance()->Pause(InstructionsState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 2)
	{
		Game::GetInstance()->Pause(OptionState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 3)
	{
		Game::GetInstance()->Pause(SaveGameState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 4)
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
	}
}

void GameplayState::RenderPause(void)
{
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_PauseImage, SGD::Point(10.0f, 100.0f));
	switch (cursorPos)
	{
	case 0: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 250, 175));
		break;
	case 1: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 250, 215));
		break;
	case 2: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 250, 250));
		break;
	case 3: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 250, 290));
		break;
	case 4: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(Game::GetInstance()->GetScreenSize().width / 2 - 250, 325));
		break;
	}
}
