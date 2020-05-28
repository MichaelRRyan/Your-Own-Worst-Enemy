#ifndef CHECKPOINT_TILE_H
#define CHECKPOINT_TILE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 28/05/2020
/// </summary>

#include "Tile.h"

class CheckpointTile : public Tile
{
public:

	CheckpointTile(bool const t_enabled = false);

	sf::IntRect const getTextureRect() const override;

	bool const isSolid() const override;

	bool const isVisible() const override;

	bool const isDeadly() const override;

	void setEnabled(bool const t_state);

private:

	bool m_enabled;

};


#endif // !CHECKPOINT_TILE_H

