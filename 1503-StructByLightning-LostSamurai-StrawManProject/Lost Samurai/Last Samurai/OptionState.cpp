#include "OptionState.h"
#include "../resource/TinyXML/tinyxml.h"
#include <sstream>
#include "Actor.h"
#include "../SGD Wrappers/SGD_Geometry.h"
OptionState* OptionState::GetInstance()
{
	static OptionState m_Instance;
	return &m_Instance;
}

void OptionState::Enter()
{
	/*std::ifstream fin;
	fin.open("Options.txt");
	if (fin.is_open())
	{
		int mastervol,musvol, sfxvol;
		fin >> mastervol;
		fin >> musvol;
		fin >> sfxvol;
		SetMasterVol(mastervol);
		SetSFXVol(sfxvol);
		SetMusicVol(musvol);
		fin.close();
	}*/
	m_BackArrow = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/BackArrow.png");

	m_Music = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/Game_Music.xwm");
	m_SFX = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/Fire_torch.wav");
	m_Pointer = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Finger.png");
	//int fullscreen;
	//TiXmlDocument m_Document;
	//if (m_Document.LoadFile("Options") == false)
	//	return;
	//TiXmlElement* m_Element = m_Document.RootElement();
	//m_Element->Attribute("MasterVolume", &MasterVol);
	//m_Element->Attribute("MusicVolume", &MusicVol);
	//m_Element->Attribute("SFXVolume", &SFXVol);
	//m_Element->Attribute("FullScreen", &fullscreen);

	//Values from game menu
	MusicVol = Game::GetInstance()->GetMusicVolume();
	SFXVol = Game::GetInstance()->GetSFXVolume();
	fullscreen = Game::GetInstance()->GetFullScreen();
	language = Game::GetInstance()->GetLanguage();
	if (language == 0)
		tempLanguage = false;
	else
		tempLanguage = true;

}

void OptionState::Exit()
{
	m_CursorPos = 0;
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_BackArrow);
	Game::GetInstance()->SetMusicVolume(MusicVol);
	Game::GetInstance()->SetSFXVolume(SFXVol);
	Game::GetInstance()->SetFullScreen(fullscreen);
	SGD::AudioManager::GetInstance()->StopAudio(m_Music);
	SGD::AudioManager::GetInstance()->StopAudio(m_SFX);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_SFX);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_Music);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_Pointer);
	TiXmlDocument m_Document;
	TiXmlDeclaration* m_Declare = new TiXmlDeclaration{ "1.0", "utf - 8", "" };
	m_Document.LinkEndChild(m_Declare);
	TiXmlElement* m_Element = new TiXmlElement{ "Options.xml" };
	m_Document.LinkEndChild(m_Element);
	m_Element->SetDoubleAttribute("MusicVolume", MusicVol);
	m_Element->SetDoubleAttribute("SFXVolume", SFXVol);
	m_Element->SetDoubleAttribute("FullScreen", fullscreen);
	m_Element->SetDoubleAttribute("Language", language);
	m_Document.SaveFile("Options");
	/*std::ofstream fout;
	fout.open("Options.txt");
	if (fout.is_open())
	{
		fout <<MasterVol << " " << MusicVol << " " << SFXVol;
		fout.close();
	}*/
}

