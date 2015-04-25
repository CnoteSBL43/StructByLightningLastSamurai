#pragma once
#include "GameplayState.h"
#include "Father.h"
#include "Game.h"
#include "Son.h"
#include "Swordsman.h"
#include "Pulley.h"
#include "Actor.h"
#include "SaveGameState.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Message.h"
#include "PressurePlate.h"
#include "MainMenuState.h"
#include "MessageID.h"
#include "EntityManager.h"
#include "../Last Samurai/TileSystem.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_MessageManager.h"
#include "Tile.h"
#include "Spike.h"
#include "Cannon.h"
#include "Arrow.h"
#include "DartCannon.h"
#include <sstream>
#include "Ladder.h"
#include "Box.h"
#include "DestroyActorMessage.h"
#include "CannonBall.h"
#include "CreateCannonBallMessage.h"
#include "CreateArrowMessage.h"
#include "PopUpSpikes.h"
#include "PressurePlate.h"
#include "Pulley.h"
#include "CreateSwordMan.h"
#include "Ledges.h"
#include "Lever.h"
#include "AutoLockingDoor.h"
#include "CheckPoint.h"
#include"LoadGameState.h"
#include "FinalDoor.h"
#include "RollingBoulder.h"
//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: GetInstance
//	Parameters: None
//	Return type: GameplayState* - (An GamePlayState Pointer);
//  What it is used for:
// this is used to make a singleton 
//
//*********************************************************************//

GameplayState* GameplayState::GetInstance()
{
	// this is a Global Static GameplayState Getinsatnce to Make a SingleTon
	static GameplayState m_Instance;
	// you are going to return the Refernce of that static singleton 
	return &m_Instance;
}


//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: CreateFather
//	Parameters: None
//	Return type: Actor* - (An Actor Pointer);
//  What it is used for:
// this is used to make the father object and then send it to the entitymanager
//
//*********************************************************************//
Actor* GameplayState::CreateFather(void)
{
	// This is Makeing a Father Player Pointer to Create a Father Object
	Player* m_father = new Father;
	// Underneath is The Father set Position It is Currently commented out so that XML can make the Spawn point
	//father->SetPosition(SGD::Point{ 100.0f, 480.0f });
	// this is Setting the Fathers State to alive so that we can determine wether or not He is dead or Alive
	m_father->SetAlive(true);
	// This is setting the image to the the father Object so that he can aPpear on the scrren with a Png
	m_father->SetImage(m_FatherImage);
	// This is Used to set the Father objects size So that we can use Calculations to get Certain things to work 
	//father->SetSize(SGD::Size{ 64.0f, 64.0f });
	// This is Setting the Fathers Object Velocity so that when pressed a certain movement button his velocity will increase 
	m_father->SetVelocity({ 0.0f, 0.0f });
	// This is setting wether or not the father is stating on the ground so then if he is he can jump or perform other actions
	m_father->SetOnGround(false);
	m_father->SetWeight(100.0f);
	// this is returning the newly alocated Father object so that it can be sent into the entity manager
	return m_father;
}

//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: CreateSon
//	Parameters: None
//	Return type: Actor* - (An Actor Pointer);
//  What it is used for:
// It is used to Create the Son Object and then place it in the entity manager
//
//*********************************************************************//
Actor* GameplayState::CreateSon(void)
{
	// This is a Player Pointer that is being new alocated to make a Son Object
	Player* m_son = new Son;
	// Underneath is The Son set Position It is Currently commented out so that XML can make the Spawn point
	//son->SetPosition(SGD::Point{ 700.0f, 540.0f });
	// this is setting the son to Alive so that we can determine wether or not he is dead later on 
	m_son->SetAlive(true);
	// This is setting the Sons image so that He can render with a texture on the screen 
	m_son->SetImage(m_FatherImage);
	// This setting the sons size so that we can do calculations later on to do things 
	//son->SetSize(SGD::Size{ -0.75f, 0.75f });
	// This is setting the Sons velocity so that we can use the Velocity later when the Son moves 
	m_son->SetVelocity({ 0.0f, 0.0f });
	// This is used to know if the son is on the ground or not so that we can use other functions such as jump 
	m_son->SetOnGround(false);
	m_son->SetWeight(50.0f);
	// this is returning a newly alocated Son object so that it can be sent to the entity manager
	return m_son;
}
Actor* GameplayState::CreateSwordsman(Actor* _player, int i) const
{
	Swordsman * swordsman = new Swordsman;
	swordsman->SetPosition({ Load->Traps["AI"][i]->left - 800.0f, Load->Traps["AI"][i]->top - 270});
	swordsman->m_LeftMax = { Load->Traps["WayPoint"][0]->left - 800, Load->Traps["WayPoint"][0]->top - 300 };
	swordsman->m_RightMax = { Load->Traps["WayPoint"][1]->left, Load->Traps["WayPoint"][1]->top - 300 };

	swordsman->SetAlive(true);
	//swordsman->SetImage(m_FatherImage);
	swordsman->SetSize(SGD::Size{ -1.5f, 1.5f });
	swordsman->SetVelocity({ 64.0f, 0.0f });
	dynamic_cast<Swordsman*>(swordsman)->SetTarget((Player*)_player);
	return swordsman;
}

Actor* GameplayState::CreateLedge(int i) const
{
	Ledges* ledge = new Ledges;
	ledge->SetPosition(SGD::Point{ Load->Traps["Ledges"][i]->left - 400.0f, Load->Traps["Ledges"][i]->top });
	ledge->SetSize({ Load->Traps["Ledges"][i]->right - Load->Traps["Ledges"][i]->left, 8.0f });
	SGD::Rectangle r = ledge->GetRect();
	if (r.ComputeWidth() == 64.0f)
	{
		ledge->isBig = true;
		ledge->SetImage(m_LedgeImage);
	}
	else
	{
		ledge->isBig = false;
		ledge->SetImage(m_SmallLedgeImage);
	}
	return ledge;
}


Actor* GameplayState::CreateCheckPoint(int i) const
{
	CheckPoint* checkpoint = new CheckPoint;
	checkpoint->SetPosition(Load->m_CheckPoints[i]->GetPosition());
	checkpoint->SetSize(Load->m_CheckPoints[i]->GetSize());
	return checkpoint;
}

Actor* GameplayState::CreateLadder(int i) const
{
	Ladder* ladder = new Ladder;
	ladder->SetPosition({ Load->Traps["Ladder"][i]->left - 832, Load->Traps["Ladder"][i]->top - 300 });
	ladder->SetSize({ 60, 224 });
	ladder->SetImage(m_LadderImage);
	return ladder;
}

