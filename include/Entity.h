#ifndef ENTITY_H
#define ENTITY_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <SFML/Graphics.hpp>

#include "Level.h"

class Entity : public sf::Drawable
{
public:

	virtual void update(sf::Time const& t_deltaTime, Level const & t_levelRef) = 0;

};

#endif // !ENTITY_H