bool OptionState::Update(float _ElapsedTime)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) && Game::GetInstance()->CheckPrevious() == false)
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
	}
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) && Game::GetInstance()->CheckPrevious() == true)
	{
		Game::GetInstance()->Pause(GameplayState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::LeftArrow) )
	{
		if (m_CursorPos == 0)
		{
			MusicVol -= 10;
			if (MusicVol < 0)
			{
				MusicVol = 100;
			}
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::Music, MusicVol);
			if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(m_Music))
				SGD::AudioManager::GetInstance()->PlayAudio(m_Music);
		}
		else if (m_CursorPos == 1)
		{
			SFXVol -= 10;
			if (SFXVol < 0)
			{
				SFXVol = 100;
			}
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::SoundEffects, SFXVol);
			if (SGD::AudioManager::GetInstance()->IsAudioPlaying(m_SFX))
				SGD::AudioManager::GetInstance()->StopAudio(m_SFX );
			SGD::AudioManager::GetInstance()->PlayAudio(m_SFX);
			if (SGD::AudioManager::GetInstance()->IsAudioPlaying(m_Music))
				SGD::AudioManager::GetInstance()->StopAudio(m_Music);
		}
		else if (m_CursorPos == 2)
		{
			if (!fullscreen)
				fullscreen = true;
			else
				fullscreen = false;
			Game::GetInstance()->SetFullScreen(fullscreen);

			SGD::GraphicsManager::GetInstance()->Resize(SGD::Size{ Game::GetInstance()->GetScreenSize().width, Game::GetInstance()->GetScreenSize().height }, !fullscreen);
		}
		else if (m_CursorPos == 3)
		{
			if (language == 0)
			{
				tempLanguage = true;
				language = 1;
			}
			else if (language == 1)
			{
				tempLanguage = false;
				language = 0;
			}
			Game::GetInstance()->SetLanguage(language);
		}
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::RightArrow))
	{
		if (m_CursorPos == 0)
		{
			MusicVol += 10;
			if (MusicVol >100)
			{
				MusicVol = 0;
			}
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::Music, MusicVol);
			if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(m_Music))
				SGD::AudioManager::GetInstance()->PlayAudio(m_Music);
		}
		else if (m_CursorPos == 1)
		{
			SFXVol += 10;
			if (SFXVol >100)
			{
				SFXVol = 0;
			}
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::SoundEffects, SFXVol);
			if (SGD::AudioManager::GetInstance()->IsAudioPlaying(m_SFX))
				SGD::AudioManager::GetInstance()->StopAudio(m_SFX);
			SGD::AudioManager::GetInstance()->PlayAudio(m_SFX);
			if (SGD::AudioManager::GetInstance()->IsAudioPlaying(m_Music))
				SGD::AudioManager::GetInstance()->StopAudio(m_Music);
		}
		else if (m_CursorPos == 2)
		{
			if (!fullscreen)
				fullscreen = true;
			else
				fullscreen = false;
			Game::GetInstance()->SetFullScreen(fullscreen);
			SGD::GraphicsManager::GetInstance()->Resize(SGD::Size{ Game::GetInstance()->GetScreenSize().width, Game::GetInstance()->GetScreenSize().height }, !fullscreen);
		}
		else if (m_CursorPos == 3)
		{
			if (language == 0)
			{
				tempLanguage = true;
				language = 1;
			}
			else if (language == 1)
			{
				tempLanguage = false;
				language = 0;
			}
			Game::GetInstance()->SetLanguage(language);
		}
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && m_CursorPos == 4)
	{
		TiXmlDocument m_Document;
		if (m_Document.LoadFile("Save1") == true)
		{
			TiXmlElement* m_Element = m_Document.RootElement();
			double fPosx, fPosy, sPosx, sPosy, spawnX, spawnY;
			m_Element->Attribute("FatherPosX", &fPosx);
			// Use the XElement Variable to Find the String in the XML File and then Store the Variable to the m_SFXVol Variable 
			m_Element->Attribute("FatherPosY", &fPosy);
			// Use the XElement Variable to Find the String in the XML File and then Store the Variable to the FullScreen Variable 
			m_Element->Attribute("SonPosX", &sPosx);
			m_Element->Attribute("SonPosY", &sPosy);
		//	m_Element->Attribute("SpawnPointX", &spawnX);
			//m_Element->Attribute("SpawnPointY", &spawnY);
			GameplayState::GetInstance()->GetFather()->SetPosition({ (float)fPosx, (float)fPosy });
			GameplayState::GetInstance()->GetSon()->SetPosition({ (float)sPosx, (float)sPosy });
			
		}
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos < 4)
		m_CursorPos++;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos ==4)
		m_CursorPos = 0;
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos >0)
		m_CursorPos--;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos == 0)
		m_CursorPos =4;

	

	return true;
}

void OptionState::Render(float _ElapsedTime)
{
	std::wostringstream wos1, wos2, wos3, wos4;
	wos1 << MusicVol;
	wos2 << SFXVol; 
	if(tempLanguage)
		wos4 << "Spanish";
	else 
		wos4 << "English";
	if (Game::GetInstance()->GetLanguage()==0)
	{
		Game::GetInstance()->GetFont().Draw("Options", SGD::Point{ 270.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("Music Volume", SGD::Point{ 125.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("SFX Volume", SGD::Point{ 125.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("FullScreen", SGD::Point{ 125.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Language", SGD::Point{ 125.0f, 350.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Load Game", SGD::Point{ 125.0f, 400.0f }, 0.50f);
		if (fullscreen)
			wos3 << "Yes";
		else
			wos3 << "No";
	}
	else
	{
		Game::GetInstance()->GetFont().Draw("Opciones", SGD::Point{ 270.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("Volumen de la Musica", SGD::Point{ 125.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("SFX volumen", SGD::Point{ 125.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Pantalla Completa", SGD::Point{ 125.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Idioma", SGD::Point{ 125.0f, 350.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Cargar Partida", SGD::Point{ 125.0f, 400.0f }, 0.50f);

		if (fullscreen)
			wos3 << "Si";
		else
			wos3 << "No";
	}
	if (m_CursorPos == 0)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(50.0f, 210.0f), 0.0f, {}, SGD::Color(255,153,0));
	}
	else if (m_CursorPos == 1)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(50.0f, 260.0f), 0.0f, {}, SGD::Color(255, 153, 0));

	}
	else if (m_CursorPos == 2)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(50.0f, 310.0f), 0.0f, {}, SGD::Color(255, 153, 0));
	}
	else if (m_CursorPos == 3)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(50.0f, 360.0f), 0.0f, {}, SGD::Color(255, 153, 0));
	}
	else if (m_CursorPos==4)
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(50.0f, 410.0f), 0.0f, {}, SGD::Color(255, 153, 0));

	Game::GetInstance()->GetFont().Draw(wos1.str().c_str(), SGD::Point{ 500.0f, 200.0f }, 0.50f);
	Game::GetInstance()->GetFont().Draw(wos2.str().c_str(), SGD::Point{ 500.0f, 250.0f }, 0.50f);
	Game::GetInstance()->GetFont().Draw(wos3.str().c_str(), SGD::Point{ 500.0f, 300.0f }, 0.50f);
	Game::GetInstance()->GetFont().Draw(wos4.str().c_str(), SGD::Point{ 500.0f, 350.0f }, 0.50f);
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_BackArrow, SGD::Point{ 5.0f, Game::GetInstance()->GetScreenSize().height - 75 });
	Game::GetInstance()->GetFont().Draw("Esc", SGD::Point{ 125.0f, Game::GetInstance()->GetScreenSize().height - 60 }, 0.50f);


}