//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: Enter
//	Parameters: None
//	Return type: void 
//  What it is used for:
// It is used to Set all of the variables you will need when you enter this state 
//
//*********************************************************************//
void GameplayState::Enter()
{
	SGD::MessageManager::GetInstance()->Initialize(&MessageProc);
	m_FatherImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Father.png");
	m_PointerImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Finger.png");
	m_SpikesImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/1_0.png");
	m_CannonImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/canon.png");
	m_DartTrapImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/darttrap.png");
	m_FatherFaceImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/FatherHead.png");
	m_SonFaceImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/SonHead.png");
	m_LedgeImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/bigledge.png");
	m_SmallLedgeImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/smallledge.png");
	m_LeverImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Lever.png");
	m_LadderImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Ladder.png");
	m_SwitchSound = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/switching characters.wav");
	m_PickingUPSon = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/backpack.wav");
	m_Movement = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/cursormove.wav");
	Select = SGD::AudioManager::GetInstance()->LoadAudio(L"../resource/audio/confirm.wav");
	//m_CannonBallImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/ball.png");
	// You are making a newly alocated entity manager so it can hold all differnt sort of things such as the Father and son and Enemies
	m_pEntities = new EntityManager;
	AnimationSystem::GetInstance()->Load("../resource/XML/FatherAnimations.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/SonAnimations.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/Cannonball.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/Arrow.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/Swordsman.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/Doors.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/Archer.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/SmashingColumns.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/FallingRocks.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/RollingBoulder.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/popupspikes.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/Lever.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/PressurePlate.xml");


	m_Backround = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/Game_Music.xwm");
	m_Backround = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/tutorial.xwm");
	SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::Music, Game::GetInstance()->GetMusicVolume());
	SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::SoundEffects, Game::GetInstance()->GetSFXVolume());
	SGD::AudioManager::GetInstance()->PlayAudio(m_Backround, true);
	father = CreateFather();
	m_pEntities->AddEntity(father, 0);
	son = CreateSon();
	m_pEntities->AddEntity(son, 1);
	Load = new TileSystem();
	//m_ParticleManager->LoadEmitter("../resource/XML/StepParticles.xml");
	//m_ParticleManager->LoadEmitter("../resource/XML/LandParticles.xml");
	//m_ParticleManager->LoadEmitter("../resource/XML/BackParticles.xml");
	//m_ParticleManager->LoadEmitter("../resource/XML/BloodParticles.xml");

	if (Game::GetInstance()->GetLevel()==1)
		Load->LoadTileXml((Father*)father, (Son*)son, "../resource/XML/Level 1.xml");
	else if (Game::GetInstance()->GetLevel() == 2)
		Load->LoadTileXml((Father*)father, (Son*)son, "../resource/XML/Level 2.xml");
	else if (Game::GetInstance()->GetLevel() == 3)
		Load->LoadTileXml((Father*)father, (Son*)son, "../resource/XML/Level 3.xml");
	else if (Game::GetInstance()->GetLevel() == 4)
		Load->LoadTileXml((Father*)father, (Son*)son, "../resource/XML/Level 4.xml");

	//p = new Pulley(200, 20, SGD::Vector(540, 900));//2840 660

	if (!Game::GetInstance()->changelevel)
		Load->LoadTileXml((Father*)father, (Son*)son,"../resource/XML/TutorialLevel.xml");
	else
		Load->LoadTileXml((Father*)father, (Son*)son, "../resource/XML/Level1.xml");
	
	p = new Pulley(200, 20, SGD::Vector(540, 900));//2840 660
	
	for (unsigned int i = 0; i < Load->m_CollisionRect.size(); i++)
		m_pEntities->AddEntity(Load->m_CollisionRect[i], 3);

	for (unsigned int i = 0; i < Load->m_Deathcollision.size(); i++)
		m_pEntities->AddEntity(Load->m_Deathcollision[i], 4);

	for (unsigned int i = 0; i < Load->Traps["Spikes"].size(); i++)
	{
		m_Spikes = CreateSpikes(i);
		m_pEntities->AddEntity(m_Spikes, 5);
		//m_Spikes->Release();
	}
	for (unsigned int i = 0; i < Load->Traps["Ledges"].size(); i++)
	{
		Actor* temp = CreateLedge(i);
		m_pEntities->AddEntity(temp, 5);
		temp->Release();

	}
	for (unsigned int i = 0; i < Load->Traps["Boulder"].size(); i++)
	{
		Actor* temp = CreateRollingBoulder(i);
		m_pEntities->AddEntity(temp, 5);
		temp->Release();
	}
	for (unsigned int i = 0; i < Load->Traps["Cannon"].size(); i++)
	{
		Actor* temp = CreateCannon(i);
		m_pEntities->AddEntity(temp, 5);
		temp->Release();
	}

	for (unsigned int i = 0; i < Load->Traps["darts"].size(); i++)
	{
		Actor* temp = CreateDarts(i);
		m_pEntities->AddEntity(temp, 5);
		temp->Release();
	}
	for (unsigned int i = 0; i < Load->Traps["PopSpikes"].size(); i++)
	{
		Actor* temp = CreatePopUpSpikes(i);
		m_pEntities->AddEntity(temp, 5);
		temp->Release();
		temp->Release();
	}

	for (unsigned int i = 0; i < Load->Traps["Doors"].size(); i++)
	{
		Actor* temp = CreateDoor(i);
		m_pEntities->AddEntity(temp, 5);
		temp->Release();
		temp->Release();
	}
	for (unsigned int i = 0; i < Load->Traps["Box"].size(); i++)
	{
		Actor* temp = CreateBox(i);
		m_pEntities->AddEntity(temp, 16);
		temp->Release();

	}
	for (unsigned int i = 0; i < Load->Traps["Levers"].size(); i++)
	{
		leverID++;
		Actor* temp = CreateLevers(i);
		m_pEntities->AddEntity(temp, 15);
		temp->Release();
		temp->Release();

	}
	for (unsigned int i = 0; i < Load->Traps["Plates"].size(); i++)
	{
		leverID++;
		Actor* temp = CreatePlates(i);
		m_pEntities->AddEntity(temp, 5);
		temp->Release();
		temp->Release();

	}
	for (unsigned int i = 0; i < Load->Traps["Ladder"].size(); i++)
	{
		Actor* temp = CreateLadder(i);
		m_pEntities->AddEntity(temp, 14);
		temp->Release();
	}
	for (unsigned int i = 0; i < Load->Traps["FinalDoor"].size(); i++)
	{
		Actor* temp = CreateFinalDoor(i);
		m_pEntities->AddEntity(temp, 18);
		win = temp->GetRect();
		temp->Release();
	}
	for (unsigned int i = 0; i < Load->Traps["AI"].size(); i++)
	{
		Actor* temp = CreateSwordsman(father, i);
		m_pEntities->AddEntity(temp, 5);
		//win = temp->GetRect();
		temp->Release();
		temp->Release();
	}
	unsigned int length = Load->m_CheckPoints.size();

	for (unsigned int i = 0; i < length; i++)
	{
		m_pEntities->AddEntity(CreateCheckPoint(i), 5);
	}

	Game::GetInstance()->SetCameraPosition({ father->GetPosition().x, father->GetPosition().y });
	Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraPosition().x, Game::GetInstance()->GetCameraPosition().y });
	Game::GetInstance()->SetCameraDestinationVector({ father->GetPosition().x, father->GetPosition().y });

}

