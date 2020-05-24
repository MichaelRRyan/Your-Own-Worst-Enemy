#ifndef VECTOR_MATH_H
#define VECTOR_MATH_H

#include <SFML/Graphics.hpp>
#include <cassert>

namespace vmath
{
	/// Vector math functions

	float const lengthSquared(sf::Vector2f const t_vector);

	float const length(sf::Vector2f const t_vector);

	float const dotProduct(sf::Vector2f const t_vectorA, sf::Vector2f const t_vectorB);

	float const angleBetween(sf::Vector2f const t_vectorA, sf::Vector2f const t_vectorB);

	float const polarAngle(sf::Vector2f const t_vector);

	sf::Vector2f const unitVector(sf::Vector2f const t_vector);

	sf::Vector2f const perpendicularVector(sf::Vector2f const t_vector);

	sf::Vector2f const projection(sf::Vector2f const t_vector, sf::Vector2f const t_onto);

	sf::Vector2f const rotatedVector(sf::Vector2f const t_vector, float const t_angleRad);

	void rotate(sf::Vector2f& t_vector, float const t_angleRad);

	// Float math

	float const sign(float const t_value);

	float const clamp(float const t_value, float const t_min, float const t_max);
}

#endif // !VECTOR_MATH_H