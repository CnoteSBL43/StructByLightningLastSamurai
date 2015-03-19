#pragma once

#include"../SGD Wrappers/SGD_Geometry.h"

class IGameState;
class TileSystem;
class Game
{
private:
	// A Static Instance of a Game pointer m_Instance to make a singleton
	static Game* m_Instance;
	// Game() Is a Defualt Constructor
	Game() = default;
	// This is Games Destructor and it is set to default
	~Game() = default;
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	SGD::Size m_ScreenSize = SGD::Size{ 1024, 800 };
	IGameState* m_CurrentState = nullptr;


	// Practice TileSystem Xml

	TileSystem* TIleXMl;
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

