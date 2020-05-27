#ifndef SUBJECT_H
#define SUBJECT_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 27/05/2020
/// </summary>

#include <vector>

#include "Observer.h"

class Subject
{
public:

	void addObserver(Observer * t_observer);

	void removeObserver(Observer * t_observer);

protected:

	void notify(Entity const * t_entity, ObserverEvent const t_event);

private:

	std::vector<Observer *> m_observers;

};

#endif // !SUBJECT_H

