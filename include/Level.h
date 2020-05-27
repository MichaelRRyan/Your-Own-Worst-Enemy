#ifndef LEVEL_H
#define LEVEL_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <array>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Tile.h"

class Level
{
public:

	Level();

	void setTile(int t_row, int t_col, Tile * t_tile);

	Tile const & getTile(int t_row, int t_col) const;

	sf::Vector2i const getSize() const;

	void draw(sf::RenderWindow& t_window, sf::Sprite & t_tileSprite);

private:

	std::array<std::array<std::shared_ptr<Tile>, 20>, 10> m_tiles;

	std::array<std::array<int, 20>, 10> m_backgroundTiles;

};

#endif // !ENTITY_H

