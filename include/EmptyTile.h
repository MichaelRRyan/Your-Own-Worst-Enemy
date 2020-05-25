#ifndef EMPTY_TILE_H
#define EMPTY_TILE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include "Tile.h"

class EmptyTile : public Tile
{
public:

	sf::IntRect const getTextureRect() const override;

	bool const isSolid() const override;

	bool const isVisible() const override;

};


#endif // !EMPTY_TILE_H

