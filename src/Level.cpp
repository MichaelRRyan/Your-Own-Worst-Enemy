/// @Author Michael Rainsford Ryan

#include "Level.h"

///////////////////////////////////////////////////////////////////

void Level::setTile(int t_row, int t_col, Tile * t_tile)
{
	m_tiles.at(t_row).at(t_col).reset(t_tile);
}

Tile const & Level::getTile(int t_row, int t_col) const
{
	return *m_tiles.at(t_row).at(t_col);
}

sf::Vector2i const Level::getSize() const
{
	return { static_cast<int>(m_tiles.at(0).size()), static_cast<int>(m_tiles.size()) };
}
