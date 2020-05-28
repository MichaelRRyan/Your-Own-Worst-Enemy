/// @Author Michael Rainsford Ryan

#include "Entity.h"
#include "..\include\PhysicsBody.h"

PhysicsBody::PhysicsBody() :
	m_onGround{ false },
	m_accelerating{ false }
{
}

///////////////////////////////////////////////////////////////////
sf::Vector2f const& PhysicsBody::getPosition() const
{
	return m_position;
}

///////////////////////////////////////////////////////////////////
void PhysicsBody::updatePhysics(Level const& t_levelRef)
{
	// Apply friction
	if (!m_accelerating)
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
		if (CollisionDetector::isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f + m_velocity.x, m_position.y - m_size.y / 2.0f }, m_size }).solid)
		{
			// Get the sign of the velocity
			float velocitySign = vmath::sign(m_velocity.x);

			// Move by the sign until right next to the wall
			while (!CollisionDetector::isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f + velocitySign, m_position.y - m_size.y / 2.0f }, m_size }).solid)
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
	if (CollisionDetector::isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f, m_position.y - m_size.y / 2.0f + m_velocity.y }, m_size }).solid)
	{
		// Get the sign of the velocity
		float velocitySign = vmath::sign(m_velocity.y);

		while (!CollisionDetector::isColliding(t_levelRef, { { m_position.x - m_size.x / 2.0f, m_position.y - m_size.y / 2.0f + velocitySign }, m_size }).solid)
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

	m_accelerating = false;
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
	m_accelerating = true;
}

///////////////////////////////////////////////////////////////////
void PhysicsBody::accelerateRight()
{
	m_velocity.x = std::min(m_maxMoveSpeed, m_velocity.x + m_moveAcceleration);
	m_accelerating = true;
}

///////////////////////////////////////////////////////////////////
bool const PhysicsBody::onGround() const
{
	return m_onGround;
}

///////////////////////////////////////////////////////////////////
bool const PhysicsBody::isAccelerating() const
{
	return m_accelerating;
}

///////////////////////////////////////////////////////////////////