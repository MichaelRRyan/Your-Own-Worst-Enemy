#include "Input.h"

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 18/04/2020
/// </summary>

InputState Input::m_currentState{ false };
InputState Input::m_previousState{ false };
Gamepad * Input::m_controllerRef{ nullptr };

///////////////////////////////////////////////////////////////////
void Input::update(sf::RenderWindow const& t_window)
{
	m_previousState = m_currentState;

	m_currentState.jump = sf::Keyboard::isKeyPressed(sf::Keyboard::W);

	m_currentState.moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	m_currentState.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	m_currentState.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
	m_currentState.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

	m_currentState.jump = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

	m_currentState.moveLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	m_currentState.moveRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	m_currentState.moveUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	m_currentState.moveDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	m_currentState.cursorPosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(t_window));

	if (m_controllerRef != nullptr)
	{
		m_controllerRef->update();

		if (m_controllerRef->getCurrentState().FaceBottom) m_currentState.jump = true;

		if (m_controllerRef->getCurrentState().DpadLeft) m_currentState.moveLeft = true;
		if (m_controllerRef->getCurrentState().DpadRight) m_currentState.moveRight = true;
		if (m_controllerRef->getCurrentState().DpadUp) m_currentState.moveUp = true;
		if (m_controllerRef->getCurrentState().DpadDown) m_currentState.moveDown = true;

		if (m_controllerRef->getCurrentState().LeftThumbStick.x > 0.0f) m_currentState.moveRight = true;
		if (m_controllerRef->getCurrentState().LeftThumbStick.x < 0.0f) m_currentState.moveLeft = true;
	}
}

///////////////////////////////////////////////////////////////////
InputState const& Input::getCurrentState()
{
	return m_currentState;
}

///////////////////////////////////////////////////////////////////
InputState const& Input::getPreviousState()
{
	return m_previousState;
}

///////////////////////////////////////////////////////////////////
void Input::setControllerPointer(Gamepad* t_controllerPtr)
{
	m_controllerRef = t_controllerPtr;
}

///////////////////////////////////////////////////////////////////