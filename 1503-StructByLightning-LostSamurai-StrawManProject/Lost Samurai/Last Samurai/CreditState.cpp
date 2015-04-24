#include "CreditState.h"

CreditState* CreditState::GetInstance()
{
	static CreditState m_Instance;
	return &m_Instance;
}

void CreditState::Enter()
{
	m_BackArrow = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/BackArrow.png");
	m_CreditMusic = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/creditsmenu.xwm");
	Select = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/confirm.wav");
	SGD::AudioManager::GetInstance()->PlayAudio(m_CreditMusic, true);
}

void CreditState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_BackArrow);
	SGD::AudioManager::GetInstance()->StopAudio(m_CreditMusic);
}

bool CreditState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) || (SGD::InputManager::GetInstance()->IsButtonPressed(0, 9)))
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	return true;
}

void CreditState::Render(float _ElapsedTime)
{
	if (Game::GetInstance()->GetLanguage() == 0)
	{
		Game::GetInstance()->GetFont().Draw("Credits", SGD::Point{ 300.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("John Oleske", SGD::Point{ 175.0f, 130.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Shawn Paris", SGD::Point{ 175.0f, 180.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Blake Bergstrom", SGD::Point{ 175.0f, 230.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Cory Saunders", SGD::Point{ 175.0f, 280.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Jacob Keffer", SGD::Point{ 175.0f, 330.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Varun Kumar", SGD::Point{ 175.0f, 380.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Gregory Bey", SGD::Point{ 175.0f, 430.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Caris Frazier", SGD::Point{ 175.0f, 480.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Deepanshu Gupta", SGD::Point{ 175.0f, 530.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  EP", SGD::Point{ 575.0f, 130.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  AP", SGD::Point{ 575.0f, 180.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Developer", SGD::Point{ 575.0f, 230.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Developer", SGD::Point{ 575.0f, 280.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Developer", SGD::Point{ 575.0f, 330.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Developer", SGD::Point{ 575.0f, 380.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Artist", SGD::Point{ 575.0f, 430.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Artist", SGD::Point{ 575.0f, 480.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Music", SGD::Point{ 575.0f, 530.0f }, 0.50f);
	}
	else
	{
		Game::GetInstance()->GetFont().Draw("Creditos", SGD::Point{ 300.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("John Oleske", SGD::Point{ 175.0f, 130.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Shawn Paris", SGD::Point{ 175.0f, 180.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Blake Bergstrom", SGD::Point{ 175.0f, 230.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Cory Saunders", SGD::Point{ 175.0f, 280.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Jacob Keffer", SGD::Point{ 175.0f, 330.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Varun Kumar", SGD::Point{ 175.0f, 380.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Gregory Bey", SGD::Point{ 175.0f, 430.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Caris Frazier", SGD::Point{ 175.0f, 480.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Deepanshu Gupta", SGD::Point{ 175.0f, 530.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  EP", SGD::Point{ 575.0f, 130.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  AP", SGD::Point{ 575.0f, 180.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Revelador", SGD::Point{ 575.0f, 230.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Revelador", SGD::Point{ 575.0f, 280.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Revelador", SGD::Point{ 575.0f, 330.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Revelador", SGD::Point{ 575.0f, 380.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Artista", SGD::Point{ 575.0f, 430.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Artista", SGD::Point{ 575.0f, 480.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("-  Musica", SGD::Point{ 575.0f, 530.0f }, 0.50f);
	}
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_BackArrow, SGD::Point{ 0.0f, Game::GetInstance()->GetScreenSize().height - 50 });
	Game::GetInstance()->GetFont().Draw("Esc", SGD::Point{ 105.0f, Game::GetInstance()->GetScreenSize().height - 35 }, 0.50f);


}
