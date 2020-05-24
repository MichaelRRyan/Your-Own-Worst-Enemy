/// @Author Michael Rainsford Ryan

#include "AnimatedSprite.h"

///////////////////////////////////////////////////////////////////
void AnimatedSprite::update()
{
}

///////////////////////////////////////////////////////////////////
void AnimatedSprite::addAnimation(std::string const& t_animationName, Animation const& t_animation)
{
	if (m_animations.empty())
	{
		m_sprite.setTexture(t_animation.getTexture());
		m_sprite.setTextureRect(t_animation.getFrame(0));
	}

	m_animations.emplace(t_animationName, t_animation);
}

///////////////////////////////////////////////////////////////////
void AnimatedSprite::addFrame(std::string const& t_animationName, sf::IntRect const& t_frame)
{
	m_animations.at(t_animationName).addFrame(t_frame);
}

///////////////////////////////////////////////////////////////////
void AnimatedSprite::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_sprite);
}

///////////////////////////////////////////////////////////////////