/// @Author Michael Rainsford Ryan

#include "SolidTile.h"

///////////////////////////////////////////////////////////////////
SolidTile::SolidTile(int t_textureNum) :
	m_textureNum{ t_textureNum }
{
}

///////////////////////////////////////////////////////////////////
sf::IntRect const SolidTile::getTextureRect() const
{
	switch (m_textureNum)
	{
	case 1:
		return { 32, 0, 16, 16 };
	case 2:
		return { 0, 0, 16, 16 };
	case 3:
		return { 16, 0, 16, 16 };
	case 4:
		return { 0, 16, 16, 16 };
	case 5:
		return { 16, 16, 16, 16 };
	default:
		return { 32, 16, 16, 16 };
	}
}

///////////////////////////////////////////////////////////////////
bool const SolidTile::isSolid() const
{
	return true;
}

bool const SolidTile::isVisible() const
{
	return true;
}

///////////////////////////////////////////////////////////////////