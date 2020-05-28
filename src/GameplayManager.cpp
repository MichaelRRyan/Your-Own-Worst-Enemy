/// @Author Michael Rainsford Ryan

#include "GameplayManager.h"

///////////////////////////////////////////////////////////////////
GameplayManager::GameplayManager(Level& t_levelRef, std::vector<std::shared_ptr<Entity>>& t_entitiesRef) :
	m_levelRef{ t_levelRef },
	m_entitiesRef{ t_entitiesRef }
{
}

///////////////////////////////////////////////////////////////////
void GameplayManager::onNotify(Entity * t_entity, ObserverEvent const t_event)
{
	switch (t_event)
	{
	case ObserverEvent::EntityDied:
		if (typeid(*t_entity).name() == typeid(Player).name())
		{
			Player * playerPtr = dynamic_cast<Player*>(t_entity);

			m_entitiesRef.push_back(std::make_shared<Zombie>(playerPtr->getPosition(), m_entitiesRef.at(0)));

			playerPtr->spawn(static_cast<sf::Vector2f>(m_levelRef.getCurrentCheckpointTile()) * 16.0f + sf::Vector2f{ 8.0f, 0.0f });
		}
		break;
	}
}

///////////////////////////////////////////////////////////////////