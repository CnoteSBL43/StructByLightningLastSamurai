#pragma once

#include"../SGD Wrappers/SGD_Geometry.h"
class IGameState;

class Game
{
private:
	static Game* m_Instance;
	Game() = default;
	~Game() = default;
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	SGD::Size m_ScreenSize = SGD::Size{ 1024, 768 };
	IGameState* m_CurrentState = nullptr;
	unsigned long m_GameTime = 0;
public:
	//Singleton
	static Game* GetInstance();
	static void DeleteInstance();

	//Setup,Play,Cleanup
	bool Initialize();
	int Update();
	void Terminate();

	//State Mutator
	void ChangeState(IGameState* _NextState);

	SGD::Size GetScreenSize() const{ return m_ScreenSize; }

};

