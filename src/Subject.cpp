/// @Author Michael Rainsford Ryan

#include "Subject.h"

///////////////////////////////////////////////////////////////////
void Subject::addObserver(Observer * t_observer)
{
	m_observers.push_back(t_observer);
}

///////////////////////////////////////////////////////////////////
void Subject::removeObserver(Observer * t_observer)
{
	// Loop the observers
	for (int i = 0; i < m_observers.size(); i++)
	{
		// Check if the memory addresses are the same (to check if the observer is the same)
		if (t_observer == m_observers.at(i))
		{
			// Erase the observer if it matches
			m_observers.erase(m_observers.begin() + i);
		}
	}
}

///////////////////////////////////////////////////////////////////
void Subject::notify(Entity const* t_entity, ObserverEvent const t_event)
{
	for (Observer * observer : m_observers)
	{
		observer->onNotify(t_entity, t_event);
	}
}

///////////////////////////////////////////////////////////////////