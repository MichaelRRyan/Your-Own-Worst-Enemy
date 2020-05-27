/// @Author Michael Rainsford Ryan

#include "GameplayManager.h"

///////////////////////////////////////////////////////////////////
void GameplayManager::onNotify(Entity const* t_entity, ObserverEvent const t_event)
{
	switch (t_event)
	{
	case ObserverEvent::EntityDied:
		if (typeid(t_entity).name() == typeid(Player).name())
		{
			std::cout << "Player Died" << std::endl;
		}
		break;
	}
}

///////////////////////////////////////////////////////////////////