#include "LoadGameState.h"
#include "Game.h"
#include "GameplayState.h"
#include "OptionState.h"
LoadGameState* LoadGameState::GetInstance()
{
	static LoadGameState m_Instance;
	return &m_Instance;
}

void LoadGameState::Enter()
{

}

void LoadGameState::Exit()
{

}

bool LoadGameState::Update(float _ElapsedTime)
{
	if (m_LoadingTime >= m_LoadTimer)
	{
		m_LoadingTime = 0;
		Game::GetInstance()->ChangeState(GameplayState::GetInstance());
	}
	m_LoadingTime += _ElapsedTime;

	return true;
}

void LoadGameState::Render(float _ElapsedTime)
{
	SGD::Point pt = { Game::GetInstance()->GetScreenSize().width / 2 - 256, Game::GetInstance()->GetScreenSize().height / 2 };
	SGD::Size sz = { (100 * m_LoadingTime) / 3, 25 };
	if (sz.width != 0)
		SGD::GraphicsManager::GetInstance()->DrawRectangle({ { pt.x, pt.y + 100 }, sz }, SGD::Color{ 255, 0, 255, 255 });
	if (Game::GetInstance()->GetLanguage() == 0)
		Game::GetInstance()->GetFont().Draw("Loading", pt, 1, { 255, 255, 255, 255 });
	else
		Game::GetInstance()->GetFont().Draw("Sobre Prima", pt, 1, { 255, 255, 255, 255 });

}
