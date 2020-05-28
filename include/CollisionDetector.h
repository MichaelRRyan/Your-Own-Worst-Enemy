#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include <SFML/Graphics.hpp>
#include "Level.h"

struct CollisionInfo
{
	bool solid{ false };
	bool deadly{ false };
};

class CollisionDetector
{
public:

	static CollisionInfo isColliding(Level const & t_level, sf::FloatRect const & t_collisionBounds);

	static bool isColliding(sf::FloatRect const& t_collisionBounds1, sf::FloatRect const& t_collisionBounds2);

};

#endif // !COLLISION_HANDLER_H