//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: Exit
//	Parameters: None
//	Return type: void 
//  What it is used for:
//  To exit the certain Gameplayste and terminate,release all of the variables used 
// in this state
//*********************************************************************//
void GameplayState::Exit()
{
	leverID = plateID = 0;
	// This is terminating the Father image so that you will not have any memory leaks 
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_PointerImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_SpikesImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_CannonImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_DartTrapImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_CannonBallImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherFaceImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_SonFaceImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_LedgeImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_SmallLedgeImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_LeverImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_LadderImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_SmallBoxImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_BigBoxImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FinalDoorImage);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_Backround);
	
	m_Pause = false;
	cursorPos = 0;
	// Father is being released from the Pointer it was associated with so that The Release function
	// Can take car of all dynamic memory 

	// this is an if Check makeing sure that m_pEntities are not null so that it can properly Erase everytihng that is inside of it 
	if (m_pEntities != nullptr)
	{
		//  this is Removing all of the Objects inside the entity Manager.
		m_pEntities->RemoveAll();
		// After removing all of the Objects in the Entity Manager You will delete the m_PEntites Pointer 
		delete m_pEntities;
		// after you release the father you are going to set him to a nullptr just in case so that you can make sure he is reslly null (Safe Check) 
		m_pEntities = nullptr;
		// this will delete load and everything inside the Alocated Tile system Pointer
		delete Load;
	}
	father->UltimateRelease();
	// after you release the father you are going to set him to a nullptr just in case so that you can make sure he is reslly null (Safe Check)
	father = nullptr;
	// Son is being released from the Pointer it was associated with so that The Release function
	// Can take car of all dynamic memory 
	son->UltimateRelease();
	// after you release the father you are going to set him to a nullptr just in case so that you can make sure he is reslly null (Safe Check)
	son = nullptr;
	Game::GetInstance()->SetCameraPosition(SGD::Point{ 0.0f, 0.0f });
	SGD::MessageManager::GetInstance()->Terminate();

	//delete p;
	//p = nullptr;
	SGD::MessageManager::DeleteInstance();
	//m_ParticleManager->FreeEmitter(0);
	//m_ParticleManager->FreeEmitter(1);
	//m_ParticleManager->FreeEmitter(2);
	//m_ParticleManager->FreeEmitter(3);
	//delete m_ParticleManager;
}


