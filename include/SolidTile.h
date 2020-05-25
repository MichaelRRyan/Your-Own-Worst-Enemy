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

	SolidTile(int const t_textureNum = 0);

	sf::IntRect const getTextureRect() const override;

	bool const isSolid() const override;

	bool const isVisible() const override;

private:

	int const m_textureNum;

};


#endif // !SOLID_TILE_H

