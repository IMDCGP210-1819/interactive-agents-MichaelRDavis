#include "MiniPCH.h"
#include "Entity.h"
#include "Gameplay/World/World.h"

Entity::Entity()
	: m_IsRegistered(true)
{
	m_World = std::make_shared<World>();
}

Entity::~Entity()
{

}

void Entity::Initialize()
{
	if (m_IsRegistered)
	{
		
	}
}

void Entity::Update(float DeltaTime)
{

}

void Entity::Render()
{

}

void Entity::SetObjectID(int NewObjectID)
{
	m_ObjectID = NewObjectID;
}
