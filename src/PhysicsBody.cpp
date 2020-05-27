/// @Author Michael Rainsford Ryan

#include "Entity.h"
#include "..\include\PhysicsBody.h"

PhysicsBody::PhysicsBody() :
	m_onGround{ false },
	m_horizontalVelocityChanged{ false }
{
}

///////////////////////////////////////////////////////////////////
void PhysicsBody::updatePhysics(Level const& t_levelRef)
{
	// Apply friction
	if (!m_horizontalVelocityChanged)
	{
		if (m_onGround)
		{
			m_velocity.x = m_velocity.x * m_groundFriction;
		}
		else
		{
			m_velocity.x = m_velocity.x * m_airFriction;
		}
	}

	m_onGround = false;

	// Horizontal collisions
	if (m_velocity.x != 0.0f)
	{
		if (isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f + m_velocity.x, m_position.y - m_size.y / 2.0f }, m_size }))
		{
			// Get the sign of the velocity
			float velocitySign = vmath::sign(m_velocity.x);

			// Move by the sign until right next to the wall
			while (!isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f + velocitySign, m_position.y - m_size.y / 2.0f }, m_size }))
			{
				m_position.x += velocitySign;
			}

			m_velocity.x = 0.0f;
		}
		else
		{
			m_position.x += m_velocity.x;
		}
	}

	// Vertical collisions
	if (isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f, m_position.y - m_size.y / 2.0f + m_velocity.y }, m_size }))
	{
		// Get the sign of the velocity
		float velocitySign = vmath::sign(m_velocity.y);

		while (!isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f, m_position.y - m_size.y / 2.0f + velocitySign }, m_size }))
		{
			m_position.y += velocitySign;
		}

		if (velocitySign > 0)
		{
			m_onGround = true;
		}

		m_velocity.y = 0.0f;
	}
	else
	{
		m_position.y += m_velocity.y;
	}


	// Apply gravity
	m_velocity.y += m_gravity;

	m_horizontalVelocityChanged = false;
}

///////////////////////////////////////////////////////////////////
void PhysicsBody::jump()
{
	if (m_onGround)
	{
		m_velocity.y = -m_jumpSpeed;
	}
}

///////////////////////////////////////////////////////////////////
void PhysicsBody::accelerateLeft()
{
	m_velocity.x = std::max(-m_maxMoveSpeed, m_velocity.x - m_moveAcceleration);
	m_horizontalVelocityChanged = true;
}

///////////////////////////////////////////////////////////////////
void PhysicsBody::accelerateRight()
{
	m_velocity.x = std::min(m_maxMoveSpeed, m_velocity.x + m_moveAcceleration);
	m_horizontalVelocityChanged = true;
}

///////////////////////////////////////////////////////////////////
bool const PhysicsBody::onGround() const
{
	return m_onGround;
}

///////////////////////////////////////////////////////////////////
/// A near replica of the collision function in CollisionHandler, should be rethought
bool const PhysicsBody::isColliding(Level const& t_level, sf::FloatRect const& t_collisionBounds)
{
	int minRow = static_cast<int>(t_collisionBounds.top / 16.0f);
	int maxRow = static_cast<int>((t_collisionBounds.top + t_collisionBounds.height) / 16.0f);
	int minCol = static_cast<int>(t_collisionBounds.left / 16.0f);
	int maxCol = static_cast<int>((t_collisionBounds.left + t_collisionBounds.width) / 16.0f);

	bool colliding{ false };
	bool touchingDeadly{ false };

	if (t_collisionBounds.top < 0 || t_collisionBounds.left < 0 || maxRow >= t_level.getSize().y || maxCol >= t_level.getSize().x)
	{
		return true;
	}

	for (int row = minRow; row <= maxRow; row++)
	{
		for (int col = minCol; col <= maxCol; col++)
		{
			if (t_level.getTile(row, col).isSolid())
			{
				// Colliding
				colliding = true;
			}
			if (!touchingDeadly && t_level.getTile(row, col).isDeadly())
			{
				touchingDeadly = true;
				notify(this, ObserverEvent::EntityDied);
			}
		}
	}

	return colliding;;
}

///////////////////////////////////////////////////////////////////