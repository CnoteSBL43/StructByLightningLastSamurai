#pragma once
#include "IGameState.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <vector>
#include "../SGD Wrappers/SGD_Declarations.h"
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
	//*****************************************************************//
	// Game Entities

	// This is a Entity Manager that Pointer variable used to send things to the entity manager
	EntityManager* m_pEntities = nullptr;
	// This is an Actor Pointer variable named Father used to create the Father 
	Actor* father = nullptr;
	// This is an Actor Pointer variable named Son used to create the SOn 
	Actor* son = nullptr;
	//************************************
	// This is a Tle System Pointer Called load what this will do is 
	// get all of the nessecary variables and functions to render the Level on the screen 
	TileSystem* Load;
	// This is Currently not used at all (Do Not Use Unless Specified);
	SGD::Point m_start = { 0, 0 };
	
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
	// This is an Actor Pointer That creates the Father object
	Actor*  CreateFather(void);
	// This is an Actor Pointer that creates the SOn Object
	Actor* CreateSon(void);

	int checkx, checky;//check collision
	bool check = false; // check collision
	bool intersect = false;//check collision
	float POSOFCOLLISION=0;//checkcollision
	// This used to go into debug Mode;
	bool Debug = false;

	//collision might need to remove if not needed
	bool GetK(){ return k; }
	void SetK(bool _k){ k = _k; }
};