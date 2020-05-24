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

	sf::Texture const & getTexture() const;

	sf::IntRect const & getFrame(int t_index) const;

private:

	sf::Texture const & m_texture;

	std::vector<sf::IntRect> m_frames;

};

#endif // !ANIMATION_H

