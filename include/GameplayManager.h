#ifndef GAMEPLAY_MANAGER_H
#define GAMEPLAY_MANAGER_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 27/05/2020
/// </summary>

#include <typeinfo>

#include "Observer.h"
#include "Player.h"

class GameplayManager : public Observer
{
public:

	virtual void onNotify(Entity const * t_entity, ObserverEvent const t_event) override;

};

#endif // !GAMEPLAY_MANAGER_H

