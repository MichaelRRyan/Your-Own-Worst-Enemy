#ifndef INPUT_H
#define INPUT_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 18/04/2020
/// </summary>

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gamepad.h"

/// <summary>
/// A struct for storing the state of the input.
/// </summary>
struct InputState
{
	bool jump;
	bool moveLeft;
	bool moveRight;
	bool moveUp;
	bool moveDown;

	sf::Vector2f cursorPosition;
};

/// <summary>
/// A class for getting and storing input data.
/// </summary>
class Input
{
public:

	/// <summary>
	/// Updates the input states with keyboard and controller input.
	/// <para>Should be called every frame BEFORE use.</para>
	/// </summary>
	static void update(sf::RenderWindow const & t_window);

	/// <summary>
	/// Returns the current state of the input.
	/// </summary>
	/// <returns>Current state of the input</returns>
	static InputState const & getCurrentState();

	/// <summary>
	/// Returns the previous state of the input.
	/// </summary>
	/// <returns>Previous state of the input</returns>
	static InputState const& getPreviousState();

	/// <summary>
	/// Sets the pointer to a gamepad
	/// </summary>
	/// <param name="t_controllerPtr">controller pointer</param>
	static void setControllerPointer(Gamepad * t_controllerPtr);

private:

	// The current state of all input.
	static InputState m_currentState;

	// The previous state of all input.
	// Can be used with the current state to check for button presses (just pressed).
	static InputState m_previousState;

	// A pointer to a controller
	static Gamepad * m_controllerRef;

};

#endif // !INPUT_H
