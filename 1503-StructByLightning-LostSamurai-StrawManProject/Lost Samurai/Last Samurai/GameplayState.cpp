#include "GameplayState.h"
#include"Father.h"
#include "Game.h"
#include "Son.h"
#include "Actor.h"
#include "../SGD Wrappers/SGD_InputManager.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Message.h"
#include"MainMenuState.h"
#include "Message.h"
#include "EntityManager.h"
#include"../Last Samurai/TileSystem.h"
#include "../SGD Wrappers/SGD_GraphicsManager.h"
#include "../SGD Wrappers/SGD_Geometry.h"
#include "Tile.h"
#include <sstream>


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
	father->SetSize(SGD::Size{ 64.0f, 64.0f });
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
	son->SetSize(SGD::Size{ -0.75f, 0.75f });
	// This is setting the Sons velocity so that we can use the Velocity later when the Son moves 
	son->SetVelocity({ 0.0f, 0.0f });
	// This is used to know if the son is on the ground or not so that we can use other functions such as jump 
	son->SetOnGround(false);
	// this is returning a newly alocated Son object so that it can be sent to the entity manager
	return son;
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
	// This is setting the Fathers Image so he can be seen on screen.
	// the Fathers Texture is Located in the resources folder. 
	m_FatherImage = SGD::GraphicsManager::GetInstance()->LoadTexture("../resource/graphics/Father.png");
	// You are making a newly alocated entity manager so it can hold all differnt sort of things such as the Father and son and Enemies
	m_pEntities = new EntityManager;
	// this is setting the CreateFather Function the The Father Actor Pointer so that it can be stored in the Enitiy Manger for later use 
	father = CreateFather();
	// The Father Acotr Pointer will be sent inside the entity manager in bucket zero 
	m_pEntities->AddEntity(father, father->GetType());
	// this is setting the CreateSon Function the The SOn Actor Pointer so that it can be stored in the Enitiy Manger for later use 
	son = CreateSon();
	// The Father Acotr Pointer will be sent inside the entity manager in bucket One 
	m_pEntities->AddEntity(son, son->GetType());
	// Underneath this is a SetCamaraPosition It is currently Comment out (Reason Unknown Will Comback to Let you why it was Commented out)
	//	Game::GetInstance()->SetCameraPosition({ father->GetPosition().x, father->GetPosition().y });
	// This Is a TileSystem Pointer that is used to make a newly Alocated Tilesystem so that you can make the Level.
	Load = new TileSystem();


	// Load is calling the LoadTileXml Function and passing the Father and son
	// It will use an XML File to load everything into the Engine and set the spawn of the Father and SOn
	Load->LoadTileXml((Father*)father, (Son*)son);
	for (unsigned int i = 0; i < Load->m_CollisionRect.size(); i++)
	{
		m_pEntities->AddEntity(Load->m_CollisionRect[i], 5);
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

	// This is a bunch of if statemnets that Let the Player switch between the father and son 
#pragma region Switching between Characters 


	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::J))
	{
		if (dynamic_cast<Father*>(father)->GetCurrCharacter())
		{
			dynamic_cast<Father*>(father)->SetCurrCharacter(false);
			dynamic_cast<Son*>(son)->SetCurrCharacter(true);
		}
		else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
		{
			dynamic_cast<Father*>(father)->SetCurrCharacter(true);
			dynamic_cast<Son*>(son)->SetCurrCharacter(false);
		}
	}
