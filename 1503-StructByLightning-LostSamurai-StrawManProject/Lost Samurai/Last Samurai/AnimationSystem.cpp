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

SGD::Point AnimationSystem::GetParticlePt(AnimationTimestamp& _ts, int _X, int _Y, int _index)
{
	SGD::Point pt = m_Loaded[_ts.GetCurrAnim()].GetFrames()[_ts.GetCurrFrame()].GetParticlePt()[_index];
	pt.x += _X;
	pt.y += _Y;
	return pt;
}

void AnimationSystem::Render(AnimationTimestamp& _info, int _PosX, int _PosY, SGD::Size _scale)
{

	SGD::Point temppt = SGD::Point((float)_PosX, (float)_PosY);
	SGD::Point pt = m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].GetAnchorPt();
	SGD::Rectangle crect = m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetCollisionRect();
	//GM->DrawRectangle(GetRect(_info, _PosX, _PosY), SGD::Color(255, 0, 0));
	SGD::Rectangle rect = m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].GetDrawFrame();
	temppt.x += rect.left * _scale.width;
	temppt.y += rect.top * _scale.height;
	if (_info.GetOwner()->GetType() == Actor::ENT_FATHER)
		GM->DrawTextureSection(m_Imgs[0], temppt, SGD::Rectangle{ rect.left + pt.x, rect.top + pt.y, (rect.left + pt.x) + rect.ComputeWidth(), (rect.top + pt.y) + rect.ComputeHeight() }, 0.0f, {}, {}, _scale);
	if (_info.GetOwner()->GetType() == Actor::ENT_SON)
		GM->DrawTextureSection(m_Imgs[1], temppt, SGD::Rectangle{ rect.left + pt.x, rect.top + pt.y, (rect.left + pt.x) + rect.ComputeWidth(), (rect.top + pt.y) + rect.ComputeHeight() }, 0.0f, {}, {}, _scale);
	if (_info.GetOwner()->GetType() == Actor::ENT_CANNONBALL)
		GM->DrawTextureSection(m_Imgs[2], temppt, SGD::Rectangle{ rect.left + pt.x, rect.top + pt.y, (rect.left + pt.x) + rect.ComputeWidth(), (rect.top + pt.y) + rect.ComputeHeight() }, 0.0f, {}, {}, _scale);
	if (_info.GetOwner()->GetType() == Actor::ENT_ARROW)
		GM->DrawTextureSection(m_Imgs[3], temppt, SGD::Rectangle{ rect.left + pt.x, rect.top + pt.y, (rect.left + pt.x) + rect.ComputeWidth(), (rect.top + pt.y) + rect.ComputeHeight() }, 0.0f, {}, {}, _scale);
	if (_info.GetOwner()->GetType() == Actor::ENT_SWORDSMAN)
		GM->DrawTextureSection(m_Imgs[4], temppt, SGD::Rectangle{ rect.left + pt.x, rect.top + pt.y, (rect.left + pt.x) + rect.ComputeWidth(), (rect.top + pt.y) + rect.ComputeHeight() }, 0.0f, {}, {}, _scale);
}

void AnimationSystem::Update(int _ElaspedTime, AnimationTimestamp& _info)
{
	if (m_Loaded[_info.GetCurrAnim()].GetFrames().size() > (unsigned int)_info.GetCurrFrame())
	{
		if (m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetTriggerType() == "Event" && m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetTriggerName() != "None")
		{
			SGD::Event* tempevent = new SGD::Event(m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetTriggerName().c_str(), nullptr, this);
			tempevent->SendEventNow();
			delete tempevent;
			tempevent = nullptr;
		}
	}
}

SGD::Rectangle AnimationSystem::GetRect(const AnimationTimestamp& _info, int _PosX, int _PosY, SGD::Size _scale)
{
	SGD::Point pt = { (float)_PosX, (float)_PosY };
	SGD::Rectangle crect = m_Loaded[_info.GetCurrAnim()].GetFrames()[_info.GetCurrFrame()].GetCollisionRect();
	float x = crect.left + pt.x;
	float y = crect.top + pt.y;
	float width = (crect.left + pt.x) + crect.ComputeWidth() * _scale.width;
	float height = (crect.top + pt.y) + crect.ComputeHeight() * _scale.height;
	return SGD::Rectangle{ x, y, width, height };
}

void AnimationSystem::Load(const char * _filename)
{
	//Game::GetInstance()->GetFont().Draw("Loading", { Game::GetInstance()->GetScreenSize().width / 2, Game::GetInstance()->GetScreenSize().height / 2 }, 1, { 255, 255, 255, 255 });
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
			Draw = Draw->NextSiblingElement("Particles");
			TiXmlElement* Particles = Draw->FirstChildElement("ParticlePT");
			Frame frame;
			while (Particles != nullptr)
			{
				Particles->Attribute("X", &ptx);
				Particles->Attribute("Y", &pty);
				Particles = Particles->NextSiblingElement();
				frame.AddParticlePoint(SGD::Point{ (float)ptx, (float)pty });
			}
			Draw = Draw->NextSiblingElement("Time");
			Draw->Attribute("Time", &time);
			Draw = Draw->NextSiblingElement("Trigger");
			trigtype = Draw->Attribute("Type");
			trigname = Draw->Attribute("Name");
			Frames = Frames->NextSiblingElement();
			frame.SetDrawFrame(SGD::Rectangle{ (float)left, (float)top, (float)(left + width), (float)(top + height) });
			frame.SetAnchorPt(SGD::Point{ (float)x, (float)y });
			frame.SetCollisionRect(SGD::Rectangle{ SGD::Point((float)cleft, (float)ctop), SGD::Size((float)cwidth, (float)cheight) });
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

