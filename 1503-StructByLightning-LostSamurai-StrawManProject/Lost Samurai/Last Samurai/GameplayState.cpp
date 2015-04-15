#include "GameplayState.h"
#include"Father.h"
#include "Game.h"
#include "Son.h"
#include "Swordsman.h"
#include "Actor.h"
#include "SaveGameState.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Message.h"
#include"MainMenuState.h"
#include "MessageID.h"
#include "EntityManager.h"
#include"../Last Samurai/TileSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include "AnimationSystem.h"
#include "../SGD Wrappers/SGD_MessageManager.h"
#include "Tile.h"
#include  "Spike.h"
#include "Cannon.h"
#include "DartCannon.h"
#include <sstream>
#include "DestroyActorMessage.h"
#include "CannonBall.h"
#include "CreateCannonBallMessage.h"

#include"CreateSwordMan.h"
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
	Player* father = new Father;
	// Underneath is The Father set Position It is Currently commented out so that XML can make the Spawn point
	//father->SetPosition(SGD::Point{ 100.0f, 480.0f });
	// this is Setting the Fathers State to alive so that we can determine wether or not He is dead or Alive
	father->SetAlive(true);
	// This is setting the image to the the father Object so that he can aPpear on the scrren with a Png
	father->SetImage(m_FatherImage);
	// This is Used to set the Father objects size So that we can use Calculations to get Certain things to work 
	//father->SetSize(SGD::Size{ 64.0f, 64.0f });
	// This is Setting the Fathers Object Velocity so that when pressed a certain movement button his velocity will increase 
	father->SetVelocity({ 0.0f, 0.0f });
	// This is setting wether or not the father is stating on the ground so then if he is he can jump or perform other actions
	father->SetOnGround(false);
	// this is returning the newly alocated Father object so that it can be sent into the entity manager
	return father;
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
	Player* son = new Son;
	// Underneath is The Son set Position It is Currently commented out so that XML can make the Spawn point
	//son->SetPosition(SGD::Point{ 700.0f, 540.0f });
	// this is setting the son to Alive so that we can determine wether or not he is dead later on 
	son->SetAlive(true);
	// This is setting the Sons image so that He can render with a texture on the screen 
	son->SetImage(m_FatherImage);
	// This setting the sons size so that we can do calculations later on to do things 
	//son->SetSize(SGD::Size{ -0.75f, 0.75f });
	// This is setting the Sons velocity so that we can use the Velocity later when the Son moves 
	son->SetVelocity({ 0.0f, 0.0f });
	// This is used to know if the son is on the ground or not so that we can use other functions such as jump 
	son->SetOnGround(false);
	// this is returning a newly alocated Son object so that it can be sent to the entity manager
	return son;
}
Actor* GameplayState::CreateSwordsman(Actor* _player) const
{
	Actor * swordsman = new Swordsman;
	swordsman->SetPosition(SGD::Point{ 100.0f, 540.0f });
	swordsman->SetAlive(true);
	swordsman->SetImage(m_FatherImage);
	swordsman->SetSize(SGD::Size{ -1.5f, 1.5f });
	swordsman->SetVelocity({ 64.0f, 0.0f });
	dynamic_cast<Swordsman*>(swordsman)->SetTarget(_player);
	return swordsman;
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

	// This is setting the Fathers Image so he can be seen on screen.
	// the Fathers Texture is Located in the resources folder. 
	m_FatherImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Father.png");
	m_PointerImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Finger.png");
	m_SpikesImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/paintex_spikes.png");
	m_CannonImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/canon.png");
	m_DartTrapImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/darttrap.png");
	m_FatherFaceImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/FatherHead.png");
	m_SonFaceImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/SonHead.png");
	//m_CannonBallImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/ball.png");
	// You are making a newly alocated entity manager so it can hold all differnt sort of things such as the Father and son and Enemies
	m_pEntities = new EntityManager;
	m_ParticleManager = new ParticleManager;
	AnimationSystem::GetInstance()->Load("../resource/XML/FatherAnimations.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/SonAnimations.xml");
	AnimationSystem::GetInstance()->Load("../resource/XML/Cannonball.xml");

	m_Backround = SGD::AudioManager::GetInstance()->LoadAudio("../resource/audio/Game_Music.xwm");
	SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::Music, Game::GetInstance()->GetMusicVolume());
	SGD::AudioManager::GetInstance()->SetMasterVolume(SGD::AudioGroup::SoundEffects, Game::GetInstance()->GetSFXVolume());
	SGD::AudioManager::GetInstance()->PlayAudio(m_Backround, true);

	//AnimationSystem::GetInstance()->Load("../anim2.xml");
	// this is setting the CreateFather Function the The Father Actor Pointer so that it can be stored in the Enitiy Manger for later use 
	father = CreateFather();

	// The Father Acotr Pointer will be sent inside the entity manager in bucket zero 
	m_pEntities->AddEntity(father, 0);
	// this is setting the CreateSon Function the The SOn Actor Pointer so that it can be stored in the Enitiy Manger for later use 
	son = CreateSon();
	m_pEntities->AddEntity(son, 1);


	// The Father Acotr Pointer will be sent inside the entity manager in bucket One 
	//m_pEntities->AddEntity(son, son->GetType());
	// Underneath this is a SetCamaraPosition It is currently Comment out (Reason Unknown Will Comback to Let you why it was Commented out)
	//	Game::GetInstance()->SetCameraPosition({ father->GetPosition().x, father->GetPosition().y });
	// This Is a TileSystem Pointer that is used to make a newly Alocated Tilesystem so that you can make the Level.
	Load = new TileSystem();

	m_ParticleManager->LoadEmitter("../resource/XML/StepParticles.xml");
	m_ParticleManager->LoadEmitter("../resource/XML/LandParticles.xml");
	m_ParticleManager->LoadEmitter("../resource/XML/BackParticles.xml");
	m_ParticleManager->LoadEmitter("../resource/XML/BloodParticles.xml");

	Load->LoadTileXml((Father*)father, (Son*)son);
	for (unsigned int i = 0; i < Load->m_CollisionRect.size(); i++)
	{
		m_pEntities->AddEntity(Load->m_CollisionRect[i], 3);
	}

	for (unsigned int i = 0; i < Load->m_Deathcollision.size(); i++)
	{
		m_pEntities->AddEntity(Load->m_Deathcollision[i], 4);
		Load->m_Deathcollision[i]->Release();
	}

	for (unsigned int i = 0; i < Load->Ledges.size(); i++)
	{
		m_pEntities->AddEntity(Load->Ledges[i], 7);
		Load->Ledges[i]->Release();
	}
	for (int i = 0; i < Load->Traps["Spikes"].size(); i++)
	{
		m_Spikes = CreateSpikes(i);
		m_pEntities->AddEntity(m_Spikes, 5);
	}

	for (int i = 0; i < Load->Traps["Cannon"].size(); i++)
	{
		m_pEntities->AddEntity(CreateCannon(i), 5);
	}

	for (int i = 0; i < Load->Traps["darts"].size(); i++)
	{
		m_pEntities->AddEntity(CreateDarts(i), 5);
	}

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

	// This is terminating the Father image so that you will not have any memory leaks 
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_PointerImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_FatherFaceImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_SonFaceImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_SpikesImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_CannonImage);
	SGD::GraphicsManager::GetInstance()->UnloadTexture(m_DartTrapImage);
	SGD::AudioManager::GetInstance()->UnloadAudio(m_Backround);
	m_Pause = false;
	cursorPos = 0;
	// Father is being released from the Pointer it was associated with so that The Release function
	// Can take car of all dynamic memory 
	father->Release();
	// after you release the father you are going to set him to a nullptr just in case so that you can make sure he is reslly null (Safe Check)
	father = nullptr;
	// Son is being released from the Pointer it was associated with so that The Release function
	// Can take car of all dynamic memory 
	son->Release();
	// after you release the father you are going to set him to a nullptr just in case so that you can make sure he is reslly null (Safe Check)
	son = nullptr;
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
	Game::GetInstance()->SetCameraPosition(SGD::Point{ 0.0f, 0.0f });
	SGD::MessageManager::GetInstance()->Terminate();
	SGD::MessageManager::DeleteInstance();
	m_ParticleManager->FreeEmitter(0);
	m_ParticleManager->FreeEmitter(1);
	m_ParticleManager->FreeEmitter(2);
	m_ParticleManager->FreeEmitter(3);
	delete m_ParticleManager;
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
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == false)
	{
		// this is setting Debug to true so that it can turn on Debug mode 
		Debug = true;
	}
	//  this is an Else if check that is basically doing the same thing but in reverse 
	// so that you Can press F3 again this time the bool Debug is True 
	// thus Turung off debug mode so that you can look at the normal level
	else if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::F3) && Debug == true)
		// this is Setting the Debug Boolean to false. 
		Debug = false;

	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Escape))
	{
		if (!m_Pause)
			m_Pause = true;
		else
			m_Pause = false;
	}

	if (m_Pause)
		Pause();
	else
	{
		if (dynamic_cast<Father*>(father)->GetCurrCharacter())
		{

			Game::GetInstance()->SetCameraPosition(SGD::Point{ father->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, father->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

			//SGD::GraphicsManager::GetInstance()->DrawRectangle(SGD::Rectangle{ Game::GetInstance()->GetCameraPosition().x, Game::GetInstance()->GetCameraPosition().y, 800, 600 }, SGD::Color(255, 0, 0));

		}
		else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
		{
			Game::GetInstance()->SetCameraPosition(SGD::Point{ son->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, son->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

		}


		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::J))
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

		if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::K) && dynamic_cast<Father*>(father)->GetCurrCharacter() && !dynamic_cast<Father*>(father)->GetBackPack())
		{
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

		m_pEntities->CheckCollisions(0, 4);
		m_pEntities->CheckCollisions(1, 4);
		m_pEntities->CheckCollisions(6, 3);
		m_pEntities->CheckCollisions(6, 0);
		m_pEntities->CheckCollisions(6, 1);
		dynamic_cast<Father*>(father)->SetCollisionRect(false);
		m_pEntities->CheckCollisions(0, 3);
		if (!dynamic_cast<Father*>(father)->GetCollisionRect() && dynamic_cast<Father*>(father)->upArrow == false)
			father->SetVelocity(SGD::Vector{ 0.0f, 64.0f });

		dynamic_cast<Son*>(son)->SetCollisionRect(false);
		m_pEntities->CheckCollisions(1, 3);
		if (!dynamic_cast<Son*>(son)->GetCollisionRect() && dynamic_cast<Son*>(son)->upArrow == false && !dynamic_cast<Son*>(son)->GetBackPack() && !dynamic_cast<Son*>(son)->GetOnGround() && dynamic_cast<Son*>(son)->lrArrow == false)
			son->SetVelocity(SGD::Vector{ 0.0f, 64.0f });

		SGD::MessageManager::GetInstance()->Update();

	}
	m_ParticleManager->UpdateEmitter(0, _ElapsedTime);

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


			SGD::Point m_Point;
			m_Point.x = (X* Load->m_Tile->m_TileWidth + Load->m_Tile->m_TileWidth) - Game::GetInstance()->GetScreenSize().width / 2;
			m_Point.y = (float)Y* Load->m_Tile->m_TileHeight + Load->m_Tile->m_TileHeight;
			SGD::Point m_Point2;
			m_Point2.x = (float)X* Load->m_Tile->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2;
			m_Point2.y = (float)Y* Load->m_Tile->m_TileHeight + Load->m_Tile->m_TileHeight;

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
			if (X != 0 && Y != 0)
			{
				if (CullingRect.IsPointInRectangle(m_Point))
				{
					SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x, (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y }, SourceRectangle);
				}
				else if (CullingRect.IsPointInRectangle(m_Point2))
				{
					SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x, (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y }, SourceRectangle);
				}
			}
			else
			{
				SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x, (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y }, SourceRectangle);

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
	// This is a if check, Checking if the Debug mode is True 
	//if (Debug)
	//{

	//	// If the Debug Boolean is True then it will Fall in
	//	// This is a for loop of all of the Collision Rectangles m_CollisionRect
	//	for (unsigned int i = 0; i < Load->m_CollisionRect.size(); i++)
	//	{
	//		// Useing a wide string stream to get the number of rectangles and where they are placed on the screen 
	//		std::wostringstream wos1;
	//		// you pass the I into the string stream 
	//		wos1 << i;
	//		// Getting a SGD Point to get the Position ofall of the Rectangles on the screen 
	//		SGD::Point pos = { Load->m_CollisionRect[i]->GetPosition().x - Game::GetInstance()->GetCameraPosition().x, Load->m_CollisionRect[i]->GetPosition().y + Game::GetInstance()->GetCameraPosition().y };
	//		//  Getting the Size of all the Collision Rectangles 
	//		SGD::Size size{ Load->m_CollisionRect[i]->GetSize().width - Load->m_CollisionRect[i]->GetPosition().x, Load->m_CollisionRect[i]->GetSize().height - Load->m_CollisionRect[i]->GetPosition().y };
	//		// Making a Rectangle so that you Can get the acurate positions and size of the Collision rectangles
	//		SGD::Rectangle rectp{ pos, size };
	//		// This is Going to Draw the Collision Recttangles On the Screen in the correct places 
	//		SGD::GraphicsManager::GetInstance()->DrawRectangle(rectp, {}, SGD::Color{ 255, 255, 0, 0 });
	//		// This is drawing a number inside the The COllision Rectangle
	//		SGD::GraphicsManager::GetInstance()->DrawString(wos1.str().c_str(), SGD::Point{ rectp.left, rectp.top }, SGD::Color{ 255, 0, 255, 0 });
	//	}



	//}
