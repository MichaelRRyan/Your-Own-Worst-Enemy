/// @Author Michael Rainsford Ryan

#include "Game.h"

///////////////////////////////////////////////////////////////////
Game::Game() :
	m_window{ sf::VideoMode{ 800u, 600u, 32u }, "Basic Game" },
	m_exitGame{ false }
{
	setupGame();
}

///////////////////////////////////////////////////////////////////
Game::~Game()
{

}

///////////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float FPS = 60.0f;
	sf::Time timePerFrame = sf::seconds(1.0f / FPS); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // Run as many times as possible
		timeSinceLastUpdate += clock.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // Run at a minimum of 60 fps
			update(timePerFrame); // 60 fps
		}
		render(); // Run as many times as possible
	}
}

///////////////////////////////////////////////////////////////////
void Game::processEvents()
{
	sf::Event nextEvent;
	while (m_window.pollEvent(nextEvent))
	{
		if (sf::Event::Closed == nextEvent.type) // check if the close window button is clicked on.
		{
			m_window.close();
		}
	}
}

///////////////////////////////////////////////////////////////////
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	for (std::unique_ptr<Entity> & entity : m_entities)
	{
		entity->update(m_level);
	}
}

///////////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear();

	sf::RectangleShape tile{ { 16.0f, 16.0f } };

	for (int row = 0; row < m_level.getSize().y; row++)
	{
		for (int col = 0; col < m_level.getSize().x; col++)
		{
			tile.setPosition(col * tile.getSize().x, row * tile.getSize().y);

			tile.setFillColor(m_level.getTile(row, col).getColor());

			m_window.draw(tile);
		}
	}

	for (std::unique_ptr<Entity> const & entity : m_entities)
	{
		m_window.draw(*entity);
	}

	m_window.display();
}

///////////////////////////////////////////////////////////////////
void Game::setupGame()
{
	for (int row = 0; row < m_level.getSize().y; row++)
	{
		for (int col = 0; col < m_level.getSize().x; col++)
		{
			m_level.setTile(row, col, new EmptyTile);
		}
	}

	m_level.setTile(5, 0, new SolidTile);

	m_entities.push_back(std::make_unique<Player>());

	float viewScale = 4.0f;

	m_window.setView({ m_window.getView().getCenter() / viewScale, m_window.getView().getSize() / viewScale });
}

///////////////////////////////////////////////////////////////////