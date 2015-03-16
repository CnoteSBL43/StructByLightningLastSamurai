#include "OptionState.h"
#include "../resource/TinyXML/tinyxml.h"
#include <fstream>
#include <sstream>
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

	m_Music = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/Game_Music.xwm");
	m_SFX = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/Fire_torch.wav");

	TiXmlDocument m_Document;
	if (m_Document.LoadFile("Options") == false)
		return;
	TiXmlElement* m_Element = m_Document.RootElement();
	m_Element->Attribute("MasterVolume", &MasterVol);
	m_Element->Attribute("MusicVolume", &MusicVol);
	m_Element->Attribute("SFXVolume", &SFXVol);

	if (Game::GetInstance()->GetPlaySound())
	{
		SGD::AudioManager::GetInstance()->PlayAudio(m_Music, true);
	}
}

void OptionState::Exit()
{
	m_CursorPos = 0;
	SGD::AudioManager::GetInstance()->StopAudio(m_Music);
	SGD::AudioManager::GetInstance()->StopAudio(m_SFX);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_SFX);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_Music);
	TiXmlDocument m_Document;
	TiXmlDeclaration* m_Declare = new TiXmlDeclaration{ "1.0", "utf - 8", "" };
	m_Document.LinkEndChild(m_Declare);
	TiXmlElement* m_Element = new TiXmlElement{ "Options.xml" };
	m_Document.LinkEndChild(m_Element);
	m_Element->SetAttribute("MasterVolume", MasterVol);
	m_Element->SetDoubleAttribute("MusicVolume", MusicVol);
	m_Element->SetDoubleAttribute("SFXVolume", SFXVol);
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
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
		return true;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::LeftArrow) )
	{
		if (m_CursorPos == 0)
		{
			MasterVol -= 10;
			if (MasterVol < 0)
			{
				MasterVol = 100;
			}
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::Music, MasterVol);
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::SoundEffects, MasterVol);
			if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(m_Music))
				SGD::AudioManager::GetInstance()->PlayAudio(m_Music);
		}

		if (m_CursorPos == 1)
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
		else if (m_CursorPos == 2)
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
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::RightArrow))
	{
		if (m_CursorPos == 0)
		{
			MasterVol += 10;
			if (MasterVol > 100)
			{
				MasterVol = 0;
			}
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::Music, MasterVol);
			SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::SoundEffects, MasterVol);
			if (!SGD::AudioManager::GetInstance()->IsAudioPlaying(m_Music))
				SGD::AudioManager::GetInstance()->PlayAudio(m_Music);
		}

		if (m_CursorPos == 1)
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
		else if (m_CursorPos == 2)
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
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos < 2)
		m_CursorPos++;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) && m_CursorPos ==2)
		m_CursorPos = 0;
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos >0)
		m_CursorPos--;
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) && m_CursorPos == 0)
		m_CursorPos = 2;

	

	return true;
}

void OptionState::Render(float _ElapsedTime)
{
	std::wostringstream wos1, wos2, wos3;
	wos1 << MasterVol;
	wos2 << MusicVol;
	wos3 << SFXVol; 
	SGD::GraphicsManager::GetInstance()->DrawString(wos1.str().c_str(), SGD::Point(Game::GetInstance()->GetScreenWidth() / 2 +50, 50), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(wos2.str().c_str(), SGD::Point(Game::GetInstance()->GetScreenWidth() / 2+50, 100), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(wos3.str().c_str(), SGD::Point(Game::GetInstance()->GetScreenWidth() / 2+50, 150), SGD::Color(0, 255, 0));

	SGD::GraphicsManager::GetInstance()->DrawString(L"Options", SGD::Point(Game::GetInstance()->GetScreenWidth()/2-10, 10), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Master Volume", SGD::Point(Game::GetInstance()->GetScreenWidth() / 2 - 100, 50), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"Music Volume", SGD::Point(Game::GetInstance()->GetScreenWidth() / 2 - 100, 100), SGD::Color(0, 255, 0));
	SGD::GraphicsManager::GetInstance()->DrawString(L"SFX Volume", SGD::Point(Game::GetInstance()->GetScreenWidth() / 2 - 100, 150), SGD::Color(0, 255, 0));

}