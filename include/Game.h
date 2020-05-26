#ifndef GAME
#define GAME

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <SFML/Graphics.hpp>
#include <vector>

#include "Input.h"
#include "Gamepad.h"

#include "Level.h"
#include "EmptyTile.h"
#include "SolidTile.h"

#include "Entity.h"
#include "Player.h"
#include "Zombie.h"

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

	Level m_level;

	std::vector<std::shared_ptr<Entity>> m_entities;

	Gamepad m_controller;

	sf::Texture m_tileSheet;
	sf::Sprite m_tileSprite;

};

#endif // !GAME

