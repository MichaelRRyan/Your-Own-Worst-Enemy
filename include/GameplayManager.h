#ifndef GAMEPLAY_MANAGER_H
#define GAMEPLAY_MANAGER_H

/// <summary>
/// @Author Michael Rainsford Ryan
/// @Date 27/05/2020
/// </summary>

#include <typeinfo>
#include <vector>
#include <memory>

#include "Observer.h"
#include "Player.h"
#include "Zombie.h"

class GameplayManager : public Observer
{
public:

	GameplayManager(std::vector<std::shared_ptr<Entity>>& t_entitiesRef);

	virtual void onNotify(Entity const * t_entity, ObserverEvent const t_event) override;

private:

	std::vector<std::shared_ptr<Entity>> & m_entitiesRef;

};

#endif // !GAMEPLAY_MANAGER_H