//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: Update
//	Parameters: float _ElapsedTime
//	Return type: void 
//  What it is used for:
// Update is used to Update all of the things on the screen to make them simulate movement
//
//*********************************************************************//
bool GameplayState::Update(float _ElapsedTime)
{


	// This is an if Check that turn on and off Debug mode for the Tile Collison 
	// If you Press F3 and the Bool Called Debug is False you Will set it to true 
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false || SGD::InputManager::GetInstance()->IsButtonPressed(0, 8) && Debug == false)
	{
		// this is setting Debug to true so that it can turn on Debug mode 
		Debug = true;
	}
	//  this is an Else if check that is basically doing the same thing but in reverse 
	// so that you Can press F3 again this time the bool Debug is True 
	// thus Turung off debug mode so that you can look at the normal level
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true || SGD::InputManager::GetInstance()->IsButtonPressed(0, 8) && Debug == true)
		// this is Setting the Debug Boolean to false. 
		Debug = false;

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape) || SGD::InputManager::GetInstance()->IsButtonPressed(0, 9))
	{
		if (!m_Pause)
			m_Pause = true;
		else
			m_Pause = false;
	}

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Q))
	{
		Game::GetInstance()->cameraPanningOn = !Game::GetInstance()->cameraPanningOn;
	}
	if (m_Pause)
		Pause();
	else
	{
		if (Game::GetInstance()->cameraPanningOn)
		{
			SGD::Point pt = Game::GetInstance()->GetCameraPosition();
			if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::W))
			{
				pt.y -= 2.0f;
				Game::GetInstance()->SetCameraPosition(pt);
			}
			if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::S))
			{
				pt.y += 2.0f;
				Game::GetInstance()->SetCameraPosition(pt);
			}
			if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::A))
			{
				pt.x -= 2.0f;
				Game::GetInstance()->SetCameraPosition(pt);
			}
			if (SGD::InputManager::GetInstance()->IsKeyDown(SGD::Key::D))
			{
				pt.x += 2.0f;
				Game::GetInstance()->SetCameraPosition(pt);
			}
			CullingRect.left = Game::GetInstance()->GetCameraPosition().x;
			CullingRect.top = Game::GetInstance()->GetCameraPosition().y;
			CullingRect.right = CullingRect.left + Game::GetInstance()->GetScreenSize().width;
			CullingRect.bottom = CullingRect.top + Game::GetInstance()->GetScreenSize().height;
		}
		else
		{
		if (Game::GetInstance()->GetCameraPosVector() != Game::GetInstance()->GetCameraDestinationVector())
		{
			float xIncrement, yIncrement;
			xIncrement = 5.0f;
			yIncrement = 3.0f;
			/*float xDistance = Game::GetInstance()->GetCameraDestinationVector().x - Game::GetInstance()->GetCameraPosVector().x;
			fabs(xDistance);
			float yDistance = Game::GetInstance()->GetCameraDestinationVector().y - Game::GetInstance()->GetCameraPosVector().y;
			fabs(yDistance);
			if (xDistance > yDistance)
			{
			xIncrement = 8.0f;
			yIncrement = 3.0f;
			}
			else 
			{
			xIncrement = 3.0f;
			yIncrement = 6.0f;
			}*/
			if (Game::GetInstance()->GetCameraPosVector().x < Game::GetInstance()->GetCameraDestinationVector().x)
			{

					Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraPosVector().x + xIncrement, Game::GetInstance()->GetCameraPosVector().y });
					if (Game::GetInstance()->GetCameraDestinationVector().x - Game::GetInstance()->GetCameraPosVector().x <= 1.0f)
					{
						Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraDestinationVector().x, Game::GetInstance()->GetCameraPosVector().y });
					}
				}
				else if (Game::GetInstance()->GetCameraPosVector().x > Game::GetInstance()->GetCameraDestinationVector().x)
				{
					Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraPosVector().x - xIncrement, Game::GetInstance()->GetCameraPosVector().y });
					if (Game::GetInstance()->GetCameraPosVector().x - Game::GetInstance()->GetCameraDestinationVector().x <= 1.0f)
					{
						Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraDestinationVector().x, Game::GetInstance()->GetCameraPosVector().y });
					}
				}
				if (Game::GetInstance()->GetCameraPosVector().y < Game::GetInstance()->GetCameraDestinationVector().y)
				{
					Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraPosVector().x, Game::GetInstance()->GetCameraPosVector().y + yIncrement });
					if (Game::GetInstance()->GetCameraDestinationVector().y - Game::GetInstance()->GetCameraPosVector().y <= 1.0f)
					{
						Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraPosVector().x, Game::GetInstance()->GetCameraDestinationVector().y });
					}
				}
				else if (Game::GetInstance()->GetCameraPosVector().y > Game::GetInstance()->GetCameraDestinationVector().y)
				{
					Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraPosVector().x, Game::GetInstance()->GetCameraPosVector().y - yIncrement });
					if (Game::GetInstance()->GetCameraPosVector().y - Game::GetInstance()->GetCameraDestinationVector().y <= 1.0f)
					{
						Game::GetInstance()->SetCameraPosVector({ Game::GetInstance()->GetCameraPosVector().x, Game::GetInstance()->GetCameraDestinationVector().y });
						Game::GetInstance()->SetCameraDestinationVector({ father->GetPosition().x, father->GetPosition().y });

					}
				}
			}
			if (dynamic_cast<Father*>(father)->GetCurrCharacter())
			{
				Game::GetInstance()->SetCameraPosition(SGD::Point{ Game::GetInstance()->GetCameraPosVector().x - Game::GetInstance()->GetScreenSize().width / 2, Game::GetInstance()->GetCameraPosVector().y - Game::GetInstance()->GetScreenSize().height / 2 });

				if (dynamic_cast<Son*>(son)->GetAlive())
					//	Game::GetInstance()->SetCameraPosition(SGD::Point{ father->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, father->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });
					Game::GetInstance()->SetCameraDestinationVector({ father->GetPosition().x, father->GetPosition().y });
				else
				{
					Game::GetInstance()->SetCameraPosition({ son->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, son->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

				}


				//SGD::GraphicsManager::GetInstance()->DrawRectangle(SGD::Rectangle{ Game::GetInstance()->GetCameraPosition().x, Game::GetInstance()->GetCameraPosition().y, 800, 600 }, SGD::Color(255, 0, 0));
			}
			else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
			{

				//Game::GetInstance()->SetCameraPosition(SGD::Point{ son->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, son->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });


				Game::GetInstance()->SetCameraPosition(SGD::Point{ Game::GetInstance()->GetCameraPosVector().x - Game::GetInstance()->GetScreenSize().width / 2, Game::GetInstance()->GetCameraPosVector().y - Game::GetInstance()->GetScreenSize().height / 2 });
				if (dynamic_cast<Father*>(father)->GetAlive())
					Game::GetInstance()->SetCameraDestinationVector({ son->GetPosition().x, son->GetPosition().y });
				else
				{
					Game::GetInstance()->SetCameraPosition({ father->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, father->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

				}
			}


		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::J) || SGD::InputManager::GetInstance()->IsButtonPressed(0, 0))
		{
			SGD::AudioManager::GetInstance()->PlayAudio(m_SwitchSound);
			if (dynamic_cast<Father*>(father)->GetCurrCharacter())
			{
				if (dynamic_cast<Father*>(father)->GetCurrCharacter())
				{
					dynamic_cast<Father*>(father)->SetCurrCharacter(false);
					dynamic_cast<Son*>(son)->SetCurrCharacter(true);

				}

				else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
				{
					if (dynamic_cast<Son*>(son)->GetBackPack())
					{
						dynamic_cast<Son*>(son)->SetOnGround(false);
						dynamic_cast<Son*>(son)->SetBackPack(false);
					}
					dynamic_cast<Father*>(father)->SetCurrCharacter(true);
					dynamic_cast<Son*>(son)->SetCurrCharacter(false);
				}
			}

		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::K) && dynamic_cast<Father*>(father)->GetCurrCharacter() && !dynamic_cast<Father*>(father)->GetBackPack() || SGD::InputManager::GetInstance()->IsButtonPressed(0, 3) && dynamic_cast<Father*>(father)->GetCurrCharacter() && !dynamic_cast<Father*>(father)->GetBackPack())
		{
			SGD::AudioManager::GetInstance()->PlayAudio(m_PickingUPSon);
			m_pEntities->CheckCollisions(0, 1);
		}
		//replace son after backpacing is activated
		if (dynamic_cast<Son*>(son)->GetBackPack())
		{
			dynamic_cast<Son*>(son)->SetFacing(dynamic_cast<Father*>(father)->GetFacing());
			son->SetPosition(SGD::Point{ father->GetPosition().x - 16.0f, father->GetPosition().y - 16.0f });
		}

			// Collision 
			m_pEntities->UpdateAll(_ElapsedTime);
			CullingRect.left = Game::GetInstance()->GetCameraPosition().x;
			CullingRect.top = Game::GetInstance()->GetCameraPosition().y;
			CullingRect.right = CullingRect.left + Game::GetInstance()->GetScreenSize().width;
			CullingRect.bottom = CullingRect.top + Game::GetInstance()->GetScreenSize().height;

			dynamic_cast<Father*>(father)->SetHanging(false);
			dynamic_cast<Son*>(son)->SetHanging(false);
			dynamic_cast<Father*>(father)->SetonLadder(false);
			dynamic_cast<Son*>(son)->SetonLadder(false);
			m_pEntities->CheckCollisions(3, 5);//tiles and box
			m_pEntities->CheckCollisions(0, 4);
			m_pEntities->CheckCollisions(1, 4);
			m_pEntities->CheckCollisions(6, 3);
			m_pEntities->CheckCollisions(6, 0);
			m_pEntities->CheckCollisions(6, 1);
			m_pEntities->CheckCollisions(7, 0);
			m_pEntities->CheckCollisions(7, 1);
			m_pEntities->CheckCollisions(0, 2);//father and pressure
			m_pEntities->CheckCollisions(1, 2);//son and pressure
			m_pEntities->CheckCollisions(0, 14);//father and ladder
			m_pEntities->CheckCollisions(1, 14);//son and ladder
			m_pEntities->CheckCollisions(5, 16);//plate and box
			m_pEntities->CheckCollisions(3, 16);//tiles and box
			m_pEntities->CheckCollisions(0, 16);//Father and box
			m_pEntities->CheckCollisions(1, 16);//son and box
			m_pEntities->CheckCollisions(5, 5);//son and box

			if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::E))
			{
				if (dynamic_cast<Father*>(father)->GetCurrCharacter())
					m_pEntities->CheckCollisions(0, 15);
				else
					m_pEntities->CheckCollisions(1, 15);

				}

			dynamic_cast<Father*>(father)->SetCollisionRect(false);
			m_pEntities->CheckCollisions(0, 3);
			if (!dynamic_cast<Father*>(father)->GetCollisionRect() && dynamic_cast<Father*>(father)->upArrow == false && !dynamic_cast<Father*>(father)->GetHanging() && !dynamic_cast<Father*>(father)->GetonLadder())
			{
				father->SetVelocity(SGD::Vector{ 0.0f, 512.0f });
			}

			m_pEntities->CheckCollisions(0, 5);


			if (dynamic_cast<Son*>(son)->GetBackPack() == false)
			{
				dynamic_cast<Son*>(son)->SetCollisionRect(false);
				m_pEntities->CheckCollisions(1, 3);
			}
			bool i = dynamic_cast<Son*>(son)->GetonLadder();
			if (!dynamic_cast<Son*>(son)->GetCollisionRect() && dynamic_cast<Son*>(son)->upArrow == false && !dynamic_cast<Son*>(son)->GetBackPack() && dynamic_cast<Son*>(son)->lrArrow == false && !dynamic_cast<Son*>(son)->GetonLadder())
				son->SetVelocity(SGD::Vector{ 0.0f, 512.0f });

			m_pEntities->CheckCollisions(1, 5);
			//Rope Collision
			SGD::Rectangle f = dynamic_cast<Father*>(father)->GetRect();
			SGD::Rectangle s = dynamic_cast<Son*>(son)->GetRect();
			/*SGD::Rectangle q = p->GetRect();
			SGD::Rectangle b = p->GetLastRect();
			if (f.IsIntersecting(q))
			{
			if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Z))
			{
			SetMovementOff(!GetMovementOff());
			p->Grab(father->GetPosition());
			}
			bool i = dynamic_cast<Son*>(son)->GetonLadder();
			if (!dynamic_cast<Son*>(son)->GetCollisionRect() && dynamic_cast<Son*>(son)->upArrow == false && !dynamic_cast<Son*>(son)->GetBackPack() && dynamic_cast<Son*>(son)->lrArrow == false && !dynamic_cast<Son*>(son)->GetonLadder())
				son->SetVelocity(SGD::Vector{ 0.0f, 512.0f });

			m_pEntities->CheckCollisions(1, 5);
			//Rope Collision
			SGD::Rectangle f = dynamic_cast<Father*>(father)->GetRect();
			SGD::Rectangle s = dynamic_cast<Son*>(son)->GetRect();
			/*SGD::Rectangle q = p->GetRect();
			SGD::Rectangle b = p->GetLastRect();
			if (f.IsIntersecting(q))
			{
			p->Pull();
			}
			}*/
			//if (f.IsIntersecting(b))//father and rope box
			//{
			//	SGD::Rectangle Rect;
			//	Rect = father->GetRect().ComputeIntersection(b);
			//	if (Rect.ComputeHeight() < father->GetRect().ComputeHeight())
			//	{
			//		if (Rect.left >= father->GetRect().left && Rect.right <= father->GetRect().right)
			//		{
			//			dynamic_cast<Father*>(father)->letLeft = true;
			//			dynamic_cast<Father*>(father)->letRight = true;

			//			if (Rect.top == father->GetRect().top)
			//			{
			//				dynamic_cast<Father*>(father)->cannotJump = true;
			//				dynamic_cast<Father*>(father)->SetCollisionRect(false);
			//			}
			//			else if (Rect.bottom == father->GetRect().bottom)
			//			{
			//				//set him on the floor and set ground to true
			//				if (Rect.ComputeWidth() < 7.0f)
			//				{
			//					dynamic_cast<Father*>(father)->SetOnGround(false);
			//					dynamic_cast<Father*>(father)->SetCollisionRect(false);
			//					dynamic_cast<Father*>(father)->cannotJump = false;
			//					dynamic_cast<Father*>(father)->upArrow = false;
			//				}
			//				else
			//				{
			//					dynamic_cast<Father*>(father)->cannotJump = false;
			//					dynamic_cast<Father*>(father)->upArrow = false;
			//					father->SetVelocity({ father->GetVelocity().x, 0.0f });
			//					float op = father->GetRect().bottom - father->GetPosition().y;
			//					father->SetPosition({ father->GetPosition().x, b.top - op });
			//					dynamic_cast<Father*>(father)->SetOnGround(true);

			//				}
			//			}
			//		}
			//	}
			//	if (Rect.ComputeWidth() < father->GetRect().ComputeWidth())
			//	{
			//		if (Rect.top >= father->GetRect().top && Rect.bottom <= father->GetRect().bottom)
			//		{
			//			father->SetVelocity({ 0.0, father->GetVelocity().y });
			//			if (father->GetRect().left == Rect.left)
			//				dynamic_cast<Father*>(father)->letLeft = false;
			//			else if (father->GetRect().right == Rect.right)
			//				dynamic_cast<Father*>(father)->letRight = false;

			//		}
			//	}
			//}
			//if (s.IsIntersecting(b))//son and rope box
			//{
			//	SGD::Rectangle Rect;
			//	Rect = son->GetRect().ComputeIntersection(b);
			//	if (Rect.ComputeHeight() < son->GetRect().ComputeHeight())
			//	{
			//		if (Rect.left >= son->GetRect().left && Rect.right <= son->GetRect().right)
			//		{
			//			dynamic_cast<Son*>(son)->letLeft = true;
			//			dynamic_cast<Son*>(son)->letRight = true;

			//			if (Rect.top == son->GetRect().top)
			//			{
			//				dynamic_cast<Son*>(son)->cannotJump = true;
			//				dynamic_cast<Son*>(son)->SetCollisionRect(false);
			//			}
			//			else if (Rect.bottom == son->GetRect().bottom)
			//			{
			//				//set him on the floor and set ground to true
			//				if (Rect.ComputeWidth() < 7.0f)
			//				{
			//					dynamic_cast<Son*>(son)->SetOnGround(false);
			//					dynamic_cast<Son*>(son)->SetCollisionRect(false);
			//					dynamic_cast<Son*>(son)->cannotJump = false;
			//					dynamic_cast<Son*>(son)->upArrow = false;
			//				}
			//				else
			//				{
			//					dynamic_cast<Son*>(son)->cannotJump = false;
			//					dynamic_cast<Son*>(son)->upArrow = false;
			//					son->SetVelocity({ son->GetVelocity().x, 0.0f });
			//					float op = son->GetRect().bottom - son->GetPosition().y;
			//					son->SetPosition({ son->GetPosition().x, b.top - op });
			//					dynamic_cast<Son*>(son)->SetOnGround(true);

			//				}
			//			}
			//		}
			//	}
			//	if (Rect.ComputeWidth() < son->GetRect().ComputeWidth())
			//	{
			//		if (Rect.top >= son->GetRect().top && Rect.bottom <= son->GetRect().bottom)
			//		{
			//			son->SetVelocity({ 0.0, son->GetVelocity().y });
			//			if (son->GetRect().left == Rect.left)
			//				dynamic_cast<Son*>(son)->letLeft = false;
			//			else if (son->GetRect().right == Rect.right)
			//				dynamic_cast<Son*>(son)->letRight = false;

			//		}
			//	}
			//}
			if (f.IsIntersecting(win) && s.IsIntersecting(win))
			{
				winbool = true;
				SetMovementOff(true);
			}
			if (winbool)
			{
				Game::GetInstance()->SetLevel(Game::GetInstance()->GetLevel() + 1);
				Game::GetInstance()->ChangeState(LoadGameState::GetInstance());
				return true;

			}
			SGD::MessageManager::GetInstance()->Update();
			//p->Update(_ElapsedTime);

		}
	}
	//m_ParticleManager->UpdateEmitter(_ElapsedTime);
	return true;
}

