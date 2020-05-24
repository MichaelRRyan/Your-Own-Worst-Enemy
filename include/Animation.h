#ifndef ANIMATION_H
#define ANIMATION_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 24/05/2020
/// </summary>

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:

	Animation(sf::Texture const & t_texture, sf::IntRect const & t_frame);

	void addFrame(sf::IntRect const & t_frame);

	void setTimePerFrame(sf::Time t_timePerFrame);

	sf::Texture const & getTexture() const;

	sf::IntRect const & getFrame(int t_index) const;

	sf::Time const & getTimePerFrame() const;

	/// <summary>
	/// Returns the number of frames in the animation
	/// </summary>
	/// <returns></returns>
	int const getSize();

private:

	sf::Texture const & m_texture;

	std::vector<sf::IntRect> m_frames;

	sf::Time m_timePerFrame;

};

#endif // !ANIMATION_H

