/// @Author Michael Rainsford Ryan

#include "Player.h"

///////////////////////////////////////////////////////////////////
Player::Player()
{
	if (!m_texture.loadFromFile("assets/images/sprite_sheet.png"))
	{
		throw("Error loading character sprite sheet");
	}

	m_animatedSprite.addAnimation("walk", Animation{ m_texture, { 32, 0, 16, 16 } });
	m_animatedSprite.addFrame("walk", { 0, 0, 16, 16 });
	m_animatedSprite.addFrame("walk", { 48, 0, 16, 16 });
	m_animatedSprite.addFrame("walk", { 0, 0, 16, 16 });

	m_animatedSprite.addAnimation("idle", Animation{ m_texture, { 0, 0, 16, 16 } });
	m_animatedSprite.addFrame("idle", { 0, 0, 16, 16 });
	m_animatedSprite.addFrame("idle", { 16, 0, 16, 16 });
	m_animatedSprite.addFrame("idle", { 16, 0, 16, 16 });
}

///////////////////////////////////////////////////////////////////
void Player::update(sf::Time const& t_deltaTime, Level const& t_levelRef)
{
	m_animatedSprite.update(t_deltaTime);
}

///////////////////////////////////////////////////////////////////
void Player::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_animatedSprite, t_states);
}

///////////////////////////////////////////////////////////////////