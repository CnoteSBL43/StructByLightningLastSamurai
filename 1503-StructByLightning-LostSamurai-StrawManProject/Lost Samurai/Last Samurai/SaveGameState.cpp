#include "SaveGameState.h"
#include "GameplayState.h"
#include "../resource/TinyXML/tinyxml.h"
#include "../resource/TinyXML/tinystr.h"
#include "Actor.h"
SaveGameState* SaveGameState::GetInstance()
{
	static SaveGameState m_Instance;
	return &m_Instance;
}

void SaveGameState::Enter()
{
	m_Pointer = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Finger.png");

	int x = 0;
	TiXmlDocument m_Document;
	if (m_Document.LoadFile("Save1") == false)
	{
		TiXmlDocument m_Document;
		TiXmlDeclaration* m_Declare = new TiXmlDeclaration{ "1.0", "utf - 8", "" };
		m_Document.LinkEndChild(m_Declare);
		TiXmlElement* m_Element = new TiXmlElement{ "Save1.xml" };
		m_Document.LinkEndChild(m_Element);
		m_Element->SetDoubleAttribute("FatherPosX", 0);
		m_Element->SetDoubleAttribute("FatherPosY", 0);
		m_Element->SetDoubleAttribute("SonPosX", 0);
		m_Element->SetDoubleAttribute("SonPosY", 0);
		m_Element->SetDoubleAttribute("SpawnPointX", 0);
		m_Element->SetDoubleAttribute("SpawnPointY", 0);
		m_Document.SaveFile("Save1");
	}
	if (m_Document.LoadFile("Save2") == false)
	{
		TiXmlDocument m_Document;
		TiXmlDeclaration* m_Declare = new TiXmlDeclaration{ "1.0", "utf - 8", "" };
		m_Document.LinkEndChild(m_Declare);
		TiXmlElement* m_Element = new TiXmlElement{ "Save2.xml" };
		m_Document.LinkEndChild(m_Element);
		m_Element->SetDoubleAttribute("FatherPosX", 0);
		m_Element->SetDoubleAttribute("FatherPosY", 0);
		m_Element->SetDoubleAttribute("SonPosX", 0);
		m_Element->SetDoubleAttribute("SonPosY", 0);
		m_Element->SetDoubleAttribute("SpawnPointX", 0);
		m_Element->SetDoubleAttribute("SpawnPointY", 0);
		m_Document.SaveFile("Save2");
	}
	if (m_Document.LoadFile("Save3") == false)
	{
		TiXmlDocument m_Document;
		TiXmlDeclaration* m_Declare = new TiXmlDeclaration{ "1.0", "utf - 8", "" };
		m_Document.LinkEndChild(m_Declare);
		TiXmlElement* m_Element = new TiXmlElement{ "Save3.xml" };
		m_Document.LinkEndChild(m_Element);
		m_Element->SetDoubleAttribute("FatherPosX", 0);
		m_Element->SetDoubleAttribute("FatherPosY", 0);
		m_Element->SetDoubleAttribute("SonPosX", 0);
		m_Element->SetDoubleAttribute("SonPosY", 0);
		m_Element->SetDoubleAttribute("SpawnPointX", 0);
		m_Element->SetDoubleAttribute("SpawnPointY", 0);
		m_Document.SaveFile("Save3");
	}
}

void SaveGameState::Exit()
{
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_Pointer);

	m_CursorPos = 0;
}

