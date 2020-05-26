/// @Author Michael Rainsford Ryan

#include "Player.h"

///////////////////////////////////////////////////////////////////
Player::Player() :
	m_onGround{ false }
{
	m_size = { 12.0f, 14.0f };

	if (!m_texture.loadFromFile("assets/images/sprite_sheet.png"))
	{
		std::exception exception("Error loading character sprite sheet");
		throw(exception);
	}

	m_animatedSprite.addAnimation("walk", Animation{ m_texture, { 32, 0, 16, 16 } });
	m_animatedSprite.addFrame("walk", { 0, 0, 16, 16 });
	m_animatedSprite.addFrame("walk", { 48, 0, 16, 16 });
	m_animatedSprite.addFrame("walk", { 0, 0, 16, 16 });

	m_animatedSprite.addAnimation("idle", Animation{ m_texture, { 0, 0, 16, 16 } });
	m_animatedSprite.addFrame("idle", { 0, 0, 16, 16 });
	m_animatedSprite.addFrame("idle", { 16, 0, 16, 16 });
	m_animatedSprite.addFrame("idle", { 16, 0, 16, 16 });

	m_animatedSprite.setOrigin(8.0f, 9.0f);
	m_animatedSprite.setPosition(8.0f, 8.0f);
}

///////////////////////////////////////////////////////////////////
void Player::update(sf::Time const& t_deltaTime, Level const& t_levelRef)
{
	m_animatedSprite.update(t_deltaTime);

	// Take left and right movement input
	float input = 0.0f;

	// Get movement input
	if (Input::getCurrentState().moveRight)
	{
		input += 1.0f;
		m_animatedSprite.setScale(1.0f, 1.0f);
	}

	if (Input::getCurrentState().moveLeft)
	{
		input -= 1.0f;
		m_animatedSprite.setScale(-1.0f, 1.0f);
	}

	// Set the velocity and clamp it to a max speed
	m_velocity.x += input * s_MOVE_ACCELERATION;

	m_velocity.x = vmath::clamp(m_velocity.x, -s_MAX_MOVE_SPEED, s_MAX_MOVE_SPEED);

	// Apply gravity
	m_velocity.y += s_GRAVITY;

	// Apply friction
	if (input == 0.0f)
	{
		m_animatedSprite.startAnimating("idle");

		if (m_onGround)
		{
			m_velocity.x = m_velocity.x * s_GROUND_FRICTION;
		}
		else
		{
			m_velocity.x = m_velocity.x * s_AIR_FRICTION;
		}
	}
	else
	{
		m_animatedSprite.startAnimating("walk");
	}

	// Jump
	if (Input::getCurrentState().jump && !Input::getPreviousState().jump)
	{
		if (m_onGround)
		{
			m_velocity.y = -s_JUMP_SPEED;
		}
	}

	m_onGround = false;

	// Horizontal collisions
	if (m_velocity.x != 0.0f)
	{
		if (CollisionDetector::isColliding(t_levelRef, { { m_animatedSprite.getPosition().x - m_size.x / 2.0f + m_velocity.x, m_animatedSprite.getPosition().y - m_size.y / 2.0f }, m_size }))
		{
			// Get the sign of the velocity
			float velocitySign = vmath::sign(m_velocity.x);

			// Move by the sign until right next to the wall
			while (!CollisionDetector::isColliding(t_levelRef, { { m_animatedSprite.getPosition().x - m_size.x / 2.0f + velocitySign, m_animatedSprite.getPosition().y - m_size.y / 2.0f }, m_size }))
			{
				m_animatedSprite.move(velocitySign, 0.0f);
			}

			m_velocity.x = 0.0f;
		}
		else
		{
			m_animatedSprite.move(m_velocity.x, 0.0f);
		}
	}

	// Vertical collisions
	if (CollisionDetector::isColliding(t_levelRef, { { m_animatedSprite.getPosition().x - m_size.x / 2.0f, m_animatedSprite.getPosition().y - m_size.y / 2.0f + m_velocity.y }, m_size }))
	{
		// Get the sign of the velocity
		float velocitySign = vmath::sign(m_velocity.y);

		while (!CollisionDetector::isColliding(t_levelRef, { { m_animatedSprite.getPosition().x - m_size.x / 2.0f, m_animatedSprite.getPosition().y - m_size.y / 2.0f + velocitySign }, m_size }))
		{
			m_animatedSprite.move(0.0f, velocitySign);
		}

		if (velocitySign > 0)
		{
			m_onGround = true;
		}

		m_velocity.y = 0.0f;
	}
	else
	{
		m_animatedSprite.move(0.0f, m_velocity.y);
	}
}

///////////////////////////////////////////////////////////////////
sf::FloatRect const Player::getCollisionBounds() const
{
	return { m_animatedSprite.getPosition() - m_size / 2.0f, m_size };
}

///////////////////////////////////////////////////////////////////
void Player::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_animatedSprite, t_states);
}

///////////////////////////////////////////////////////////////////