//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: Render
//	Parameters: float _ElapsedTime
//	Return type: void 
//  What it is used for:
// Render is used  to Make every appear on the window screen
//
//*********************************************************************//
void GameplayState::Render(float _ElapsedTime)
{


	// This i s a nested for loop to make the destination rectangle as well as the source rectangle
	// It will use the Variable Load to get the Grids with and the Grids Height
	// So that it will determine where in the world that Tile will go


	for (int X = 0; X < Load->m_Grid->m_GridWidth; X++)
	{
		for (int Y = 0; Y < Load->m_Grid->m_GridHeight; Y++)
		{
			// this is the destination rectangle To get the spacific Place where you are going to put your Tiles 
			SGD::Rectangle DestinationRectangle;
			// You are going to Multiply X times the Loadtilewidth to get the position of the rectangle
			DestinationRectangle.top = (float)(X * Load->m_Tile->m_TileWidth);
			//  You are going to Multiply Y times the Loadtileheight to get the Y position of the Rectangle 
			DestinationRectangle.left = (float)(Y * Load->m_Tile->m_TileHeight);
			// to get the sixe of the right you are going to Add the Left rectngle with the Grid with 
			DestinationRectangle.right = (float)(DestinationRectangle.left + Load->m_Grid->m_GridWidth);
			// to get the sixe of the right you are going to Add the Left rectngle with the Grid with 
			DestinationRectangle.bottom = (float)(DestinationRectangle.top + Load->m_Grid->m_GridHeight);
			//SGD::GraphicsManager::GetInstance()->DrawRectangle(DestinationRectangle, SGD::Color{ 255, 0, 255, 255 }, SGD::Color{ 255, 255, 0, 0 }, 5);


			SGD::Rectangle tileRect;
			tileRect.left = (X* Load->m_Tile->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2);// -Game::GetInstance()->GetCameraPosition().x;
			tileRect.top = (float)Y* Load->m_Tile->m_TileHeight;
			tileRect.right = tileRect.left + Load->m_Tile->m_TileWidth;
			tileRect.bottom = tileRect.top + Load->m_Tile->m_TileHeight;

			//// This is a SourceRectangle, It will Draw all the tiles Where the Destination Rectangle is Placed
			SGD::Rectangle SourceRectangle;
			// This is The Cell Algorithem

			// To get the left of the Source Rectangle you Will Get he TIle ID then Mod It by the the Result of the Image Width 
			// Divided by the Tile Width then Multiply thr Tile Width to get the Sources Left 
			SourceRectangle.left = (float)(Load->Map[X][Y]->m_TileID % (int)(Load->Map[X][Y]->m_Image.width / Load->Map[X][Y]->m_TileWidth) * Load->Map[X][Y]->m_TileWidth);
			// This is The Cell Algorithem
			// To get the Top of the Source Rectangle you Will Get he TIle ID then devide It by the the Result of the Image Width 
			// Divided by the Tile Height then Multiply thr Tile Height to get the Sources Top
			SourceRectangle.top = (float)(Load->Map[X][Y]->m_TileID / (int)(Load->Map[X][Y]->m_Image.height / Load->Map[X][Y]->m_TileHeight) * Load->Map[X][Y]->m_TileHeight);
			// To ge the Source Rectangle Right you will  add SourceRectangles Left to the TileHeight 
			SourceRectangle.right = (float)(SourceRectangle.left + Load->Map[X][Y]->m_TileWidth);
			//// To ge the Source Rectangle bottom you will  add SourceRectangles  to the TileWidth 
			SourceRectangle.bottom = (float)(SourceRectangle.top + Load->Map[X][Y]->m_TileHeight);
			// This will Draw the Tiles in a spacifc plac on the Screen of the Game
			// You will First get an Image to Render
			// You will Get a Point Times the X from the For Loop with the Map's Tile Width minus half the screen witdh minus the Camera's X position 
			// You will Get a Point Times the Y from the For Loop with the Map's Tile Height minus half the screen Height minus the Camera's Y position 
			// Then Pass it the Source Rectangle to Draw it on the Screen
			if (CullingRect.IsIntersecting(tileRect))
			{
				if (Load->Map[X][Y]->Border == 1)
				{
					SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x, (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y }, SourceRectangle, {}, {}, SGD::Color{ 0, 255, 255, 255 });
				}
				else
				{
					SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x, (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y }, SourceRectangle);
				}

			}

			SGD::Rectangle rect;
			rect.left = ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x;
			rect.top = (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y;
			rect.right = rect.left + Load->Map[X][Y]->m_TileWidth;
			rect.bottom = rect.top + Load->Map[X][Y]->m_TileHeight;

			if (Debug)
			{
				if (Load->Map[X][Y]->m_Spawn == 1)
				{
					std::wostringstream wos1;
					wos1 << "R";
					SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 0, 0, 0 }, SGD::Color(255, 255, 0, 0));
					SGD::GraphicsManager::GetInstance()->DrawString(wos1.str().c_str(), SGD::Point{ rect.left, rect.top }, SGD::Color{ 255, 0, 255, 0 });
				}

				if (Load->Map[X][Y]->m_Checkpoint == 1)
				{
					std::wostringstream wos1;
					wos1 << "CP";
					float k = rect.left;
					float s = rect.top;
					SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 0, 0, 0 }, SGD::Color(255, 255, 0, 0));
					SGD::GraphicsManager::GetInstance()->DrawString(wos1.str().c_str(), SGD::Point{ rect.left, rect.top }, SGD::Color{ 255, 0, 255, 0 });
				}

				if (Load->Map[X][Y]->m_Trigger == 1)
				{
					std::wostringstream wos1;
					wos1 << "T";
					SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 0, 0, 0 }, SGD::Color(255, 255, 0, 0));
					SGD::GraphicsManager::GetInstance()->DrawString(wos1.str().c_str(), SGD::Point{ rect.left, rect.top }, SGD::Color{ 255, 0, 255, 0 });
				}

			}


		}
	}



