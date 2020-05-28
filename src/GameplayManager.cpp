/// @Author Michael Rainsford Ryan

#include "GameplayManager.h"

///////////////////////////////////////////////////////////////////
GameplayManager::GameplayManager(std::vector<std::shared_ptr<Entity>>& t_entitiesRef) :
	m_entitiesRef{ t_entitiesRef }
{
}

///////////////////////////////////////////////////////////////////
void GameplayManager::onNotify(Entity const* t_entity, ObserverEvent const t_event)
{
	switch (t_event)
	{
	case ObserverEvent::EntityDied:
		if (typeid(*t_entity).name() == typeid(Player).name())
		{
			m_entitiesRef.push_back(std::make_shared<Zombie>(dynamic_cast<Player const *>(t_entity)->getPosition(), m_entitiesRef.at(0)));
		}
		break;
	}
}

///////////////////////////////////////////////////////////////////