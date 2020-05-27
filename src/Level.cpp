/// @Author Michael Rainsford Ryan

#include "Level.h"

///////////////////////////////////////////////////////////////////
Level::Level()
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
			if (getTile(row, col).isVisible())
			{
				t_tileSprite.setPosition(col * t_tileSprite.getGlobalBounds().width, row * t_tileSprite.getGlobalBounds().height);
				t_tileSprite.setTextureRect(getTile(row, col).getTextureRect());
				t_window.draw(t_tileSprite);
			}
			else
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
			}
		}
	}
}

///////////////////////////////////////////////////////////////////