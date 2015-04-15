#pragma once
#include <map>
#include "AnimationTimestamp.h"
#include "Animation.h"
#include "../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Geometry.h"
class AnimationSystem
{
private:
	SGD::GraphicsManager* GM = SGD::GraphicsManager::GetInstance();
	SGD::HTexture m_Img = SGD::INVALID_HANDLE;
	std::string m_ImgString, m_AnimationName;
	std::map<std::string, Animation> m_Loaded;
	//SGD::Rectangle m_Rect;
	std::vector<SGD::HTexture> m_Imgs;
	//Ctor and Dtor
	AnimationSystem() = default;
	~AnimationSystem() = default;
	AnimationSystem(const AnimationSystem&) = delete;
	AnimationSystem& operator=(const AnimationSystem&) = delete;
	int count = 0;
public:
	//Singleton
	static AnimationSystem* GetInstance();

	//Accessor
	std::map<std::string, Animation>& GetLoaded() { return m_Loaded; }
	SGD::Rectangle GetRect(const AnimationTimestamp& _info, int _PosX, int _PosY, SGD::Size _scale = { 1, 1 });
	SGD::Point GetParticlePt(AnimationTimestamp& info, int _X, int _Y, int _index);
	//SGD::Rectangle GetSonRect() { return m_SonRect; }
	//Methods

	void Update(int _elapsedtime, AnimationTimestamp& _info);
	void Render(AnimationTimestamp& _info, int _PosX, int _PosY, SGD::Size _scale = { 1, 1 });
	void Load(const char* _filename);
	void Exit();


};

