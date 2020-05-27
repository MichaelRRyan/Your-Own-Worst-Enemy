#ifndef ZOMBIE_H
#define ZOMBIE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 26/05/2020
/// </summary>

#include <memory>

#include "Entity.h"
#include "AnimatedSprite.h"
#include "Input.h"
#include "CollisionDetector.h"
#include "VectorMath.h"
#include "Player.h"

class Zombie : public Entity
{
public:

	Zombie(sf::Vector2f t_tilePosition, std::weak_ptr<Entity> t_target);

	virtual void update(sf::Time const& t_deltaTime, Level const& t_levelRef) override;

	virtual sf::FloatRect const getCollisionBounds() const override;

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const override;

	static float constexpr s_MOVE_ACCELERATION{ 0.02f };
	static float constexpr s_MAX_MOVE_SPEED{ 0.4f };
	static float constexpr s_GROUND_FRICTION{ 0.80f };
	static float constexpr s_AIR_FRICTION{ 0.99f };
	static float constexpr s_JUMP_SPEED{ 3.5f };
	static float constexpr s_GRAVITY{ 0.15f };

	AnimatedSprite m_animatedSprite;

	sf::Texture m_texture;

	sf::Vector2f m_velocity;

	bool m_onGround;

	std::weak_ptr<Entity> m_target;

};

#endif // !ZOMBIE_H

