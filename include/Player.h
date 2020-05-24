#ifndef PLAYER_H
#define PLAYER_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include "Entity.h"
#include "AnimatedSprite.h"

class Player : public Entity
{
public:

	Player();

	virtual void update(Level const& t_levelRef) override;

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const override;

	AnimatedSprite m_animatedSprite;

	sf::Texture m_texture;

};

#endif // !PLAYER_H

