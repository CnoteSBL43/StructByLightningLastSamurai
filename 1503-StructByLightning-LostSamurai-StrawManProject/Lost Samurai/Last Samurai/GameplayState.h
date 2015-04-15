#pragma once
#include "IGameState.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <vector>
#include "../SGD Wrappers/SGD_Declarations.h"
#include "ParticleManager.h"
#include "Cannon.h"


class Actor;
class EntityManager;
class TileSystem;
class GameplayState :
	public IGameState
{
private:
	// this is the default Constructor 
	GameplayState() = default;
	// this is a default Deconstructor
	~GameplayState() = default;
	// this is a make shift Copy Constructor 
	GameplayState(const GameplayState&) = delete;
	// this is a make shift  Assignment Operator 
	GameplayState& operator= (const GameplayState&) = delete;
	// This is an Haudio used for the main menu 
	SGD::HAudio m_SFX = SGD::INVALID_HANDLE;
	// this is a Htexture used to Render the fathers image 
	SGD::HTexture m_FatherImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_PointerImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_SpikesImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_CannonImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_DartTrapImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_CannonBallImage = SGD::INVALID_HANDLE;
	//*****************************************************************//
	// Game Entities

	// This is a Entity Manager that Pointer variable used to send things to the entity manager
	EntityManager* m_pEntities = nullptr;
	ParticleManager* m_ParticleManager = nullptr;
	// This is an Actor Pointer variable named Father used to create the Father 
	Actor* father = nullptr;
	// This is an Actor Pointer variable named Son used to create the SOn 
	Actor* son = nullptr;
	Actor* m_Spikes = nullptr;
	Actor* m_Cannon = nullptr;
	//************************************
	// This is a Tle System Pointer Called load what this will do is 
	// get all of the nessecary variables and functions to render the Level on the screen 
	TileSystem* Load;
	// This is Currently not used at all (Do Not Use Unless Specified);
	SGD::Point m_start = { 0, 0 };
	//******Pause*****//
	bool m_Pause = false;
	int cursorPos = 0;
	
	SGD::HAudio m_Backround;
	// This is a function for the message proc so that you can send messages 
	static void MessageProc(const SGD::Message* pMsg);

	///collision might need to remove if not used
	bool k = false;

public:
	// this is a Gamplaystate Pointer function used to  make a singleton 
	static GameplayState* GetInstance();
	// This is a Function used to enter the gameplay state
	void Enter(void);
	// this is used to exit the gameplaystate
	void Exit(void);
	// this is the update function that Takes in a float to make the objects simulate movement
	bool Update(float _ElapsedTime);
	// This is a function for Render that takes in a float to the objects to simulate movement
	void Render(float _ElapsedTime);
	//*****PAUSE******//
	void RenderPause(void);
	void Pause(void);
	TileSystem* GetTileSystem() { return Load; }
	// This is an Actor Pointer That creates the Father object
	Actor*  CreateFather(void);
	// This is an Actor Pointer that creates the SOn Object
	Actor* CreateSon(void);
	Actor* CreateSwordsman(Actor* _player)const ;
	Actor* CreateSpikes(int i) const;
	Actor* CreateDarts(int i) const;
	Actor* CreateCannon(int i) const;
	Actor* CreateRocks(int i) const;
	Actor* CreateSmashingColumns(int i) const;
	Actor* CreateCannonBall(Cannon*);
	int checkx, checky;//check collision
	bool check = false; // check collision
	bool intersect = false;//check collision
	float POSOFCOLLISION=0;//checkcollision
	// This used to go into debug Mode;
	bool Debug = false;

	//collision might need to remove if not needed
	bool GetK(){ return k; }
	void SetK(bool _k){ k = _k; }

	Actor*  GetFather(){ return father; }
	Actor* GetSon(){ return son; }
	//Culling Rect
	SGD::Rectangle CullingRect;

};