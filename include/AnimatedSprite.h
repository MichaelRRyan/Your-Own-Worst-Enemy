#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

#include "Animation.h"

class AnimatedSprite : public sf::Drawable
{
public:

	void update();

	void addAnimation(std::string const & t_animationName, Animation const & t_animation);

	void addFrame(std::string const & t_animationName, sf::IntRect const & t_frame);

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const override;

	sf::Sprite m_sprite;

	std::map<std::string, Animation> m_animations;

};

#endif // !ANIMATED_SPRITE_H
