#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 27/05/2020
/// </summary>

#include "Entity.h"
#include "Subject.h"
#include "CollisionDetector.h"
#include "VectorMath.h"

class PhysicsBody : public Entity, public Subject
{
public:

	PhysicsBody();

	virtual void update(sf::Time const& t_deltaTime, Level const & t_levelRef) = 0;

	virtual sf::FloatRect const getCollisionBounds() const = 0;

	sf::Vector2f const & getPosition() const;

protected:

	void updatePhysics(Level const& t_levelRef);

	void jump();

	void accelerateLeft();

	void accelerateRight();

	bool const onGround() const;

	bool const isAccelerating() const;

	float m_moveAcceleration{ 0.05f };
	float m_maxMoveSpeed{ 1.0f };
	float m_groundFriction{ 0.80f };
	float m_airFriction{ 0.99f };
	float m_jumpSpeed{ 3.5f };
	float m_gravity{ 0.15f };

	sf::Vector2f m_position;

	sf::Vector2f m_velocity;


private:

	bool m_onGround;

	bool m_accelerating;

};

#endif // !PHYSICS_BODY_H

