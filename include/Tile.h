#ifndef TILE_H
#define TILE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <SFML/Graphics.hpp>

class Tile
{
public:

	virtual sf::Color getColor() const = 0;

};

#endif // !TILE_H

