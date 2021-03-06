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

	virtual sf::IntRect const getTextureRect() const = 0;

	virtual bool const isSolid() const = 0;

	virtual bool const isVisible() const = 0;

	virtual bool const isDeadly() const = 0;

};

#endif // !TILE_H

