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

	GameplayManager(Level& t_levelRef, std::vector<std::shared_ptr<Entity>>& t_entitiesRef);

	virtual void onNotify(Entity * t_entity, ObserverEvent const t_event) override;

private:

	Level& m_levelRef;

	std::vector<std::shared_ptr<Entity>> & m_entitiesRef;

};

#endif // !GAMEPLAY_MANAGER_H