#pragma endregion
	// Above This Code is not Needed anymore (SHOULD WE DELETE THIS? IF IT IS NOT BEING USE?)



	// This is an If check  that is using Input to Switch between the father and Son 
	// You are Dynamic_casting to a father pointer then use the father variable to get the 
	// Function GetCurrCharacter() So that you can determine wether or not you are the father or the son 
	// Also You are Dynamic casting To check if the father isnt backpacking.
	if (SGD::InputManager::GetInstance()->IsKeyPressed(SGD::Key::K) && dynamic_cast<Father*>(father)->GetCurrCharacter() && !dynamic_cast<Father*>(father)->GetBackPack())
	{
		// if the if check is true it will Use m_pEntities Check Collision function to see if they car coliding? (CHECK FOR BETTER EXPLENATION)
		m_pEntities->CheckCollisions(0, 1);
	}

	// This is  is another Dynamic Cast if check checking if the father is the current object that the player is using at the moment 
	// ?(NEED TO DICUSS WHY THERE IS SO MANY DYNAMIC_CASTING GOING ON)?
	if (dynamic_cast<Father*>(father)->GetCurrCharacter())
	{
		// This is a Game Instance Singleton Calling the The Camera's SetPosition
		// You are going to use a SGD point to get the Fathers X Position and then Minus it by half of the screen width
		// You are going to use a SGD point to get the Fathers Y Position and then Minus it by half of the screen Height
		// You are doing this so that the camera can switch between the father and Son Objects. 
		Game::GetInstance()->SetCameraPosition(SGD::Point{ father->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, father->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });
	}
	// this is an else if check that is checking if that the son is current charater slected at the time
	// ?(NEED TO DICUSS WHY THERE IS SO MANY DYNAMIC_CASTING GOING ON)?
	else if (dynamic_cast<Son*>(son)->GetCurrCharacter())
	{
		// This is a Game Instance Singleton Calling the The Camera's SetPosition
		// You are going to use a SGD point to get the Son X Position and then Minus it by half of the screen width
		// You are going to use a SGD point to get the Son Y Position and then Minus it by half of the screen Height
		// You are doing this so that the camera can switch between the father and Son Objects.
		Game::GetInstance()->SetCameraPosition(SGD::Point{ son->GetPosition().x - Game::GetInstance()->GetScreenSize().width / 2, son->GetPosition().y - Game::GetInstance()->GetScreenSize().height / 2 });

	}

	//replace son after backpacing is activated
	// ?(NEED TO DICUSS WHY THERE IS SO MANY DYNAMIC_CASTING GOING ON)?
	// This is a if check saying if the Son is being backpacked at that current moment
	if (dynamic_cast<Son*>(son)->GetBackPack())
	{
		// ?(NEED TO DICUSS WHY THERE IS SO MANY DYNAMIC_CASTING GOING ON)?
		// this is a Dynamic casted son And it is setting the Son facing position to where the father is facing 
		dynamic_cast<Son*>(son)->SetFacing(dynamic_cast<Father*>(father)->GetFacing());
		// ?(NEED TO DICUSS WHY THERE IS SO MANY DYNAMIC_CASTING GOING ON)?
		// This is a Dynamic casted son Pointer to set the position of the Son to the back of the Father 
		// You are also Dynamic_cating the father so the you can get the position minus Sixteen also with the y position
		dynamic_cast<Son*>(son)->SetPosition(SGD::Point{ dynamic_cast<Father*>(father)->GetPosition().x - 16.0f, dynamic_cast<Father*>(father)->GetPosition().y - 16.0f });
	}



	m_pEntities->UpdateAll(_ElapsedTime);
	m_pEntities->CheckCollisions(Actor::EntityType::ENT_FATHER, Actor::EntityType::ENT_TILES);
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

			// This is a SourceRectangle, It will Draw all the tiles Where the Destination Rectangle is Placed
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
			SourceRectangle.right = (float)(SourceRectangle.left + Load->Map[X][Y]->m_TileHeight);
			//// To ge the Source Rectangle bottom you will  add SourceRectangles  to the TileWidth 
			SourceRectangle.bottom = (float)(SourceRectangle.top + Load->Map[X][Y]->m_TileWidth);
			// This will Draw the Tiles in a spacifc plac on the Screen of the Game
			// You will First get an Image to Render
			// You will Get a Point Times the X from the For Loop with the Map's Tile Width minus half the screen witdh minus the Camera's X position 
			// You will Get a Point Times the Y from the For Loop with the Map's Tile Height minus half the screen Height minus the Camera's Y position 
			// Then Pass it the Source Rectangle to Draw it on the Screen
			SGD::GraphicsManager::GetInstance()->DrawTextureSection(Load->GetTileImage(), SGD::Point{ ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x, (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y }, SourceRectangle);
			SGD::Rectangle rect = SourceRectangle;
			rect.left = ((float)X * Load->Map[X][Y]->m_TileWidth - Game::GetInstance()->GetScreenSize().width / 2) - Game::GetInstance()->GetCameraPosition().x;
			rect.top = (float)Y * Load->Map[X][Y]->m_TileHeight - Game::GetInstance()->GetCameraPosition().y;
			rect.right = rect.left + Load->Map[X][Y]->m_TileHeight;
			rect.bottom = rect.top + Load->Map[X][Y]->m_TileWidth;

			if (Debug)
			{
				if (Load->Map[X][Y]->SpawnX != 0 && Load->Map[X][Y]->SpawnY != 0)
				{
					std::wostringstream wos1;
					wos1 << "R";
					SGD::GraphicsManager::GetInstance()->DrawRectangle(rect, SGD::Color{ 255, 0, 0, 0 }, SGD::Color(255, 255, 0, 0));
					SGD::GraphicsManager::GetInstance()->DrawString(wos1.str().c_str(), SGD::Point{ rect.left, rect.top }, SGD::Color{ 255, 0, 255, 0 });
				}

			}


		}
	}
#if 1 
	//This Is Not Used Anymore But Can Be UseFul Later On 








#endif

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

	// This is GOing to render all of the Objects inside the Entity Manager 
	m_pEntities->RenderAll();
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
	case MessageID::MSG_BACKPACK:
		SGD_PRINT(L"BackPack Done");
		break;
	case MessageID::MSG_UNKNOWN:
		SGD_PRINT(L"GameplayState::MessageProc - unknown message id\n");
		break;
	default:
		break;
	}


	/* Restore previous warning levels */
#pragma warning( pop )
}
