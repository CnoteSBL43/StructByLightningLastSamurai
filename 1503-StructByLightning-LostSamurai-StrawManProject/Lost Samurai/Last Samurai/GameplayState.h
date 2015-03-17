#pragma once
#include "IGameState.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <vector>
class Actor;
class EntityManager;

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
	SGD::HTexture m_BgImage = SGD::INVALID_HANDLE;


	EntityManager*	m_pEntities = nullptr;
	Actor* father = nullptr;
	Actor* son = nullptr;
	

public:
	static GameplayState* GetInstance();
	void	Enter(void);
	void	Exit(void);

	bool	Update(float _ElapsedTime);
	void	Render(float _ElapsedTime);
	Actor*  CreateFather(void);
	Actor*	CreateSon(void);


};

