
#include "Game.h"
#include "Vector2D.h"

#include <iostream>
#include <string>
#include <SDL.h>
#include <memory>

void createWindow()
{

}

int i = 100;
int numb;

int main(int argc, char* args[])
{
	//Init game
	if (Game::instance()->init("Tetris", 600, 600))
	{
		//Game loop
		while (Game::instance()->isRunning()) 
		{
			//Listen for events
			Game::instance()->handleEvents();
			Game::instance()->update();
			Game::instance()->render();
		}
	}
	else
	{
		std::cout << "Game failed to initialize.";
	}

	////Init game
	//if (Game::instance()->init("Space Shooter", 1000, 1000))
	//{
	//	//Game loop
	//	while (Game::instance()->isRunning())
	//	{
	//		
	//		Game::instance()->handleEvents(); //Listen for events
	//		Game::instance()->update(); //Update game
	//		Game::instance()->render(); //Render
	//	}
	//		
	//}
	////Game didn't init
	//else
	//{
	//	std::cout << "Failed to initialize.";
	//}

	int numb;

	

	std::cout << "\n\nEnd\n";
	char c;
	std::cin >> c;
	return 0;
}


