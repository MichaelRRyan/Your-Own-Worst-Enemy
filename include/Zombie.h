#ifndef ZOMBIE_H
#define ZOMBIE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 26/05/2020
/// </summary>

#include <memory>

#include "PhysicsBody.h"
#include "AnimatedSprite.h"
#include "Input.h"
#include "CollisionDetector.h"
#include "VectorMath.h"
#include "Player.h"

class Zombie : public PhysicsBody
{
public:

	Zombie(sf::Vector2f t_position, std::weak_ptr<Entity> t_target);

	virtual void update(sf::Time const& t_deltaTime, Level const& t_levelRef) override;

	virtual sf::FloatRect const getCollisionBounds() const override;

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const override;

	AnimatedSprite m_animatedSprite;

	sf::Texture m_texture;

	std::weak_ptr<Entity> m_target;

};

#endif // !ZOMBIE_H

