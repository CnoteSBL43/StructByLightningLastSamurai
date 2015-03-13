//*********************************************************************//
//	File:		Main.cpp
//	Author:		Varun Kumar
//	Course:		SGP - 1501
//	Purpose:	Application entry point
//*********************************************************************//

#include <vld.h>
#include "Game.h"

int main()
{
	if (Game::GetInstance()->Initialize() == false)
		return -1;	// failure!!!
	// Run game:
	int exitCode = 0;
	do
		exitCode = Game::GetInstance()->Update();
	while (exitCode == 0);


	// Terminate game:
	Game::GetInstance()->Terminate();
	Game::DeleteInstance();


	// Exit (+success, -failure)
	return exitCode;
}