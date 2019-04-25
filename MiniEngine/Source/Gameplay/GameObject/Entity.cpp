#include "MiniPCH.h"
#include "Entity.h"
#include "Gameplay/World/World.h"

Entity::Entity()
	: m_IsRegistered(true)
{
	
}

Entity::~Entity()
{

}

void Entity::AddToWorld(std::shared_ptr<World> WorldObject)
{
	if (m_IsRegistered)
	{
		m_World = WorldObject;
		m_World->AttachEntity(this);
	}
}

void Entity::Initialize()
{

}

void Entity::Update(float DeltaTime)
{

}

void Entity::Draw(SDL_Renderer* Renderer)
{

}

void Entity::SetObjectID(int NewObjectID)
{
	m_ObjectID = NewObjectID;
}
