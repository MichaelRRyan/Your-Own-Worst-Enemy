/// @Author Michael Rainsford Ryan

#include "Game.h"

///////////////////////////////////////////////////////////////////
Game::Game() :
	m_window{ sf::VideoMode{ 1280u, 720u, 32u }, "Your Own Worst Enemy" },
	m_exitGame{ false },
	m_gameplayManager{ m_level, m_entities }
{
	setupGame();

	m_controller.connect();
	Input::setControllerPointer(&m_controller);
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

	Input::update(m_window);

	for (int i = 0; i < m_entities.size(); i++)
	{
		m_entities.at(i)->update(t_deltaTime, m_level);
	}
}

///////////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color::White);

	m_level.draw(m_window, m_tileSprite);

	for (std::shared_ptr<Entity> const & entity : m_entities)
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

	for (int i = 0; i < m_level.getSize().x; i++)
	{
		m_level.setTile(m_level.getSize().y - 1, i, new SolidTile);
	}

	m_level.setTile(m_level.getSize().y - 3, 2, new SolidTile(2));
	m_level.setTile(m_level.getSize().y - 3, 3, new SolidTile(3));
	m_level.setTile(m_level.getSize().y - 2, 2, new SolidTile(4));
	m_level.setTile(m_level.getSize().y - 2, 3, new SolidTile(5));

	m_level.setTile(m_level.getSize().y - 4, 5, new SolidTile(2));
	m_level.setTile(m_level.getSize().y - 4, 6, new SolidTile(3));
	m_level.setTile(m_level.getSize().y - 3, 5, new SolidTile(4));
	m_level.setTile(m_level.getSize().y - 3, 6, new SolidTile(5));

	m_level.setTile(m_level.getSize().y - 2, 8, new SpikeTile);

	m_level.setTile(5, 5, new CheckpointTile(true));

	std::shared_ptr<Player> player = std::make_shared<Player>();

	player->addObserver(&m_gameplayManager);

	player->spawn(static_cast<sf::Vector2f>(m_level.getCurrentCheckpointTile()) * 16.0f + sf::Vector2f{ 8.0f, 0.0f });

	m_entities.push_back(player);

	// Set up the view
	sf::View newView{ m_window.getDefaultView() };

	float aspectRatio = newView.getSize().x / newView.getSize().y;

	float viewHeight = m_level.getSize().y * 16.0f;

	newView.setSize(viewHeight * aspectRatio, viewHeight);

	newView.setCenter(newView.getSize() / 2.0f);

	m_window.setView(newView);

	if (!m_tileSheet.loadFromFile("assets/images/tile_sheet.png"))
	{
		std::exception exception("failed to load tile sheet texture");
		throw(exception);
	}

	m_tileSprite.setTexture(m_tileSheet);
}

///////////////////////////////////////////////////////////////////