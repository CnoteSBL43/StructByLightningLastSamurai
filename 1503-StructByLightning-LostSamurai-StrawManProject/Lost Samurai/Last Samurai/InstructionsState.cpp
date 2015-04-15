#include "InstructionsState.h"

InstructionsState* InstructionsState::GetInstance()
{
	static InstructionsState m_Instance;
	return &m_Instance;
}

void InstructionsState::Enter()
{
	m_BackArrow = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/BackArrow.png");
}

void InstructionsState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_BackArrow);
}

bool InstructionsState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) && Game::GetInstance()->CheckPrevious()==false)
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) && Game::GetInstance()->CheckPrevious() == true)
	{
		Game::GetInstance()->Pause(GameplayState::GetInstance());
	}
	return true;
}

void InstructionsState::Render(float _ElapsedTime)
{
	if (Game::GetInstance()->GetLanguage() == 0)
	{
		Game::GetInstance()->GetFont().Draw("Instructions", SGD::Point{ 270.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("Move Left      -", SGD::Point{ 175.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Move Right    -", SGD::Point{ 175.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Jump             -", SGD::Point{ 175.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Left Arrow", SGD::Point{ 475.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Right Arrow", SGD::Point{ 475.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Up Arrow", SGD::Point{ 475.0f, 300.0f }, 0.50f);
	}
	else
	{
		Game::GetInstance()->GetFont().Draw("Instrucciones", SGD::Point{ 270.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("Mover a la Izquierda    -", SGD::Point{ 100.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("mover a la Derecha    -", SGD::Point{ 100.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Jump                           -", SGD::Point{ 100.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Flecha Izquierda", SGD::Point{ 500.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Flecha Derecha", SGD::Point{ 500.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Flecha Arriba", SGD::Point{ 500.0f, 300.0f }, 0.50f);
	}
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_BackArrow, SGD::Point{ 5.0f, Game::GetInstance()->GetScreenSize().height - 75 });
	Game::GetInstance()->GetFont().Draw("Esc", SGD::Point{ 125.0f, Game::GetInstance()->GetScreenSize().height - 60 }, 0.50f);
}