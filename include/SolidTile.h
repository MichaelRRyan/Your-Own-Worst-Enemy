#ifndef SOLID_TILE_H
#define SOLID_TILE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include "Tile.h"

class SolidTile : public Tile
{
public:

	sf::Color const getColor() const override;

	bool const isSolid() const override;

};


#endif // !SOLID_TILE_H

