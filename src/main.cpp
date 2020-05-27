/// Your Own Worst Enemy
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif

#include "Game.h"

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	try
	{
		Game game;
		game.run();
	}
	catch (std::exception e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
		system("pause");
	}

	return 0;
}
