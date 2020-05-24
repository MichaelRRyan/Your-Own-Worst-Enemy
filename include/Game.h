#ifndef GAME
#define GAME

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <SFML/Graphics.hpp>
#include <array>
#include <Memory>

#include "Tile.h"
#include "EmptyTile.h"
#include "SolidTile.h"

/// <summary>
/// The game's main class. Keeps the game running at 60
/// frames per second and holds all ground level game objects.
/// </summary>
class Game
{
public:

	Game();
	~Game();

	void run();

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	void setupGame();

	sf::RenderWindow m_window;
	bool m_exitGame;

	std::array<std::array<std::shared_ptr<Tile>, 20>, 10> m_level;

};

#endif // !GAME

