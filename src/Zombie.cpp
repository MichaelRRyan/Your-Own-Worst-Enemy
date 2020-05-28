/// @Author Michael Rainsford Ryan

#include "Zombie.h"

///////////////////////////////////////////////////////////////////

Zombie::Zombie(sf::Vector2f t_position, std::weak_ptr<Entity> t_target) :
	m_target{ t_target }
{
	m_size = { 12.0f, 14.0f };
	m_moveAcceleration = 0.02f;
	m_maxMoveSpeed = 0.4f;
	m_active = true;

	m_position = t_position;

	if (!m_texture.loadFromFile("assets/images/sprite_sheet.png"))
	{
		std::exception exception("Error loading character sprite sheet");
		throw(exception);
	}

	m_animatedSprite.addAnimation("idle", Animation{ m_texture, { 0, 16, 16, 16 } });
	m_animatedSprite.addFrame("idle", { 16, 16, 16, 16 });
	m_animatedSprite.addFrame("idle", { 32, 16, 16, 16 });
	m_animatedSprite.addFrame("idle", { 48, 16, 16, 16 });

	m_animatedSprite.addAnimation("walk", Animation{ m_texture, { 64, 16, 16, 16 } });
	m_animatedSprite.addFrame("walk", { 0, 16, 16, 16 });
	m_animatedSprite.addFrame("walk", { 80, 16, 16, 16 });
	m_animatedSprite.addFrame("walk", { 0, 16, 16, 16 });

	m_animatedSprite.setOrigin(8.0f, 9.0f);
}

void Zombie::update(sf::Time const& t_deltaTime, Level const& t_levelRef)
{
	if (m_active)
	{
		m_animatedSprite.update(t_deltaTime);

		// TEMP - Bad code, should be refactored
		Player * playerPtr = dynamic_cast<Player *>(m_target.lock().get());

		if (playerPtr != nullptr && playerPtr->isActive())
		{
			sf::FloatRect const targetBounds = playerPtr->getCollisionBounds();

			if (targetBounds.left > getCollisionBounds().left)
			{
				accelerateRight();
				m_animatedSprite.setScale(1.0f, 1.0f);
			}
			else
			{
				accelerateLeft();
				m_animatedSprite.setScale(-1.0f, 1.0f);
			}

			if (CollisionDetector::isColliding(getCollisionBounds(), targetBounds))
			{
				playerPtr->die();
			}
		}

		if (isAccelerating())
		{
			m_animatedSprite.startAnimating("walk");
		}
		else
		{
			m_animatedSprite.startAnimating("idle");
		}

		updatePhysics(t_levelRef);

		m_animatedSprite.setPosition(m_position);
	}
}

sf::FloatRect const Zombie::getCollisionBounds() const
{
	return { m_animatedSprite.getPosition() - m_size / 2.0f, m_size };
}

void Zombie::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	if (m_active)
	{
		t_target.draw(m_animatedSprite);
	}
}
