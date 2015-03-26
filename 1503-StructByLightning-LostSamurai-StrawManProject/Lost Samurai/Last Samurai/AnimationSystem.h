#pragma once
#include <map>
#include "AnimationTimestamp.h"
#include "Animation.h"
#include "../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
class AnimationSystem
{
private:
	SGD::GraphicsManager* GM = SGD::GraphicsManager::GetInstance();
	SGD::HTexture m_Img = SGD::INVALID_HANDLE;
	std::string m_ImgString, m_AnimationName;
	std::map<std::string, Animation> m_Loaded;
	//Ctor and Dtor
	AnimationSystem() = default;
	~AnimationSystem() = default;
	AnimationSystem(const AnimationSystem&) = delete;
	AnimationSystem& operator=(const AnimationSystem&) = delete;
public:
	//Singleton
	static AnimationSystem* GetInstance();
	

	//Methods

	void Update(int _elapsedtime, AnimationTimestamp _info);
	void Render(AnimationTimestamp _info, int _PosX, int _PosY, SGD::Size _scale = { 1, 1 });
	void Load();
	void Exit();


};

