#ifndef OBSERVER_H
#define OBSERVER_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 27/05/2020
/// </summary>

#include "ObserverEvent.h"
#include "Entity.h"

class Observer
{
public:

	virtual ~Observer() {}

	virtual void onNotify(Entity * t_entity, ObserverEvent const t_event) = 0;

};

#endif // !OBSERVER_H

