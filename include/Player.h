#ifndef PLAYER_H
#define PLAYER_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include "PhysicsBody.h"
#include "AnimatedSprite.h"
#include "Input.h"
#include "CollisionDetector.h"
#include "VectorMath.h"

class Player : public PhysicsBody
{
public:

	Player();

	virtual void update(sf::Time const& t_deltaTime, Level const& t_levelRef) override;

	virtual sf::FloatRect const getCollisionBounds() const override;

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const override;

	void updateAnimatedSprite();

	AnimatedSprite m_animatedSprite;

	sf::Texture m_texture;

};

#endif // !PLAYER_H

