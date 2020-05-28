#include "CollisionDetector.h"

CollisionInfo CollisionDetector::isColliding(Level const& t_level, sf::FloatRect const& t_collisionBounds)
{
	int minRow = static_cast<int>(t_collisionBounds.top / 16.0f);
	int maxRow = static_cast<int>((t_collisionBounds.top + t_collisionBounds.height) / 16.0f);
	int minCol = static_cast<int>(t_collisionBounds.left / 16.0f);
	int maxCol = static_cast<int>((t_collisionBounds.left + t_collisionBounds.width) / 16.0f);

	CollisionInfo info;

	if (t_collisionBounds.top < 0 || t_collisionBounds.left < 0 || maxRow >= t_level.getSize().y || maxCol >= t_level.getSize().x)
	{
		info.solid = true;
		return info;
	}

	for (int row = minRow; row <= maxRow; row++)
	{
		for (int col = minCol; col <= maxCol; col++)
		{	
			// Colliding
			if (t_level.getTile(row, col).isSolid())
			{
				info.solid = true;
			}
			if (t_level.getTile(row, col).isDeadly())
			{
				info.deadly = true;
			}
		}
	}

	return info;
}

bool CollisionDetector::isColliding(sf::FloatRect const& t_collisionBounds1, sf::FloatRect const& t_collisionBounds2)
{
	if (t_collisionBounds1.left < t_collisionBounds2.left + t_collisionBounds2.width
		&& t_collisionBounds1.left + t_collisionBounds1.width > t_collisionBounds2.left)
	{
		if (t_collisionBounds1.top < t_collisionBounds2.top + t_collisionBounds2.height
			&& t_collisionBounds1.top + t_collisionBounds1.height > t_collisionBounds2.top)
		{
			return true;
		}
	}

	return false;
}
