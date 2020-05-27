/// @Author Michael Rainsford Ryan

#include "Player.h"

///////////////////////////////////////////////////////////////////
Player::Player()
{
	m_size = { 12.0f, 14.0f };
	m_position = { 8.0f, 8.0f };

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

	m_animatedSprite.addAnimation("jump", Animation{ m_texture, { 64, 0, 16, 16 } });

	m_animatedSprite.setOrigin(8.0f, 9.0f);
}

///////////////////////////////////////////////////////////////////
void Player::update(sf::Time const& t_deltaTime, Level const& t_levelRef)
{
	m_animatedSprite.update(t_deltaTime);

	bool moved{ false };

	// Get movement input
	if (Input::getCurrentState().moveRight && !Input::getCurrentState().moveLeft)
	{
		accelerateRight();
		m_animatedSprite.setScale(1.0f, 1.0f);
		moved = true;
	}
	else if (Input::getCurrentState().moveLeft && !Input::getCurrentState().moveRight)
	{
		accelerateLeft();
		m_animatedSprite.setScale(-1.0f, 1.0f);
		moved = true;
	}

	// Jump
	if (Input::getCurrentState().jump && !Input::getPreviousState().jump)
	{
		jump();
	}

	if (onGround())
	{
		if (moved)
		{
			m_animatedSprite.startAnimating("walk");
		}
		else
		{
			m_animatedSprite.startAnimating("idle");
		}
	}
	else
	{
		m_animatedSprite.startAnimating("jump");
	}

	updatePhysics(t_levelRef);

	m_animatedSprite.setPosition(m_position);
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