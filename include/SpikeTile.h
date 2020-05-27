#ifndef SPIKE_TILE_H
#define SPIKE_TILE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 27/05/2020
/// </summary>

#include "Tile.h"

class SpikeTile : public Tile
{
public:

	SpikeTile(int const t_textureNum = 0);

	sf::IntRect const getTextureRect() const override;

	bool const isSolid() const override;

	bool const isVisible() const override;

	bool const isDeadly() const override;

private:

	int const m_textureNum;

};


#endif // !SPIKE_TILE_H

