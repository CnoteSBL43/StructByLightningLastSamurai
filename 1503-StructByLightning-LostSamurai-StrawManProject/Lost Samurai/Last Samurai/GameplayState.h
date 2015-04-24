#pragma once
#include "IGameState.h"
#include"../SGD Wrappers/SGD_Handle.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include <vector>
#include "../SGD Wrappers/SGD_Declarations.h"
#include "ParticleManager.h"
#include "Cannon.h"
#include "DartCannon.h"
#include "PopUpSpikes.h"
#include "Ledges.h"


class Actor;
class EntityManager;
class TileSystem;
class Pulley;
class PressurePlate;
class Lever;
class AutoLockingDoor;

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
	SGD::HTexture m_FatherFaceImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_SonFaceImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_LedgeImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_SmallLedgeImage = SGD::INVALID_HANDLE;
	SGD::HTexture m_LeverImage = SGD::INVALID_HANDLE;
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
	Actor* m_Door;
	
	Pulley* p;
	PressurePlate* plate;
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

	
	bool movementTurnOff = false;

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
	Actor* CreateSwordsman(Actor* _player)const;
	Actor* CreateSpikes(int i) const;
	Actor* CreatePopUpSpikes(int i) const;
	Actor* CreateDarts(int i) const;
	Actor* CreateCannon(int i) const;
	Actor* CreateRocks(int i) const;
	Actor* CreateSmashingColumns(int i) const;
	Actor* CreateCannonBall(Cannon*);
	Actor* CreateArrow(DartCannon*);
	Actor* CreateDoor(int i) const;
	Actor* CreateLadder(int i) const;
	Actor* CreateRopes(int i) const;
	Actor* CreatePlates(int i) const;
	Actor* CreateBox(int i) const;
	Actor* CreateLevers(int i) const;
	Actor* CreateLedge(int i) const;
	Actor* CreateCheckPoint(int i) const;

	// This used to go into debug Mode;
	bool Debug = false;

	Actor*  GetFather(){ return father; }
	Actor* GetSon(){ return son; }
	//Culling Rect
	SGD::Rectangle CullingRect;

	float stiffnessValue = 0.8f;

	//lever bool
	bool lever = false;

	//win door rect
	SGD::Rectangle win;
	bool winbool = false;
	bool loosebool = false;
	bool GetMovementOff(){ return movementTurnOff; }
	void SetMovementOff(bool _off){ movementTurnOff = _off; }
	int leverID = 0;
};