#pragma region Debug Rects
#pragma endregion	

	m_pEntities->RenderAll();
	//m_ParticleManager->RenderEmitter();
	/*std::wostringstream s;
	s << father->GetVelocity().y;
	Game::GetInstance()->GetFont().Draw(s.str().c_str(), SGD::Point{ 345.0f, 50.0f }, 0.75f);*/

	SGD::GraphicsManager::GetInstance()->DrawTexture(m_FatherFaceImage, { Game::GetInstance()->GetScreenSize().width / 2 - 32, 10 }, 0, {}, dynamic_cast<Father*>(father)->GetStaminaState());
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_SonFaceImage, { Game::GetInstance()->GetScreenSize().width / 2 + 32, 30 }, 0, {}, dynamic_cast<Son*>(son)->GetStaminaState(), { 0.5f, 0.5f });
	std::wostringstream s;
	s << son->GetVelocity().y;
	Game::GetInstance()->GetFont().Draw(s.str().c_str(), SGD::Point{ 345.0f, 50.0f }, 0.75f);
	//p->Render(_ElapsedTime);
	if (m_Pause)
		RenderPause();
	SGD::Rectangle e = win;
	e.left -= Game::GetInstance()->GetCameraPosition().x;
	e.right -= Game::GetInstance()->GetCameraPosition().x;
	e.top -= Game::GetInstance()->GetCameraPosition().y;
	e.bottom -= Game::GetInstance()->GetCameraPosition().y;

	//SGD::GraphicsManager::GetInstance()->DrawRectangle(e, SGD::Color{ 255, 125, 35 });
	//if (winbool)
	//	Game::GetInstance()->GetFont().Draw("Success", SGD::Point{ 345.0f, 50.0f }, 0.75f);
	//if (lever)
	//	Game::GetInstance()->GetFont().Draw("Ok!", SGD::Point{ 345.0f, 50.0f }, 0.75f);
	//else
	//Game::GetInstance()->GetFont().Draw("Nokay!", SGD::Point{ 345.0f, 50.0f }, 0.75f);
	//if (loosebool)
	//	Game::GetInstance()->GetFont().Draw("You Died", SGD::Point{ 345.0f, 50.0f }, 0.75f);


}


