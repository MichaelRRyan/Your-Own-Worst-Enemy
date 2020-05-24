#ifndef LEVEL_H
#define LEVEL_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <array>
#include <memory>

#include "Tile.h"

class Level
{
public:

	void setTile(int t_row, int t_col, Tile * t_tile);

	Tile const & getTile(int t_row, int t_col) const;

	sf::Vector2i const getSize() const;

private:

	std::array<std::array<std::shared_ptr<Tile>, 20>, 10> m_tiles;

};

#endif // !ENTITY_H