#pragma endregion	

	m_pEntities->RenderAll();
	m_ParticleManager->RenderEmitter(0);
	/*std::wostringstream s;
	s << father->GetVelocity().y;
	Game::GetInstance()->GetFont().Draw(s.str().c_str(), SGD::Point{ 345.0f, 50.0f }, 0.75f);*/

	SGD::GraphicsManager::GetInstance()->DrawTexture(m_FatherFaceImage, { Game::GetInstance()->GetScreenSize().width / 2 - 32, 10 }, 0, {}, dynamic_cast<Father*>(father)->GetStaminaState());
	SGD::GraphicsManager::GetInstance()->DrawTexture(m_SonFaceImage, { Game::GetInstance()->GetScreenSize().width / 2 + 32, 30 }, 0, {}, dynamic_cast<Son*>(son)->GetStaminaState(), { 0.5f, 0.5f });

	if (m_Pause)
		RenderPause();
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
	}

	/* Restore previous warning levels */
#pragma warning( pop )
}

void GameplayState::Pause(void)
{
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::DownArrow))
	{
		cursorPos++;
		if (cursorPos > 4)
			cursorPos = 0;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::UpArrow))
	{

		cursorPos--;
		if (cursorPos < 0)
			cursorPos = 4;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 0)
	{
		m_Pause = false;
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 1)
	{
		Game::GetInstance()->Pause(InstructionsState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 2)
	{
		Game::GetInstance()->Pause(OptionState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 3)
	{
		Game::GetInstance()->Pause(SaveGameState::GetInstance());
	}
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::Enter) && cursorPos == 4)
	{
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
	m_Spike->SetPosition(SGD::Point{ Load->Traps["Spikes"][i]->left - 500, Load->Traps["Spikes"][i]->top - 350 });


	return m_Spike;
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