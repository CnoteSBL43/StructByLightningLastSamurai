#pragma once
#include "IGameState.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <vector>
#include "../SGD Wrappers/SGD_Declarations.h"
#include "ParticleManager.h"

class Actor;
class EntityManager;
class TileSystem;
class GameplayState :
	public IGameState
{
private:
	GameplayState() = default;
	~GameplayState() = default;
	GameplayState(const GameplayState&) = delete;
	GameplayState& operator= (const GameplayState&) = delete;
	SGD::HAudio m_SFX = SGD::INVALID_HANDLE;
	SGD::HTexture m_FatherImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_PauseImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_PointerImage = SGD::INVALID_HANDLE;
	//*****************************************************************//
	// Game Entities
	EntityManager* m_pEntities = nullptr;
	ParticleManager* m_ParticleManager = nullptr;
	Actor* father = nullptr;
	Actor* son = nullptr;
	Actor* swordsman = nullptr;
	//************************************
	TileSystem* Load;
	SGD::Point m_start = { 0, 0 };
	//******Pause*****//
	bool m_Pause = false;
	int cursorPos = 0;
	


	static void MessageProc(const SGD::Message* pMsg);
public:
	static GameplayState* GetInstance();
	void Enter(void);
	void Exit(void);
	bool Update(float _ElapsedTime);
	void Render(float _ElapsedTime);
	//*****PAUSE******//
	void RenderPause(void);
	void Pause(void);

	Actor*  CreateFather(void);
	Actor* CreateSon(void);
	Actor* CreateSwordsman(void);
};