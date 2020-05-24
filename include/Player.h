#ifndef PLAYER_H
#define PLAYER_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include "Entity.h"
#include "AnimatedSprite.h"
#include "Input.h"
#include "CollisionDetector.h"
#include "VectorMath.h"

class Player : public Entity
{
public:

	Player();

	virtual void update(sf::Time const& t_deltaTime, Level const& t_levelRef) override;

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const override;

	static float constexpr s_MOVE_ACCELERATION{ 0.05f };
	static float constexpr s_MAX_MOVE_SPEED{ 1.0f };
	static float constexpr s_GROUND_FRICTION{ 0.85f };
	static float constexpr s_AIR_FRICTION{ 0.99f };
	static float constexpr s_JUMP_SPEED{ 4.0f };
	static float constexpr s_GRAVITY{ 0.2f };

	AnimatedSprite m_animatedSprite;

	sf::Texture m_texture;

	sf::Vector2f m_velocity;

	bool m_onGround;

};

#endif // !PLAYER_H

