#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "Game.h"
#include "../resource/TinyXML/tinyxml.h"
#include "../resource/TinyXML/tinystr.h"
#include "Frame.h"
#include "Father.h"
#include "Son.h"
AnimationSystem* AnimationSystem::GetInstance()
{
	static AnimationSystem m_Instance;
	return &m_Instance;
}

void AnimationSystem::Render(AnimationTimestamp _info, int _PosX, int _PosY, SGD::Size _scale)
{
	SGD::Point temppt = SGD::Point((float)_PosX, (float)_PosY);
#if defined(_DEBUG)
	//GM->DrawRectangle(m_Loaded[m_String.c_str()].GetFrames()[0].GetCollisionRect(), SGD::Color(255, 0, 0));
#endif


	SGD::Point point = Game::GetInstance()->GetCameraPosition();
	//SGD::Point pointtwo = dynamic_cast<Father*>(_info.GetOwner())->GetPosition();
	//m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].SetCollisionRect(SGD::Rectangle{ (float)_PosX, (float)_PosY, (float)_PosX + 64, (float)_PosY + 100 });
	//if (dynamic_cast<Father*>(_info.GetOwner())->GetFacing() == true)
	//	m_FatherRect = SGD::Rectangle{ (float)_PosX - 64, (float)_PosY, (float)_PosX, (float)_PosY + 100 };
	//else
	//	m_FatherRect = SGD::Rectangle{ (float)_PosX, (float)_PosY, (float)_PosX + 64, (float)_PosY + 100 };
	if (_info.GetOwner()->GetType() == Father::ENT_FATHER)
		GM->DrawRectangle(m_FatherRect, SGD::Color(255, 0, 0));
	if (_info.GetOwner()->GetType() == Son::ENT_SON)
		GM->DrawRectangle(m_SonRect, SGD::Color(255, 0, 0));
	GM->DrawTextureSection(m_Img, temppt, m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].GetDrawFrame(), 0.0f, {}, {}, _scale);
}

void AnimationSystem::Update(int _ElaspedTime, AnimationTimestamp _info)
{
	if (_info.GetOwner() != nullptr)
	{
		if (_info.GetOwner()->GetType() == Father::ENT_FATHER)
		{
			SGD::Point point = dynamic_cast<Father*>(_info.GetOwner())->GetPosition();
			SGD::Point pointtwo = Game::GetInstance()->GetCameraPosition();
			if (dynamic_cast<Father*>(_info.GetOwner())->GetFacing() == true)
				m_FatherRect = { point.x - 84 - pointtwo.x, point.y - pointtwo.y, point.x - pointtwo.x, point.y + 100 - pointtwo.y };
			else
				m_FatherRect = { point.x - 64 - pointtwo.x, point.y - pointtwo.y, point.x + 16 - pointtwo.x, point.y + 100 - pointtwo.y };
		}
		if (_info.GetOwner()->GetType() == Son::ENT_SON)
		{
			SGD::Point point = dynamic_cast<Son*>(_info.GetOwner())->GetPosition();
			SGD::Point pointtwo = Game::GetInstance()->GetCameraPosition();
			if (dynamic_cast<Son*>(_info.GetOwner())->GetFacing() == true)
				m_SonRect = { point.x - 44 - pointtwo.x, point.y - pointtwo.y, point.x - pointtwo.x, point.y + 49 - pointtwo.y };
			else
				m_SonRect = { point.x - 44 - 22 - pointtwo.x, point.y - pointtwo.y, point.x - 22 - pointtwo.x, point.y + 49 - pointtwo.y };

		}
	}
}

void AnimationSystem::Load(const char * _filename)
{
	double left, top, width, height, cleft, ctop, cright, cbottom;
	double x, y;
	double ptx, pty;
	double time;
	TiXmlDocument doc;
	if (doc.LoadFile(_filename) == false)
		return;
	TiXmlElement* root = doc.RootElement();

	m_ImgString = root->Attribute("Image");
	root->Attribute("RectX", &cleft);
	root->Attribute("RectY", &ctop);
	root->Attribute("RectRight", &cright);
	root->Attribute("RectBottom", &cbottom);
	if (count == 0)
		m_FatherRect = SGD::Rectangle{ (float)cleft, (float)ctop, (float)cright, (float)cbottom };
	else if (count == 1)
		m_SonRect = SGD::Rectangle{ (float)cleft, (float)ctop, (float)cright, (float)cbottom };
	count += 1;
	TiXmlElement* Animation = root->FirstChildElement("Animation");
	while (Animation != nullptr)
	{
		TiXmlElement* Frames = Animation->FirstChildElement();
		m_AnimationName = Animation->Attribute("Name");
		while (Frames != nullptr)
		{
			TiXmlElement* Draw = Frames->FirstChildElement("Draw");
			Draw->Attribute("RectX", &left);
			Draw->Attribute("RectY", &top);
			Draw->Attribute("RectWidth", &width);
			Draw->Attribute("RectHeight", &height);
			Draw = Draw->NextSiblingElement("AnchorPT");
			Draw->Attribute("X", &x);
			Draw->Attribute("Y", &y);
			Draw = Draw->NextSiblingElement("ParticlePT");
			Draw->Attribute("X", &ptx);
			Draw->Attribute("Y", &pty);
			Draw = Draw->NextSiblingElement("Time");
			Draw->Attribute("Time", &time);
			Frames = Frames->NextSiblingElement();
			Frame frame;
			frame.SetDrawFrame(SGD::Rectangle{ (float)left, (float)top, (float)(left + width), (float)(top + height) });
			frame.SetAnchorPt(SGD::Point{ (float)x, (float)y });
			SGD::Point point = Game::GetInstance()->GetCameraPosition();
			//frame.SetCollisionRect(SGD::Rectangle{ (float)x, (float)y, (float)x + 64, (float)y + 64 });
			frame.SetParticlePt(SGD::Point{ (float)ptx, (float)pty });
			frame.SetTimer((float)time);
			if (m_AnimationName == "Idle")
			{
				m_Loaded[m_AnimationName].SetLooping(false);
			}
			else if (count == 1 && m_AnimationName == "Running")
			{
				m_Loaded[m_AnimationName].SetLooping(true);
			}
			else
			{
				m_Loaded[m_AnimationName].SetLooping(true);
			}
			m_Loaded[m_AnimationName].AddFrames(frame);
		}
		Animation = Animation->NextSiblingElement();
	}

	std::string str;
	str = "../resource/graphics/";
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (i != 20)
			i++;
		else
			str.append(m_ImgString);

	}

	m_Img = GM->LoadTexture(str.c_str());
	m_Imgs.push_back(m_Img);

}

void AnimationSystem::Exit()
{
	for (size_t i = 0; i < m_Imgs.size(); i++)
	{
		GM->UnloadTexture(m_Imgs[i]);
	}
}

