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
	if (SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Right) && Switch == false || SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Q) && Switch == false)
	{
		Switch = true;
	}
	else if (SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Left) && Switch == true || SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Q) && Switch == true)
	{
		Switch = false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) && Game::GetInstance()->CheckPrevious() == false ||  SGD::InputManager::GetInstance()->IsButtonPressed(0, 9) && Game::GetInstance()->CheckPrevious() == false)
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) && Game::GetInstance()->CheckPrevious() == true || SGD::InputManager::GetInstance()->IsButtonPressed(0, 9) && Game::GetInstance()->CheckPrevious() == true)
	{
		Game::GetInstance()->Pause(GameplayState::GetInstance());
	}
	return true;
}

void InstructionsState::Render(float _ElapsedTime)
{
	if (Game::GetInstance()->GetLanguage() == 0)
	{
		if (!Switch)
		{
			Game::GetInstance()->GetFont().Draw("Instructions", SGD::Point{ 270.0f, 50.0f }, 0.75f);
			Game::GetInstance()->GetFont().Draw("Left Arrow:     -", SGD::Point{ 175.0f, 200.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Right Arrow:   -", SGD::Point{ 175.0f, 250.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Up Arrow :         -", SGD::Point{ 175.0f, 300.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press J:         -", SGD::Point{ 175.0f, 350.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press K:         -", SGD::Point{ 175.0f, 400.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press E:         -", SGD::Point{ 175.0f, 450 }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press Right Dpad/Q To See Controller Controls", SGD::Point{ 20.0f, 500 }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Move Left", SGD::Point{ 475.0f, 200.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Move Right", SGD::Point{ 475.0f, 250.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Jump", SGD::Point{ 475.0f, 300.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Switch Characters", SGD::Point{ 475.0f, 400.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("BackPack", SGD::Point{ 475.0f, 450.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Interact", SGD::Point{ 475.0f, 350.0f }, 0.50f);
		}
		 else if (Switch)
		{
		Game::GetInstance()->GetFont().Draw("Instructions", SGD::Point{ 270.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("DPad Left:     -", SGD::Point{ 175.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("DPad Right:   -", SGD::Point{ 175.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Press A:         -", SGD::Point{ 175.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Press B:         -", SGD::Point{ 175.0f, 350.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Press X:         -", SGD::Point{ 175.0f, 400.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Press Y:         -", SGD::Point{ 175.0f, 450 }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Press Left Dpad/Q To See Keyboard Controls", SGD::Point{ 20.0f, 500 }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Move Left", SGD::Point{ 475.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Move Right", SGD::Point{ 475.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Jump", SGD::Point{ 475.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Switch Characters", SGD::Point{ 475.0f, 400.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("BackPack", SGD::Point{ 475.0f, 450.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Interact", SGD::Point{ 475.0f, 350.0f }, 0.50f);
		}
		/*else
		{
			Game::GetInstance()->GetFont().Draw("Instructions", SGD::Point{ 270.0f, 50.0f }, 0.75f);
			Game::GetInstance()->GetFont().Draw("DPad Left:     -", SGD::Point{ 175.0f, 200.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("DPad Right:   -", SGD::Point{ 175.0f, 250.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press A:         -", SGD::Point{ 175.0f, 300.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press B:         -", SGD::Point{ 175.0f, 350.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press X:         -", SGD::Point{ 175.0f, 400.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Press Y:         -", SGD::Point{ 175.0f, 450 }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Move Left", SGD::Point{ 475.0f, 200.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Move Right", SGD::Point{ 475.0f, 250.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Jump", SGD::Point{ 475.0f, 300.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Switch Characters", SGD::Point{ 475.0f, 400.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("BackPack", SGD::Point{ 475.0f, 450.0f }, 0.50f);
			Game::GetInstance()->GetFont().Draw("Interact", SGD::Point{ 475.0f, 350.0f }, 0.50f);
		}*/
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