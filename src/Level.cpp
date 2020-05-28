/// @Author Michael Rainsford Ryan

#include "Level.h"

///////////////////////////////////////////////////////////////////
Level::Level() :
	m_currentCheckpoint{ 0 }
{
	sf::Vector2i size = getSize();

	for (int row = 0; row < size.y; row++)
	{
		for (int col = 0; col < size.x; col++)
		{
			if (rand() % 10 == 0)
			{
				m_backgroundTiles[row][col] = 2;
			}
			else
			{
				m_backgroundTiles[row][col] = 0;
			}
		}
	}
}

///////////////////////////////////////////////////////////////////
void Level::setTile(int t_row, int t_col, Tile * t_tile)
{
	// Bad code - Bad system - should be refactored
	if (typeid(*t_tile).name() == typeid(CheckpointTile).name())
	{
		m_checkpointTiles.push_back({ t_col, t_row });
	}

	m_tiles.at(t_row).at(t_col).reset(t_tile);
}

///////////////////////////////////////////////////////////////////
Tile const & Level::getTile(int t_row, int t_col) const
{
	return *m_tiles.at(t_row).at(t_col);
}

///////////////////////////////////////////////////////////////////
sf::Vector2i const Level::getSize() const
{
	return { static_cast<int>(m_tiles.at(0).size()), static_cast<int>(m_tiles.size()) };
}

///////////////////////////////////////////////////////////////////
void Level::draw(sf::RenderWindow& t_window, sf::Sprite& t_tileSprite)
{
	sf::Vector2i size = getSize();

	for (int row = 0; row < size.y; row++)
	{
		for (int col = 0; col < size.x; col++)
		{
			t_tileSprite.setPosition(col * t_tileSprite.getGlobalBounds().width, row * t_tileSprite.getGlobalBounds().height);

			switch (m_backgroundTiles[row][col])
			{
			case 1:
				t_tileSprite.setTextureRect({ 16, 32, 16, 16 });
				break;
			case 2:
				t_tileSprite.setTextureRect({ 0, 48, 16, 16 });
				break;
			case 3:
				t_tileSprite.setTextureRect({ 16, 48, 16, 16 });
				break;
			default:
				t_tileSprite.setTextureRect({ 0, 32, 16, 16 });
				break;
			}

			t_window.draw(t_tileSprite);

			if (getTile(row, col).isVisible())
			{
				t_tileSprite.setTextureRect(getTile(row, col).getTextureRect());
				t_window.draw(t_tileSprite);
			}
		}
	}
}

///////////////////////////////////////////////////////////////////
sf::Vector2i const Level::getCurrentCheckpointTile() const
{
	if (m_currentCheckpoint < m_checkpointTiles.size())
	{
		return m_checkpointTiles.at(m_currentCheckpoint);
	}
	
	return { 0, 0 };
}

///////////////////////////////////////////////////////////////////
/// Bad code vv
/// Should be majorly refactored ASAP
void Level::nextCheckpoint()
{
	if (m_currentCheckpoint + 1 < m_checkpointTiles.size())
	{
		// Disable the previous checkpoint
		// Get a checkpoint tile pointer from the base tile pointer
		sf::Vector2i checkpointPos = m_checkpointTiles.at(m_currentCheckpoint);
		Tile * lastCheckpoint = m_tiles[checkpointPos.y][checkpointPos.x].get();
		CheckpointTile * checkpoint = dynamic_cast<CheckpointTile *>(lastCheckpoint);

		if (checkpoint != nullptr)
		{
			checkpoint->setEnabled(false);
		}

		m_currentCheckpoint++;

		// Enable the new current checkpoint
		// Get a checkpoint tile pointer from the base tile pointer
		checkpointPos = m_checkpointTiles.at(m_currentCheckpoint);
		lastCheckpoint = m_tiles[checkpointPos.y][checkpointPos.x].get();
		checkpoint = dynamic_cast<CheckpointTile*>(lastCheckpoint);

		if (checkpoint != nullptr)
		{
			checkpoint->setEnabled(true);
		}
	}
}

///////////////////////////////////////////////////////////////////