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

	void update(sf::Time const & t_deltaTime);

	void addAnimation(std::string const & t_animationName, Animation const & t_animation);

	void addFrame(std::string const & t_animationName, sf::IntRect const & t_frame);

	void startAnimating(std::string const & t_animationName);

	// Transformations
	void setPosition(sf::Vector2f const & t_position);

	void setPosition(float const t_x, float const t_y);

	void move(sf::Vector2f const & t_displacement);

	void move(float const t_x, float const t_y);

	void setScale(sf::Vector2f const & t_scale);

	void setScale(float const t_x, float const t_y);

	void setOrigin(sf::Vector2f const & t_origin);

	void setOrigin(float const t_x, float const t_y);

	sf::Vector2f const & getPosition() const;

	sf::Vector2f const & getScale() const;

	sf::Vector2f const & getOrigin() const;

private:

	virtual void draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const override;

	sf::Sprite m_sprite;

	std::map<std::string, Animation> m_animations;

	sf::Time m_elapsedTime;

	std::string m_currentAnimation;

};

#endif // !ANIMATED_SPRITE_H