//*********************************************************************//
//	File: GamePlayState.cpp
//	Function: MessageProc
//	Parameters: const SGD::Message* pMsg
//	Return type: void 
//  What it is used for:
//  This function is used to make a message system it is sent to  the MessageProc 
// to create a certain event/message
//*********************************************************************//
void GameplayState::MessageProc(const SGD::Message* pMsg)
{
	/* Show warning when a Message ID enumerator is not handled */
#pragma warning( push )
#pragma warning( 1 : 4061 )


	// What type of message?
	switch (pMsg->GetMessageID())
	{

	case MessageID::MSG_UNKNOWN:
		SGD_PRINT(L"GameplayState::MessageProc - unknown message id\n");
		break;
	case MessageID::MSG_CREATESWORDMAN:
	{
		GameplayState* self = GameplayState::GetInstance();
		Actor* swordman = self->CreateSwordsman(dynamic_cast<const CreateSwordMan*>(pMsg)->GetPlayer());
		self->m_pEntities->AddEntity(swordman, 2);
		swordman->Release();
		swordman = nullptr;
		break;
	}

	case MessageID::MSG_DESTORY_ACTOR:
	{
		const DestroyActorMessage* DestroyMsg = dynamic_cast<const DestroyActorMessage*>(pMsg);
		Actor* pActor = DestroyMsg->GetEntityMessage();
		GameplayState::GetInstance()->m_pEntities->RemoveEntity(pActor);
		break;

	}
	case MessageID::MSG_CANNON_BALL:
	{

		const CreateCannonBallMessage* m_cannon = dynamic_cast<const CreateCannonBallMessage*>(pMsg);
		Actor* m_Cannonball = (GameplayState::GetInstance()->CreateCannonBall(m_cannon->GetCannonOwner()));
		GameplayState::GetInstance()->m_pEntities->AddEntity(m_Cannonball, 6);
		break;

	}
	case MessageID::MSG_ARROW:
	{

		const CreateArrowMessage* m_Arrow = dynamic_cast<const CreateArrowMessage*>(pMsg);
		Actor* m_arrow = GameplayState::GetInstance()->CreateArrow(m_Arrow->GetDartCannonOwner());
		GameplayState::GetInstance()->m_pEntities->AddEntity(m_arrow, 6);
		break;

	}
	}

	/* Restore previous warning levels */
#pragma warning( pop )
}

void GameplayState::Pause(void)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow) || SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Down))
	{

		cursorPos++;
		SGD::AudioManager::GetInstance()->PlayAudio(m_Movement);
		if (cursorPos > 4)
			cursorPos = 0;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow) || SGD::InputManager::GetInstance()->IsDPadPressed(0, SGD::DPad::Up))
	{

		cursorPos--;
		SGD::AudioManager::GetInstance()->PlayAudio(m_Movement);
		if (cursorPos < 0)
			cursorPos = 4;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 0 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && cursorPos == 0)
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		m_Pause = false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 1 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && cursorPos == 1)
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->Pause(InstructionsState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 2 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && cursorPos == 2)
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->Pause(OptionState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 3 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && cursorPos == 3)
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->Pause(SaveGameState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 4 || SGD::InputManager::GetInstance()->IsButtonPressed(0, 1) && cursorPos == 4)
	{
		SGD::AudioManager::GetInstance()->PlayAudio(Select);
		Game::GetInstance()->ChangeState(MainMenuState::GetInstance());
	}
}

