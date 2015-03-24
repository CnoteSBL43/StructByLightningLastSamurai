#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../resource/TinyXML/tinyxml.h"
#include "../resource/TinyXML/tinystr.h"
#include "Frame.h"

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

	GM->DrawTextureSection(m_Img, temppt, m_Loaded[_info.GetCurrAnim().c_str()].GetFrames()[_info.GetCurrFrame()].GetDrawFrame(), 0.0f, {}, {}, _scale);

}

void AnimationSystem::Update(int _ElaspedTime, AnimationTimestamp _info)
{

}

void AnimationSystem::Load()
{
	double left, top, width, height;
	double x, y;
	double ptx, pty;
	double time;
	TiXmlDocument doc;
	if (doc.LoadFile("../anim.xml") == false)
		return;
	TiXmlElement* root = doc.RootElement();

	m_ImgString = root->Attribute("Image");
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
			frame.SetParticlePt(SGD::Point{ (float)ptx, (float)pty });
			frame.SetTimer((float)time);
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


}

void AnimationSystem::Exit()
{
	GM->UnloadTexture(m_Img);
}

