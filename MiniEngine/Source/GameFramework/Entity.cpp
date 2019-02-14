#include "MiniPCH.h"
#include "GameFramework/Entity.h"

Engine::Entity::Entity()
{

}

Engine::Entity::~Entity()
{

}

void Engine::Entity::SetObjectID(int NewObjectID)
{
	m_ObjectID = NewObjectID;
}
