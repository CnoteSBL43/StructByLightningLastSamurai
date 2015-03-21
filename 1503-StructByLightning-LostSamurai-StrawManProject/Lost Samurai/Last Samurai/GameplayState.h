#pragma once
#include "IGameState.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <vector>
class Actor;
class EntityManager;

#include "../SGD Wrappers/SGD_Geometry.h"
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
	//*****************************************************************//
	// Game Entities
	EntityManager*	m_pEntities = nullptr;
	Actor* m_player = nullptr;
	//************************************
	TileSystem* Load;
SGD::Point m_start = { 0, 0 };

public:
	static GameplayState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
	Actor*  CreateFather(void);


};

