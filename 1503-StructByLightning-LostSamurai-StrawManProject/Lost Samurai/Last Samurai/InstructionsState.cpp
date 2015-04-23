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
	if (Arcade == 1)
	{


		if (SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Right) && Switch == false || SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Q) && Switch == false)
		{
			Switch = true;
		}
		else if (SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Left) && Switch == true || SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Q) && Switch == true)
		{
			Switch = false;
		}
	}
	else if (Arcade == 0)
	{
		if (SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Right) && Switch == false || SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Q) && Switch == false)
		{
			Switch = true;
		}
		else if (SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Left) && Switch == true || SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Q) && Switch == true)
		{
			Switch = false;
		}
	}

	if (SGD::InputManager::GetInstance()->IsButtonPressed(0, 8) && Arcade == false)
	{
		Arcade = true;
	}
	else if (SGD::InputManager::GetInstance()->IsButtonPressed(0, 8) && Arcade == true)
	{
		Arcade = false;
	}


	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) && Game::GetInstance()->CheckPrevious() == false || SGD::InputManager::GetInstance()->IsButtonPressed(0, 9) && Game::GetInstance()->CheckPrevious() == false)
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
#pragma region English
	if (Game::GetInstance()->GetLanguage() == 0)
	{
		if (Arcade)
		{
			if (!Switch)
			{
				Game::GetInstance()->GetFont().Draw("Instructions", SGD::Point{ 170.0f, 50.0f }, 0.75f);
				Game::GetInstance()->GetFont().Draw("Left Arrow:     -", SGD::Point{ 75.0f, 200.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Right Arrow:   -", SGD::Point{ 75.0f, 250.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Up Arrow :         -", SGD::Point{ 75.0f, 300.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press J:         -", SGD::Point{ 75.0f, 350.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press K:         -", SGD::Point{ 75.0f, 400.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press E:         -", SGD::Point{ 75.0f, 450.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press Right Dpad/Q To See Controller Controls", SGD::Point{ 20.0f, 500.0f }, 0.30f);
				Game::GetInstance()->GetFont().Draw("Move Left", SGD::Point{ 375.0f, 200.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Move Right", SGD::Point{ 375.0f, 250.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Jump", SGD::Point{ 375.0f, 300.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Switch Characters", SGD::Point{ 375.0f, 400.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("BackPack", SGD::Point{ 375.0f, 450.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Interact", SGD::Point{ 375.0f, 350.0f }, 0.375f);
			}
			else if (Switch)
			{
				Game::GetInstance()->GetFont().Draw("Instructions", SGD::Point{ 170.0f, 50.0f }, 0.75f);
				Game::GetInstance()->GetFont().Draw("DPad Left:     -", SGD::Point{ 75.0f, 200.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("DPad Right:   -", SGD::Point{ 75.0f, 250.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press A:         -", SGD::Point{ 75.0f, 300.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press B:         -", SGD::Point{ 75.0f, 350.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press X:         -", SGD::Point{ 75.0f, 400.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press Y:         -", SGD::Point{ 75.0f, 450.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Press Left Dpad/Q To See Keyboard Controls", SGD::Point{ 20.0f, 500.0f }, 0.30f);
				Game::GetInstance()->GetFont().Draw("Move Left", SGD::Point{ 375.0f, 200.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Move Right", SGD::Point{ 375.0f, 250.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Jump", SGD::Point{ 375.0f, 300.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Switch Characters", SGD::Point{ 375.0f, 400.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("BackPack", SGD::Point{ 375.0f, 450.0f }, 0.375f);
				Game::GetInstance()->GetFont().Draw("Interact", SGD::Point{ 375.0f, 350.0f }, 0.375f);
			}

		}
		else if (!Arcade)
		{

			Game::GetInstance()->GetFont().Draw(" Arcade Instructions", SGD::Point{ 5.0f, 50.0f }, 0.75f);
			Game::GetInstance()->GetFont().Draw(" Left Stick:     -", SGD::Point{ 25.0f, 200.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Right Stick:   -", SGD::Point{ 25.0f, 250.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Press 0:         -", SGD::Point{ 25.0f, 300.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Press 2:         -", SGD::Point{ 25.0f, 350.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Press 3:         -", SGD::Point{ 25.0f, 400.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Press 1:         -", SGD::Point{ 25.0f, 450.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Press Select to See Keyboard/Controller Controls", SGD::Point{ 25.0f, 500.0f }, 0.30f);
			Game::GetInstance()->GetFont().Draw("Move Left", SGD::Point{ 400.0f, 200.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Move Right", SGD::Point{ 400.0f, 250.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Jump", SGD::Point{ 400.0f, 300.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Switch Characters", SGD::Point{ 400.0f, 400.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("BackPack", SGD::Point{ 400.0f, 450.0f }, 0.375f);
			Game::GetInstance()->GetFont().Draw("Interact", SGD::Point{ 400.0f, 350.0f }, 0.375f);
		}
	}
#pragma endregion
	else
	{
		if (!Switch)
		{
			Game::GetInstance()->GetFont().Draw("Instrucciones", SGD::Point{ 170.0f, 50.0f }, 0.75f);
			Game::GetInstance()->GetFont().Draw("Flecha Izquierda:", SGD::Point{ 25.0f, 200.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Flecha Correcta   ", SGD::Point{ 25.0f, 250.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Flecha Hacia Arriba:", SGD::Point{ 25.0f, 300.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Pulse J:", SGD::Point{ 25.0f, 350.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Pulse K:", SGD::Point{ 25.0f, 400.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Pulse E:", SGD::Point{ 25.0f, 450.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Pulse Derecha Dpad/Q Para Ver Controles Controlador", SGD::Point{ 20.0f, 500.0f }, 0.30f);
			Game::GetInstance()->GetFont().Draw("Muevete A La Izquierda", SGD::Point{ 375.0f, 200.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Moverse A La Derecha", SGD::Point{ 375.0f, 250.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Saltar", SGD::Point{ 375.0f, 300.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Personajes interruptor", SGD::Point{ 375.0f, 400.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Mochila", SGD::Point{ 375.0f, 450.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Obrar reciprocamente", SGD::Point{ 375.0f, 350.0f }, 0.3f);
		}
		else if (Switch)
		{

			Game::GetInstance()->GetFont().Draw("Instrucciones", SGD::Point{ 170.0f, 50.0f }, 0.75f);
			Game::GetInstance()->GetFont().Draw("DPad izquierda:", SGD::Point{ 25.0f, 200.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("DPad derecho", SGD::Point{ 25.0f, 250.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Presione A:", SGD::Point{ 25.0f, 300.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Presione B:", SGD::Point{ 25.0f, 350.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Presione X:", SGD::Point{ 25.0f, 400.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Presione Y:", SGD::Point{ 25.0f, 450.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Pulse Izquierda Dpad / Q Para Ver Controles del teclado", SGD::Point{ 20.0f, 500.0f }, 0.30f);
			Game::GetInstance()->GetFont().Draw("Muevete A La Izquierda", SGD::Point{ 375.0f, 200.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Moverse A La Derecha", SGD::Point{ 375.0f, 250.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Saltar", SGD::Point{ 375.0f, 300.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Personajes interruptor", SGD::Point{ 375.0f, 400.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Mochila", SGD::Point{ 375.0f, 450.0f }, 0.3f);
			Game::GetInstance()->GetFont().Draw("Obrar reciprocamente", SGD::Point{ 375.0f, 350.0f }, 0.3f);
		}
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_BackArrow, SGD::Point{ 5.0f, Game::GetInstance()->GetScreenSize().height - 75 });
		Game::GetInstance()->GetFont().Draw("Esc", SGD::Point{ 125.0f, Game::GetInstance()->GetScreenSize().height - 60 }, 0.50f);
	}
}