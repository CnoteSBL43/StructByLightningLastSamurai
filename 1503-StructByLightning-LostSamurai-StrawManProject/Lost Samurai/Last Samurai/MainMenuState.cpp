#include "MainMenuState.h"
#include "LoadGameState.h"
MainMenuState* MainMenuState::GetInstance()
{
	static MainMenuState m_Instance;
	return &m_Instance;
}


void MainMenuState::Enter()
{
	m_GameMusic = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/Game_Music.xwm");
	m_Pointer = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Finger.png");
	m_BkgndImg = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/mainmenuimg.png");
	int MusicVol = Game::GetInstance()->GetMusicVolume();
	SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::Music, MusicVol);
	SGD::AudioManager::GetInstance()->PlayAudio(m_GameMusic);
	m_Movement = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/cursormove.wav");
	Select = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/confirm.wav");
}

void MainMenuState::Exit()
{
	SGD::AudioManager::GetInstance()->StopAudio(m_GameMusic);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_Pointer);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_BkgndImg);
	SGD::AudioManager::GetInstance()->StopAudio(m_GameMusic);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_GameMusic);
}

bool MainMenuState::Update(float _ElapsedTime)
{

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))//leaves game
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		return false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 0 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && m_CursorPos == 0)//PlayGame
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->ChangeState(LoadGameState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 1 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && m_CursorPos == 1)//instructions
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->ChangeState(InstructionsState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 2 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && m_CursorPos == 2)//options
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->ChangeState(OptionState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 3 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && m_CursorPos == 3)//credits
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->ChangeState(CreditState::GetInstance());
		return true;
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 4 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && m_CursorPos == 4)//exit
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		return false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos < 4 || SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Down) && m_CursorPos < 4)
	{
		m_CursorPos++;
		SGD::AudioManager::GetInstance()->PlayAudio(m_Movement);
	}

	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos == 4 || SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Down) && m_CursorPos == 4)
	{
		m_CursorPos = 0;
		SGD::AudioManager::GetInstance()->PlayAudio(m_Movement);
	}

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos > 0 || SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Up) && m_CursorPos > 0)
	{
		m_CursorPos--;
		SGD::AudioManager::GetInstance()->PlayAudio(m_Movement);
	}

	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos == 0 | SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Up) && m_CursorPos == 0)
		m_CursorPos = 4;


	return true;
}

void MainMenuState::Render(float _ElapsedTime)
{
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_BkgndImg, {});

	if (Game::GetInstance()->GetLanguage() == 0)
	{
		Game::GetInstance()->GetFont().Draw("Play", SGD::Point{ 375.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Instructions", SGD::Point{ 325.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Options", SGD::Point{ 350.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Credits", SGD::Point{ 350.0f, 350.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Exit", SGD::Point{ 375.0f, 400.0f }, 0.50f);
	}
	else
	{
		Game::GetInstance()->GetFont().Draw("Juego", SGD::Point{ 375.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Instrucciones", SGD::Point{ 325.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Opciones", SGD::Point{ 350.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Creditos", SGD::Point{ 350.0f, 350.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Salida", SGD::Point{ 375.0f, 400.0f }, 0.50f);
	}
	switch (m_CursorPos)
	{
	case 0: SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 210.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 1: SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 260.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 2: SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 310.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 3: SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 360.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 4: SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 410.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	}

}
