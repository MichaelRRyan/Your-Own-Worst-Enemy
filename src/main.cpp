/// Your Own Worst Enemy
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020

#ifndef SFML_STATIC 

#ifdef _DEBUG  
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-system-d.lib")  
#pragma comment(lib,"sfml-window-d.lib")  
#pragma comment(lib,"sfml-audio-d.lib")  
#pragma comment(lib,"sfml-main-d.lib") 
#pragma comment(lib,"sfml-network-d.lib")  
#else  
#pragma comment(lib,"sfml-graphics.lib")  
#pragma comment(lib,"sfml-system.lib")  
#pragma comment(lib,"sfml-window.lib")  
#pragma comment(lib,"sfml-audio.lib")  
#pragma comment(lib,"sfml-main.lib") 
#pragma comment(lib,"sfml-network.lib")  
#endif //_DEBUG  

#else 

#ifdef _DEBUG  
#pragma comment(lib,"sfml-graphics-s-d.lib") 
#pragma comment(lib,"freetype.lib") 
#pragma comment(lib,"jpeg.lib") 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"sfml-system-s-d.lib")  
#pragma comment(lib,"winmm.lib") 
#pragma comment(lib,"sfml-window-s-d.lib")  
#pragma comment(lib,"winmm") 
#pragma comment(lib,"gdi32") 
#pragma comment(lib,"sfml-audio-s-d.lib")  
#pragma comment(lib,"flac.lib") 
#pragma comment(lib,"ogg.lib") 
#pragma comment(lib,"vorbisenc.lib") 
#pragma comment(lib,"vorbisfile.lib") 
#pragma comment(lib,"vorbis.lib") 
#pragma comment(lib,"openal32.lib") 
#pragma comment(lib,"sfml-main-d.lib") 
//#pragma comment(lib,"sfml-network-s-d.lib")  
//#pragma comment(lib,"ws2_32.lib") 

#else  

#pragma comment(lib,"sfml-graphics-s.lib")  
#pragma comment(lib,"freetype.lib") 
//#pragma comment(lib,"jpeg.lib") 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"sfml-system-s.lib")  
#pragma comment(lib,"winmm.lib") 
#pragma comment(lib,"sfml-window-s.lib")  
#pragma comment(lib,"gdi32") 
#pragma comment(lib,"winmm") 
#pragma comment(lib,"sfml-audio-s.lib")  
#pragma comment(lib,"flac.lib") 
#pragma comment(lib,"ogg.lib") 
#pragma comment(lib,"vorbisenc.lib") 
#pragma comment(lib,"vorbisfile.lib") 
#pragma comment(lib,"vorbis.lib") 
#pragma comment(lib,"openal32.lib") 
#pragma comment(lib,"sfml-main.lib") 

#pragma comment(lib,"sfml-network-s.lib")  
#pragma comment(lib,"ws2_32.lib") 

#endif //_DEBUG  
#endif // !SFML_STATIC 

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
