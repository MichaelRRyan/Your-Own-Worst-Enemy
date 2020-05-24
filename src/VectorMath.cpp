#include "VectorMath.h"

//////////////////  VECTOR MATH FUNCTIONS  ////////////////////////


///////////////////////////////////////////////////////////////////
float const vmath::lengthSquared(sf::Vector2f const t_vector)
{
	return t_vector.x * t_vector.x + t_vector.y * t_vector.y;
}

///////////////////////////////////////////////////////////////////
float const vmath::length(sf::Vector2f const t_vector)
{
	return sqrtf(lengthSquared(t_vector));
}

///////////////////////////////////////////////////////////////////
float const vmath::dotProduct(sf::Vector2f const t_vectorA, sf::Vector2f const t_vectorB)
{
	return (t_vectorA.x * t_vectorB.x) + (t_vectorA.y * t_vectorB.y);
}

///////////////////////////////////////////////////////////////////
float const vmath::angleBetween(sf::Vector2f const t_vectorA, sf::Vector2f const t_vectorB)
{
	float const dot{ dotProduct(t_vectorA, t_vectorB) }; // Get the dot product of the two vectors

	float const lens{ length(t_vectorA) * length(t_vectorB) }; // Get the two lengths multiplied together

	return acosf(dot / lens); // Return the angle
}

///////////////////////////////////////////////////////////////////
float const vmath::polarAngle(sf::Vector2f const t_vector)
{
	return atan2f(t_vector.y, t_vector.x);
}

///////////////////////////////////////////////////////////////////
sf::Vector2f const vmath::unitVector(sf::Vector2f const t_vector)
{
	assert(t_vector != sf::Vector2f()); // Check the vector is not a zero vector
	return t_vector / length(t_vector);
}

///////////////////////////////////////////////////////////////////
sf::Vector2f const vmath::perpendicularVector(sf::Vector2f const t_vector)
{
	return sf::Vector2f{ -t_vector.y, t_vector.x };
}

///////////////////////////////////////////////////////////////////
sf::Vector2f const vmath::projection(sf::Vector2f const t_vector, sf::Vector2f const t_onto)
{
	assert(t_onto != sf::Vector2f()); // Check the onto vector is not a zero vector

	float const multiplier{ dotProduct(t_vector, t_onto) / lengthSquared(t_onto) };

	return t_onto * multiplier;
}

///////////////////////////////////////////////////////////////////
sf::Vector2f const vmath::rotatedVector(sf::Vector2f const t_vector, float const t_angleRad)
{
	sf::Vector2f copy{ t_vector };

	rotate(copy, t_angleRad);

	return copy;
}

///////////////////////////////////////////////////////////////////

void vmath::rotate(sf::Vector2f& t_vector, float const t_angleRad)
{
	// Don't manipulate x and y separately, otherwise they're overwritten too early (Thor library's explanation)
	t_vector = sf::Vector2f{
		cosf(t_angleRad) * t_vector.x - sinf(t_angleRad) * t_vector.y,
		sinf(t_angleRad) * t_vector.x + cosf(t_angleRad) * t_vector.y };
}

///////////////////////////////////////////////////////////////////
float const vmath::sign(float const t_value)
{
	if (t_value > 0.0f)
	{
		return 1.0f;
	}
	else if (t_value < 0.0f)
	{
		return -1.0f;
	}

	return 0.0f;
}

///////////////////////////////////////////////////////////////////
float const vmath::clamp(float const t_value, float const t_min, float const t_max)
{
	if (t_value < t_min)
	{
		return t_min;
	}
	else if (t_value > t_max)
	{
		return t_max;
	}

	return t_value;
}

///////////////////////////////////////////////////////////////////