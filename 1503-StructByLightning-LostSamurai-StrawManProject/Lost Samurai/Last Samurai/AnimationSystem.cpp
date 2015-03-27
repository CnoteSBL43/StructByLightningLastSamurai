#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "Game.h"
#include "../resource/TinyXML/tinyxml.h"
#include "../resource/TinyXML/tinystr.h"
#include "Frame.h"
#include "Father.h"
#include "Son.h"
#include "../SGD Wrappers/SGD_Event.h"

AnimationSystem* AnimationSystem::GetInstance()
{
	static AnimationSystem m_Instance;
	return &m_Instance;
}

SGD::Point AnimationSystem::GetParticlePt(int _frame, std::string _animationname)
{
	return m_Loaded[_animationname.c_str()].GetFrames()[_frame].GetAnchorPt();
}

void AnimationSystem::Render(AnimationTimestamp _info, int _PosX, int _PosY, SGD::Size _scale)
{
	SGD::Point temppt = SGD::Point((float)_PosX, (float)_PosY);
	SGD::Point pt = m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].GetAnchorPt();
	SGD::Rectangle crect = m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetCollisionRect();
	GM->DrawRectangle(GetRect(_info, _PosX, _PosY), SGD::Color(255, 0, 0));
	SGD::Rectangle rect = m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].GetDrawFrame();
	temppt.x += rect.left * _scale.width;
	temppt.y += rect.top * _scale.height;
	GM->DrawTextureSection(m_Img, temppt, SGD::Rectangle{ rect.left + pt.x, rect.top + pt.y, (rect.left + pt.x) + rect.ComputeWidth(), (rect.top + pt.y) + rect.ComputeHeight() }, 0.0f, {}, {}, _scale);
}

void AnimationSystem::Update(int _ElaspedTime, AnimationTimestamp _info)
{
	if (m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetTriggerType() == "Event" && m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetTriggerName() != "None")
	{
		SGD::Event* tempevent = new SGD::Event(m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetTriggerName().c_str(),nullptr,this);
		tempevent->SendEventNow();
		delete tempevent;
		tempevent = nullptr;
	}
}

SGD::Rectangle AnimationSystem::GetRect(AnimationTimestamp _info, int _PosX, int _PosY)
{

	SGD::Point point = Game::GetInstance()->GetCameraPosition();
	SGD::Point pt = m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].GetAnchorPt();
	SGD::Rectangle crect = m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetCollisionRect();
	return SGD::Rectangle{ crect.left + _PosX, crect.top + _PosY, (crect.left + _PosX) + crect.ComputeWidth(), (crect.top + _PosY) + crect.ComputeHeight() };
}

void AnimationSystem::Load(const char * _filename)
{
	double left, top, width, height, cleft, ctop, cheight, cwidth;
	double x, y;
	double ptx, pty;
	double time;
	std::string trigtype;
	std::string trigname;
	TiXmlDocument doc;
	if (doc.LoadFile(_filename) == false)
		return;
	TiXmlElement* root = doc.RootElement();
	m_ImgString = root->Attribute("Image");

#pragma region XML

	/*root->Attribute("RectX", &cleft);
	root->Attribute("RectY", &ctop);
	root->Attribute("RectRight", &cright);
	root->Attribute("RectBottom", &cbottom);
	if (count == 0)
	m_FatherRect = SGD::Rectangle{ (float)cleft, (float)ctop, (float)cright, (float)cbottom };
	else if (count == 1)
	m_SonRect = SGD::Rectangle{ (float)cleft, (float)ctop, (float)cright, (float)cbottom };
	count += 1;*/

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
			Draw = Draw->NextSiblingElement("Collision");
			Draw->Attribute("RectX", &cleft);
			Draw->Attribute("RectY", &ctop);
			Draw->Attribute("RectWidth", &cwidth);
			Draw->Attribute("RectHeight", &cheight);
			Draw = Draw->NextSiblingElement("AnchorPT");
			Draw->Attribute("X", &x);
			Draw->Attribute("Y", &y);
			Draw = Draw->NextSiblingElement("ParticlePT");
			Draw->Attribute("X", &ptx);
			Draw->Attribute("Y", &pty);
			Draw = Draw->NextSiblingElement("Time");
			Draw->Attribute("Time", &time);
			Draw = Draw->NextSiblingElement("Trigger");
			trigtype = Draw->Attribute("Type");
			trigname = Draw->Attribute("Name");
			Frames = Frames->NextSiblingElement();
			Frame frame;
			frame.SetDrawFrame(SGD::Rectangle{ (float)left, (float)top, (float)(left + width), (float)(top + height) });
			frame.SetAnchorPt(SGD::Point{ (float)x, (float)y });
			SGD::Point point = Game::GetInstance()->GetCameraPosition();
			frame.SetCollisionRect(SGD::Rectangle{ (float)cleft, (float)ctop, (float)(cleft + cwidth), (float)(ctop + cheight) });
			frame.SetParticlePt(SGD::Point{ (float)ptx, (float)pty });
			frame.SetTimer((float)time);
			frame.SetTriggerType(trigtype);
			frame.SetTriggerName(trigname);
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
#pragma endregion 
}

void AnimationSystem::Exit()
{
	for (size_t i = 0; i < m_Imgs.size(); i++)
	{
		GM->UnloadTexture(m_Imgs[i]);
	}
}

