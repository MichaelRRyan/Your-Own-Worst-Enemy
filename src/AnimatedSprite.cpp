/// @Author Michael Rainsford Ryan

#include "AnimatedSprite.h"

///////////////////////////////////////////////////////////////////
void AnimatedSprite::update(sf::Time const& t_deltaTime)
{
	// Get the previous frame
	int prevFrame = static_cast<int>(m_elapsedTime.asSeconds() / m_animations.at(m_currentAnimation).getTimePerFrame().asSeconds());

	// Increment the elapsed time
	m_elapsedTime += t_deltaTime;

	// Get the length of the animation
	sf::Time animationLength = m_animations.at(m_currentAnimation).getTimePerFrame() * static_cast<float>(m_animations.at(m_currentAnimation).getSize());

	// If the elapsed time is greater than the animation length remove the animation length (loop animation)
	if (m_elapsedTime > animationLength)
	{
		m_elapsedTime -= animationLength;
	}

	int currentFrame = static_cast<int>(m_elapsedTime.asSeconds() / m_animations.at(m_currentAnimation).getTimePerFrame().asSeconds());

	// If the previous frame is no the same as the current, update the sprite
	if (prevFrame != currentFrame)
	{
		m_sprite.setTextureRect(m_animations.at(m_currentAnimation).getFrame(currentFrame));
	}
}

///////////////////////////////////////////////////////////////////
void AnimatedSprite::addAnimation(std::string const& t_animationName, Animation const& t_animation)
{
	m_animations.emplace(t_animationName, t_animation);

	// If this was the first animation added, start animating that
	if (m_animations.size() == 1)
	{
		startAnimating(t_animationName);
	}
}

///////////////////////////////////////////////////////////////////
void AnimatedSprite::addFrame(std::string const& t_animationName, sf::IntRect const& t_frame)
{
	m_animations.at(t_animationName).addFrame(t_frame);
}

///////////////////////////////////////////////////////////////////
void AnimatedSprite::startAnimating(std::string const& t_animationName)
{
	if (m_animations.count(t_animationName))
	{
		m_currentAnimation = t_animationName; // Set the current animation name
		m_elapsedTime = sf::Time::Zero; // Reset the elapsed time

		// Update the sprite
		m_sprite.setTexture(m_animations.at(t_animationName).getTexture());
		m_sprite.setTextureRect(m_animations.at(t_animationName).getFrame(0));
	}
	else
	{
		throw("No animation called \"" + t_animationName + "\"");
	}
}

///////////////////////////////////////////////////////////////////
void AnimatedSprite::draw(sf::RenderTarget& t_target, sf::RenderStates t_states) const
{
	t_target.draw(m_sprite);
}

///////////////////////////////////////////////////////////////////