bool SaveGameState::Update(float _ElapsedTime)
{

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		Game::GetInstance()->Pause(GameplayState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Down))
	{
		m_CursorPos++;
		if (m_CursorPos > 2)
			m_CursorPos = 0;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Up))
	{
		m_CursorPos--;
		if (m_CursorPos <0)
			m_CursorPos = 2;
	}
	if (m_CursorPos == 0 && SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter))
	{
		TiXmlDocument m_Document;
		if (m_Document.LoadFile("Save1") == true)
		{
			TiXmlElement* m_Element = m_Document.RootElement();
			m_Element->Attribute("Save");
			m_Element->SetDoubleAttribute("FatherPosX", GameplayState::GetInstance()->GetFather()->GetPosition().x);
			m_Element->SetDoubleAttribute("FatherPosY", GameplayState::GetInstance()->GetFather()->GetPosition().y);
			m_Element->SetDoubleAttribute("SonPosX", GameplayState::GetInstance()->GetSon()->GetPosition().x);
			m_Element->SetDoubleAttribute("SonPosY", GameplayState::GetInstance()->GetSon()->GetPosition().y);
			//m_Element->SetDoubleAttribute("SpawnPointX", GameplayState::GetInstance()->);
			//m_Element->SetDoubleAttribute("SpawnPointY", 0);
			m_Document.SaveFile("Save1");
		}
	}
	if (m_CursorPos == 1 && SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter))
	{
		TiXmlDocument m_Document;



		if (m_Document.LoadFile("Save2") == true)
		{
			TiXmlElement* m_Element = m_Document.RootElement();

			m_Element->SetDoubleAttribute("FatherPosX", GameplayState::GetInstance()->GetFather()->GetPosition().x);
			m_Element->SetDoubleAttribute("FatherPosY", GameplayState::GetInstance()->GetFather()->GetPosition().y);
			m_Element->SetDoubleAttribute("SonPosX", GameplayState::GetInstance()->GetSon()->GetPosition().x);
			m_Element->SetDoubleAttribute("SonPosY", GameplayState::GetInstance()->GetSon()->GetPosition().y);
			//m_Element->SetDoubleAttribute("SpawnPointX", GameplayState::GetInstance()->);
			//m_Element->SetDoubleAttribute("SpawnPointY", 0);
			m_Document.SaveFile("Save2");
		}

	}
	if (m_CursorPos == 2 && SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter))
	{
		TiXmlDocument m_Document;
		if (m_Document.LoadFile("Save3") == true)
		{
			TiXmlElement* m_Element = m_Document.RootElement();

			m_Element->SetDoubleAttribute("FatherPosX", GameplayState::GetInstance()->GetFather()->GetPosition().x);
			m_Element->SetDoubleAttribute("FatherPosY", GameplayState::GetInstance()->GetFather()->GetPosition().y);
			m_Element->SetDoubleAttribute("SonPosX", GameplayState::GetInstance()->GetSon()->GetPosition().x);
			m_Element->SetDoubleAttribute("SonPosY", GameplayState::GetInstance()->GetSon()->GetPosition().y);
			//m_Element->SetDoubleAttribute("SpawnPointX", GameplayState::GetInstance()->);
			//m_Element->SetDoubleAttribute("SpawnPointY", 0);
			m_Document.SaveFile("Save3");
		}

	}
	return true;
}

void SaveGameState::Render(float _ElapsedTime)
{
	Game::GetInstance()->GetFont().Draw("Save Game", SGD::Point{ 270.0f, 50.0f }, 0.75f);

	Game::GetInstance()->GetFont().Draw("Slot 1", SGD::Point{ 325.0f, 150.0f }, 0.5f);

	Game::GetInstance()->GetFont().Draw("Slot 2", SGD::Point{ 325.0f, 200.0f }, 0.5f);

	Game::GetInstance()->GetFont().Draw("Slot 3", SGD::Point{ 325.0f, 250.0f }, 0.5f);

	if (m_CursorPos == 0)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 160.0f), 0.0f, {}, SGD::Color(255, 153, 0));
	}
	else if (m_CursorPos == 1)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 210.0f), 0.0f, {}, SGD::Color(255, 153, 0));

	}
	else if (m_CursorPos == 2)
	{
		SGD::GraphicsManager::GetInstance()->DrawTexture(m_Pointer, SGD::Point(250.0f, 260.0f), 0.0f, {}, SGD::Color(255, 153, 0));
	}
	


}