void GameplayState::RenderPause(void)
{
	if (Game::GetInstance()->GetLanguage() == 0)
	{
		Game::GetInstance()->GetFont().Draw("Pause", SGD::Point{ 345.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("Continue", SGD::Point{ 350.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Controls", SGD::Point{ 350.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Options", SGD::Point{ 355.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Save", SGD::Point{ 375.0f, 350.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Exit", SGD::Point{ 385.0f, 400.0f }, 0.50f);

	}
	else
	{
		Game::GetInstance()->GetFont().Draw("Pausa", SGD::Point{ 345.0f, 50.0f }, 0.75f);
		Game::GetInstance()->GetFont().Draw("Continuar", SGD::Point{ 350.0f, 200.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Controles", SGD::Point{ 350.0f, 250.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Opciones", SGD::Point{ 355.0f, 300.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Salvo", SGD::Point{ 375.0f, 350.0f }, 0.50f);
		Game::GetInstance()->GetFont().Draw("Salida", SGD::Point{ 380.0f, 400.0f }, 0.50f);

	}
	switch (cursorPos)
	{
	case 0: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(275.0f, 210.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 1: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(275.0f, 260.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 2: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(275.0f, 310.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 3: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(275.0f, 360.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	case 4: SGD::GraphicsManager::GetInstance()->DrawTexture(m_PointerImage, SGD::Point(275.0f, 410.0f), 0.0f, {}, SGD::Color(255, 153, 0));
		break;
	}
}

Actor* GameplayState::CreateSpikes(int i) const
{
	Spike* m_Spike = new Spike();
	m_Spike->SetImage(m_SpikesImage);
	m_Spike->SetSize({ 0.7f, 0.7f });
	m_Spike->SetPosition(SGD::Point{ Load->Traps["Spikes"][i]->left - 500, Load->Traps["Spikes"][i]->top - 300 });
	return m_Spike;
}

Actor*  GameplayState::CreatePopUpSpikes(int i) const
{
	PopUpSpikes* m_PUSpikes = new PopUpSpikes();
	m_PUSpikes->SetImage(m_SpikesImage);
	m_PUSpikes->SetSize({ 0.7f, 0.7f });
	m_PUSpikes->SetPosition(SGD::Point{ Load->Traps["PopSpikes"][i]->left - 735, Load->Traps["PopSpikes"][i]->top - 900 });
	return m_PUSpikes;
}

Actor*  GameplayState::CreateCannon(int i) const
{
	Cannon* m_Cannon = new Cannon();
	m_Cannon->SetImage(m_CannonImage);
	m_Cannon->SetPosition(SGD::Point{ Load->Traps["Cannon"][i]->left - 1000, Load->Traps["Cannon"][i]->top - 350 });

	return m_Cannon;

}

Actor* GameplayState::CreateDarts(int i) const
{
	DartCannon* m_DartCannon = new DartCannon();
	m_DartCannon->SetImage(m_DartTrapImage);
	m_DartCannon->SetPosition(SGD::Point{ Load->Traps["darts"][i]->left - 370, Load->Traps["darts"][i]->top - 380 });


	return m_DartCannon;
}

Actor* GameplayState::CreateCannonBall(Cannon*_Cannon)
{
	CannonBall* temp = new CannonBall();
	//temp->SetImage(m_CannonBallImage);
	temp->SetPosition(SGD::Point{ _Cannon->GetPosition().x, _Cannon->GetPosition().y + 30 });
	temp->SetSize(SGD::Size{ 16, 16, });
	SGD::Vector newVelocity = { -200, 0 };
	temp->SetVelocity(newVelocity);
	temp->SetCannon(_Cannon);
	return temp;

}

Actor*  GameplayState::CreateArrow(Actor* _DartCannon)
{
	Arrow* m_DartCannon = new Arrow();
	m_DartCannon->SetPosition(SGD::Point{ _DartCannon->GetPosition().x - 450, _DartCannon->GetPosition().y + 20 });
	m_DartCannon->SetSize(SGD::Size{ 16, 16, });
	SGD::Vector newVelocity = { -200, 0 };
	m_DartCannon->SetVelocity(newVelocity);
	m_DartCannon->SetDartCannon(_DartCannon);
	return m_DartCannon;

}

Actor* GameplayState::CreateDoor(int i) const
{
	AutoLockingDoor* temp = new AutoLockingDoor();
	temp->SetPosition(SGD::Point{ Load->Traps["Doors"][i]->left - 780, Load->Traps["Doors"][i]->top - 280 });
	temp->SetID(Load->DoorID[i]);
	return temp;

}

SGD::Rectangle Spike::GetRect() const
{
	return{ m_ptPosition, m_szSize };
}

Actor* GameplayState::CreateBox(int i) const
{
	Box* temp = new Box();
	temp->SetImage(m_SmallBoxImage);

	if (Load->BoxWeight[i] == true)
	{
		temp->SetTriggered(true);
		temp->SetPosition(SGD::Point{ Load->Traps["Box"][i]->left - 800, Load->Traps["Box"][i]->top - 324 });
		temp->SetHeavy(false);
		temp->SetImage(m_SmallBoxImage);
		temp->SetSize({ 32, 32 });
	}
	else if (Load->BoxWeight[i] == false)
	{
		temp->SetTriggered(true);
		temp->SetPosition(SGD::Point{ Load->Traps["Box"][i]->left - 800, Load->Traps["Box"][i]->top - 340 });
		temp->SetHeavy(true);
		temp->SetImage(m_BigBoxImage);
		temp->SetSize({ 64, 64 });
	}
	return temp;
}

Actor*  GameplayState::CreatePlates(int i) const
{
	PressurePlate* temp = new PressurePlate();
	temp->SetPosition(SGD::Point{ Load->Traps["Plates"][i]->left - 780, Load->Traps["Plates"][i]->top - 270 });
	temp->SetSize({ 32, 32 });
	temp->SetID(leverID);
	if (Load->PlateisHeavy[i] == false)
		temp->SetHeavy(false);
	else
		temp->SetHeavy(true);
	return temp;

}

//Actor* GameplayState::CreateRopes(int i) const
//{
//	Pulley* temp = new Pulley(200, 20, SGD::Vector{ Load->Traps["Rope"][i]->left, Load->Traps["Rope"][i]->top });
//
//
//	return temp;
//
//}

Actor* GameplayState::CreateLevers(int i) const
{
	Lever* temp = new Lever;
	temp->SetPosition({ Load->Traps["Levers"][i]->left - 780, Load->Traps["Levers"][i]->top - 279 });
	temp->SetImage(m_LeverImage);
	temp->SetSize({ 32, 32 });
	temp->SetID(leverID);
	return temp;
}

Actor* GameplayState::CreateFinalDoor(int i) const
{
	FinalDoor* temp = new FinalDoor;
	temp->SetPosition({ Load->Traps["FinalDoor"][i]->left - 800, Load->Traps["FinalDoor"][i]->top - 300 });
	temp->SetImage(m_FinalDoorImage);
	temp->SetSize({ 128, 128 });
	return temp;
}
Actor* GameplayState::CreateRollingBoulder(int i) const
{
	RollingBoulder* temp = new RollingBoulder;
	temp->SetPosition({ Load->Traps["Boulder"][i]->left - 780, Load->Traps["Boulder"][i]->top - 300 });
	temp->SetVelocity({ -128.0f, 0.0f });
	//temp->SetVelocity({ 0.0f, 0.0f });

	return temp;
}