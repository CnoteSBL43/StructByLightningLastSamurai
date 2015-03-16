#include "MainMenuState.h"

MainMenuState* MainMenuState::GetInstance()
{
	static MainMenuState m_Instance;
	return &m_Instance;
}


void MainMenuState::Enter()
{
	m_MainMenu = SGD::GraphicsManager::GetInstance()->LoadTexture(L"../resource/graphics/PlayGame.png");
	m_Instructions = SGD::GraphicsManager::GetInstance()->LoadTexture(L"../resource/graphics/Instructions.png");
	m_Credits = SGD::GraphicsManager::GetInstance()->LoadTexture(L"../resource/graphics/Credits.png");
	m_Options = SGD::GraphicsManager::GetInstance()->LoadTexture(L"../resource/graphics/Options.png");
	m_Exit = SGD::GraphicsManager::GetInstance()->LoadTexture(L"../resource/graphics/Exit.png");
	m_GameMusic = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/Game_Music.xwm");
	Game::GetInstance()->SetPlaySound(false);
	if (Game::GetInstance()->GetPlaySound())
	{
		SGD::AudioManager::GetInstance()->PlayAudio(m_GameMusic, true);
	}
}

void MainMenuState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_MainMenu);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_Instructions);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_Credits);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_Options);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_Exit);
	SGD::AudioManager::GetInstance()->StopAudio(m_GameMusic);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_GameMusic);
}

bool MainMenuState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))//leaves game
	{
		return false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 0)//PlayGame
	{
		Game::GetInstance()->ChangeState(GameplayState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos==1)//instructions
	{
		Game::GetInstance()->ChangeState(InstructionsState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 2)//options
	{
		Game::GetInstance()->ChangeState(OptionState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 3)//credits
	{
		Game::GetInstance()->ChangeState(CreditState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 4)//exit
	{
		return false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos < 4)
		m_CursorPos++;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos ==4)
		m_CursorPos = 0;
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos >0)
		m_CursorPos--;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos ==0)
		m_CursorPos = 4;


	 return true;
}

void MainMenuState::Render(float _ElapsedTime)
{
	switch (m_CursorPos)
	{
	case 0:SGD::GraphicsManager::GetInstance()->DrawTexture(m_MainMenu, SGD::Point(0.0f, 0.0f));
			break;
	case 1:SGD::GraphicsManager::GetInstance()->DrawTexture(m_Instructions, SGD::Point(0.0f, 0.0f));
		break;
	case 2:SGD::GraphicsManager::GetInstance()->DrawTexture(m_Options, SGD::Point(0.0f, 0.0f));
		break;
	case 3:SGD::GraphicsManager::GetInstance()->DrawTexture(m_Credits, SGD::Point(0.0f, 0.0f));
		break;
	case 4:SGD::GraphicsManager::GetInstance()->DrawTexture(m_Exit, SGD::Point(0.0f, 0.0f));
		break;
	}
	//SGD::GraphicsManager::GetInstance()->DrawString(L"MainMenu", SGD::Point(500, 10), SGD::Color(0, 255, 0));

}
